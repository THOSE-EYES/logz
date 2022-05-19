# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
# 
#  http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

# Setting CMake
cmake_minimum_required(VERSION 3.15)
project(logz)

# If not specified, then the build type should be "debug"
IF( NOT CMAKE_BUILD_TYPE )
   SET( CMAKE_BUILD_TYPE Debug ... FORCE )
ENDIF()

# Setting the compiler for Linux
if (UNIX)
	set(CMAKE_CXX_STANDARD_LIBRARIES "")
endif (UNIX)

# Add debug flags for the debug build
if (CMAKE_BUILD_TYPE MATCHES Debug)
	set(CXXFLAGS "${CXXFLAGS} -Wall -g")
endif()

# Looking for source files
include_directories("include")

# Find source files
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp" "src/*/*/*/*.cpp")

# Command to compile the whole project
add_executable(${PROJECT_NAME} ${SOURCES})