# 'Google_test' is the subproject name
cmake_minimum_required(VERSION 3.19)
project(String_Tools_Google_Tests)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 'lib' is the folder with Google Test sources
# add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(
        Google_Tests_String_Tools
        ../StringTools.cpp
        testStringTools.cpp
)
# target_link_libraries(Google_Tests_run gtest gtest_main pthread)
target_link_libraries(Google_Tests_String_Tools gtest gtest_main pthread)

# target_link_libraries(testFifo ${GTEST_LIBRARIES} pthread)
