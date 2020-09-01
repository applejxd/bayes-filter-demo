cmake_minimum_required(VERSION 3.8.0)

include(GoogleTest)

add_library(GTest
    SHARED ${PROJECT_SOURCE_DIR}/test/gtest/gtest-all.cc
)
target_include_directories(GTest
    PUBLIC ${PROJECT_SOURCE_DIR}/test
)

add_library(GMain
    SHARED ${PROJECT_SOURCE_DIR}/test/gtest/gtest_main.cc
)
target_include_directories(GMain
    PUBLIC ${PROJECT_SOURCE_DIR}/test
)

add_executable(SolverTest solver_test.cc)
target_compile_options(SolverTest PUBLIC -O2 -Wall)
target_compile_features(SolverTest PUBLIC cxx_std_11)
target_link_libraries(SolverTest
    PUBLIC
        GTest
        GMain
)

gtest_add_tests(TARGET SolverTest)
