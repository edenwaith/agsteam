#!/bin/bash

# File: build_agsteam.sh
# Description: Build script to build the libagsteam-unified.dylib as a Universal Binary.  Replacement for this
# project's Makefile.  
# Author: Chad Armstrong (chad@edenwaith.com)
# Date: 14-17 September 2024

# Define some paths...
PATH_SRC=.
PATH_AGS2CLIENT=$PATH_SRC/ags2client
# Path to the Steamworks SDK folder.  This build pointed to Steamworks build 159
PATH_STEAMWORKS=$PATH_SRC/../steamworks/sdk
PATH_STEAMWORKS_INC=$PATH_STEAMWORKS/public
PATH_STEAMWORKS_LIB=$PATH_STEAMWORKS/redistributable_bin
PATH_BUILD=$PATH_SRC/Solutions/build
SRCS="ags2client/IAGS2Client.cpp ags2client/IClientAchievements.cpp ags2client/IClientLeaderboards.cpp  ags2client/IClientStats.cpp ags2client/main.cpp AGS2Client.cpp AGSteamPlugin.cpp SteamAchievements.cpp SteamLeaderboards.cpp SteamStats.cpp"

# .o object files for ags2client end up in a separate directory
# https://linuxsimply.com/bash-scripting-tutorial/string/manipulation/string-replace/
OBJS="${SRCS//.cpp/.o}"
CXXFLAGS="-g -Wall -std=c++11 -O2 -fPIC -I$PATH_STEAMWORKS_INC"
CXX=g++ # g++ is needed to compile this project, clang throws errors

PATH_OSX_BUILD="$PATH_BUILD/osx" # platform_build_path
PATH_OSX_OBJ="$PATH_OSX_BUILD/obj" # platform_obj_path

# Get object file path names (e.g., ./Solutions/build/osx/obj/ags2client/IAGS2Client.o) for all object files
OSX_OBJ_FILE_PATHS="" # ${OBJS//PATH_OSX_OBJ/ /}" # obj_file_paths

# This may not be the most elegant way to do this, but it works to construct the list where each 
# of the object files is stored
for obj in ${OBJS}; do
	OSX_OBJ_FILE_PATHS+="$PATH_OSX_OBJ/$obj "
done

# OS X
OSX_CXX_FLAGS="-DMAC_VERSION"
OSX_STEAMWORKS_DIR=osx
OSX_LIB_FLAGS="-dynamiclib -o $PATH_OSX_BUILD/libagsteam-unified.dylib"

# Create a directory at ./Solutions/build/osx/obj/ags2client
mkdir -p "$PATH_OSX_OBJ/ags2client"

# Create an array of the source files, based from the SRCS string
SRCS_ARRAY=($SRCS)

# Generate the object (.o) files
# This works in bash, but not zsh
for filename in $SRCS; do
	# Swap the .cpp for a .o file extension
	OBJ_FILENAME="${filename//.cpp/.o}"
	# Example: g++ -g -Wall -std=c++11 -O2 -fPIC -I./../steamworks/sdk/public -DAGS2CLIENT_UNIFIED_CLIENT_NAME -DMAC_VERSION -c SteamStats.cpp -o ./Solutions/build/osx/obj/SteamStats.o
	$CXX -arch x86_64 -arch arm64 $CXXFLAGS -DAGS2CLIENT_UNIFIED_CLIENT_NAME $OSX_CXX_FLAGS -c $filename -o "$PATH_OSX_OBJ/$OBJ_FILENAME"
done

# Create the unified build, link up the object files created in the previous step
# Example: # g++  -v -arch x86_64 -arch arm64 -L./../steamworks/sdk/redistributable_bin/osx -lsteam_api -dynamiclib -o ./Solutions/build/osx/libagsteam.dylib ./Solutions/build/osx/obj/ags2client/IAGS2Client.o ./Solutions/build/osx/obj/ags2client/IClientAchievements.o ./Solutions/build/osx/obj/ags2client/IClientLeaderboards.o ./Solutions/build/osx/obj/ags2client/IClientStats.o ./Solutions/build/osx/obj/ags2client/main.o ./Solutions/build/osx/obj/AGS2Client.o ./Solutions/build/osx/obj/AGSteamPlugin.o ./Solutions/build/osx/obj/SteamAchievements.o ./Solutions/build/osx/obj/SteamLeaderboards.o ./Solutions/build/osx/obj/SteamStats.o 
$CXX -v -arch x86_64 -arch arm64 -L$PATH_STEAMWORKS_LIB/$OSX_STEAMWORKS_DIR -lsteam_api $OSX_LIB_FLAGS $OSX_OBJ_FILE_PATHS
