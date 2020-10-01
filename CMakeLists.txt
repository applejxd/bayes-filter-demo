cmake_minimum_required(VERSION 3.8.0)
project(Filtering)

add_executable(Filtering main.cc)
target_compile_options(Filtering PUBLIC -O2 -Wall)
target_compile_features(Filtering PUBLIC cxx_std_11)

find_package(OpenCV REQUIRED)
target_include_directories(Filtering PUBLIC ${OpenCV_INCLUDE_DIRS})

add_subdirectory(src)
target_link_libraries(Filtering
    PUBLIC
        Dynamics
        ${OpenCV_LIBS}
)

enable_testing()
# add_subdirectory(test)