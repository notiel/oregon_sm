cmake_minimum_required (VERSION 3.12)
project (OregonFallout)

# ================ Begin of testing dependencies set up ================
# (based on instructions from
# https://github.com/google/googletest/blob/master/googletest/README.md)
#
# Download and unpack googletest at configure time
configure_file(CMakeLists.deps.txt googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
# ================= End of testing dependencies set up =================

add_library(OregonFalloutLib
  eventHandlers.cpp
  eventHandlers.h
  oregonPill.cpp
  oregonPlayer.cpp
  qhsm.c
  service.c
)

add_executable(OregonFallout main.cpp)
target_link_libraries(OregonFallout OregonFalloutLib)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(OregonFalloutTest
  oregonPlayerTest.cpp)
target_link_libraries(OregonFalloutTest OregonFalloutLib gtest_main)
