cmake_minimum_required(VERSION 3.8.0)

add_library(Dynamics
    SHARED
        eom.cc
        ode_solver.cc
        # viewer.cc
        runner.cc
)