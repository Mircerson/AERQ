#!/usr/bin/env python

"""
Copyright (c) 2021 STMicroelectronics. All rights reserved.

SPDX-License-Identifier: Apache-2.0

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

from argparse import ArgumentParser
import sys
import os
import json
import subprocess
import re

import aci_pinvalidate

custom_targets_file = open("custom_targets.json", "r")
custom_targets_info = json.load(custom_targets_file)
custom_targets_file.close()

print("")
BuildType = "PATCH"
Arguments = ArgumentParser(description="Quick script for build check")
Arguments.add_argument("--toolchain", "-tc", help="ARM | GCC_ARM | IAR . Default is GCC_ARM")
Arguments.add_argument("--targets", "-t", help="Specific target. Default is patched targets compared to master branch")
Arguments.add_argument("--all", "-a", action="store_true", help="Build all targets. Default is patched targets compared to master branch")
Arguments.add_argument("--baremetal", "-b", action="store_true", help="Build with baremetal profile")
Arguments.add_argument("--cli2", "-c", action="store_true", help="Build with cmake (CLI2). Default is CLI1")
Arguments.add_argument("--pin", "-p", action="store_true", help="Check pin name standart")
Arguments.add_argument("--exit", "-e", action="store_true", help="Stop after 1st build failure")
Arguments.add_argument("--paths", help="don't use it")
Arguments.add_argument("--verbose", action="count", default=3, help="don't use it")
args = Arguments.parse_args()

if args.toolchain:
    requested_toolchain = args.toolchain
else:
    requested_toolchain = "GCC_ARM"

if args.cli2:
    mbed_tool = "mbedtools"
else:
    mbed_tool = "mbed"

if args.baremetal:
    mbed_lib = "mbed-baremetal"
else:
    mbed_lib = "mbed-os"

# TargetList is the copy of custom_targets.json
#   then skipped targets will be repoved from custom_targets_info
TargetList = [*custom_targets_info]

if args.targets:
    BuildType = "TARGET"
    print ("Explicit target is requested: %s" % args.targets)
    if args.targets not in TargetList:
        print("\tERROR => not part of custom_targets.json")
        sys.exit(1)
    for EachTarget in TargetList:
        if EachTarget == args.targets:
            pass
        else:
            print ("\t%s is skipped" % EachTarget)
            del custom_targets_info[EachTarget]

if args.all:
    BuildType = "FULL"

if BuildType == "PATCH":
    PatchedTargets = []
    PinNamesList = []
    print("git", "diff", "--name-only", "origin/master")
    try:
        CONSOLE = subprocess.check_output(["git", "diff", "--name-only", "origin/master"], stderr=subprocess.STDOUT).decode('ascii')
        CONSOLE = CONSOLE.splitlines()

        for EachPatchedFile in CONSOLE:
            print("patched file: %s" % EachPatchedFile)
            if args.pin:
                if "PinNames.h" in EachPatchedFile:
                    PinNamesList.append(EachPatchedFile)
            else:
                TARGET_match = re.match(r"TARGET_STM32.*/TARGET_(.*)/", EachPatchedFile)
                if TARGET_match:
                    if TARGET_match.group(1) not in PatchedTargets:
                        TargetToBuild = TARGET_match.group(1)
                        PatchedTargets.append(TargetToBuild)
                        if TargetToBuild not in TargetList:
                            print("ERROR => %s not part of custom_targets.json" % TargetToBuild)
                            sys.exit(1)
                        print("      => %s" % TargetToBuild)

    except:
        pass

    for EachTarget in TargetList:
        if EachTarget in PatchedTargets:
            pass
        else:
            print ("\t%s is skipped" % EachTarget)
            del custom_targets_info[EachTarget]


## MAIN APPLICATION

application_file = open("main.cpp", 'w')
application_code =  ("""// generated file (automatic_build.py)
#include "mbed.h"
#define BLINKING_RATE     500ms
int main()
{
    DigitalOut led((PinName)0);
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
""" % ())
application_file.write(application_code)
application_file.close()


## CONFIGURATION

with open("mbed_app_template.json", "r") as sources:
    lines = sources.readlines()
with open("mbed_app.json", "w") as sources:
    sources.write(lines[0])
    if args.baremetal:
        sources.write('    "requires": ["bare-metal", "sx1276-lora-driver", "stm32wl-lora-driver"],\n')
    for line in lines[1:]:
        sources.write(line)


configuration_file = open(".mbedignore", 'w')
configuration_code = ("""cmake_build/*
""" % ())
configuration_file.write(configuration_code)
configuration_file.close()


if args.cli2:
    configuration_file = open("mbed-os.lib", 'w')
    configuration_file.close()

    configuration_file = open("CMakeLists.txt", 'w')
    configuration_code = ("""# generated file (automatic_build.py)

cmake_minimum_required(VERSION 3.19.0 FATAL_ERROR)

set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")
set(MBED_CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "")
set(APP_TARGET ci-application)

include(${MBED_PATH}/tools/cmake/app.cmake)

project(${APP_TARGET})

add_subdirectory(TARGET_STM32F0)
add_subdirectory(TARGET_STM32F1)
add_subdirectory(TARGET_STM32F2)
add_subdirectory(TARGET_STM32F3)
add_subdirectory(TARGET_STM32F4)
add_subdirectory(TARGET_STM32F7)
add_subdirectory(TARGET_STM32G0)
add_subdirectory(TARGET_STM32G4)
add_subdirectory(TARGET_STM32H7)
add_subdirectory(TARGET_STM32L0)
add_subdirectory(TARGET_STM32L1)
add_subdirectory(TARGET_STM32L4)
add_subdirectory(TARGET_STM32L5)
add_subdirectory(TARGET_STM32U5)
add_subdirectory(TARGET_STM32WB)
add_subdirectory(TARGET_STM32WL)

add_subdirectory(${MBED_PATH})

add_executable(${APP_TARGET})

mbed_configure_app_target(${APP_TARGET})

target_sources(${APP_TARGET}
    PRIVATE
        main.cpp
)

target_link_libraries(${APP_TARGET}
    PRIVATE
        %s
)

mbed_set_post_build(${APP_TARGET})
""" % (mbed_lib))
    configuration_file.write(configuration_code)
    configuration_file.close()


BuildFailed = []
BuildOK = []

if args.pin:
    ## START PIN NAME VALIDATION

    if BuildType == "PATCH":
        for EachPinName in PinNamesList:
            cmdline = "python aci_pinvalidate.py -p %s -vvv" % EachPinName
            args.paths = EachPinName
            try:
                result = aci_pinvalidate.validate_pin_names(args)
                BuildOK.append(cmdline)
            except:
                BuildFailed.append(cmdline)
                if args.exit:
                    print(cmdline)
                    sys.exit(2)

    elif BuildType == "FULL":
        cmdline = "python aci_pinvalidate.py -a -vvv"
        try:
            result = aci_pinvalidate.validate_pin_names(args)
            BuildOK.append(cmdline)
        except:
            BuildFailed.append(cmdline)
            if args.exit:
                print(cmdline)
                sys.exit(2)

    else:
        cmdline = "python aci_pinvalidate.py -t %s -vvv" % args.targets
        try:
            result = aci_pinvalidate.validate_pin_names(args)
            BuildOK.append(cmdline)
        except:
            BuildFailed.append(cmdline)
            if args.exit:
                print(cmdline)
                sys.exit(2)

else:
    ## START BUILD

    for EachTarget in custom_targets_info:
        cmdline = "%s compile -m %s -t %s" % (mbed_tool, EachTarget, requested_toolchain)
        print ("\n***************************************")
        print ("Executing: " + cmdline)
        sys.stdout.flush()

        if os.system(cmdline) != 0:
            BuildFailed.append(cmdline)
            if args.exit:
                print(cmdline)
                sys.exit(2)
        else:
            BuildOK.append(cmdline)


if BuildOK != []:
    print()
    print("Succeeded build command:")
    for EachBuild in BuildOK:
        print(EachBuild)
    print()

if BuildFailed != []:
    print()
    print("Failed build command:")
    for EachBuild in BuildFailed:
        print(EachBuild)
    print()
    sys.exit(1)
