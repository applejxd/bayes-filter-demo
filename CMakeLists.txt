cmake_minimum_required(VERSION 3.8.0)
project(Filtering VERSION 0.1.0)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})

add_executable(Filtering main.cc)
target_compile_options(Filtering PUBLIC -O2 -Wall)
target_compile_features(Filtering PUBLIC cxx_std_11)

add_subdirectory(src)
target_link_libraries(Filtering
    PUBLIC
        Dynamics
        ${OpenCV_LIBRARIES}
)

enable_testing()
# add_subdirectory(test)