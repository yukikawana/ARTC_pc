# artc_pc CMake config file
#
# This file sets the following variables:
# artc_pc_FOUND - Always TRUE.
# artc_pc_INCLUDE_DIRS - Directories containing the artc_pc include files.
# artc_pc_IDL_DIRS - Directories containing the artc_pc IDL files.
# artc_pc_LIBRARIES - Libraries needed to use artc_pc.
# artc_pc_DEFINITIONS - Compiler flags for artc_pc.
# artc_pc_VERSION - The version of artc_pc found.
# artc_pc_VERSION_MAJOR - The major version of artc_pc found.
# artc_pc_VERSION_MINOR - The minor version of artc_pc found.
# artc_pc_VERSION_REVISION - The revision version of artc_pc found.
# artc_pc_VERSION_CANDIDATE - The candidate version of artc_pc found.

message(STATUS "Found artc_pc-1.0.0")
set(artc_pc_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(artc_pc_INCLUDE_DIRS
#    "/usr/local/include/artc_pc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(artc_pc_IDL_DIRS
#    "/usr/local/include/artc_pc-1/idl")
set(artc_pc_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(artc_pc_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(artc_pc_LIBRARIES
        "/usr/local/components/lib/libartc_pc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(artc_pc_LIBRARIES
        "/usr/local/components/lib/libartc_pc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(artc_pc_DEFINITIONS ${<dependency>_DEFINITIONS})

set(artc_pc_VERSION 1.0.0)
set(artc_pc_VERSION_MAJOR 1)
set(artc_pc_VERSION_MINOR 0)
set(artc_pc_VERSION_REVISION 0)
set(artc_pc_VERSION_CANDIDATE )

