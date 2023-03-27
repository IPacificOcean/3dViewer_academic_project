cmake_minimum_required(VERSION 3.21)
project(3DViewer_v2_0)

set(CMAKE_CXX_STANDARD 17)

# 'Google_test' is the subproject name

include(FetchContent)
FetchContent_Declare(
        googletest
        Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(HEADER_FILES

        )

set(SOURCE_FILES

        )

#add_library(viewer_2_0 STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(viewer_tests
        src/tests/tests.cc)

target_link_libraries(viewer_tests
#        viewer_2_0
        gtest
        gtest_main
        )

add_test(test_all viewer_tests)