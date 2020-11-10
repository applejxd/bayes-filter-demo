/**
 * @file main.cc
 * Copyright 2020 @applejxd
 */ 
#include "./src/include/runner.h"
#include "./src/include/config.h"

int main(int, char**) {
  runner::Runner runner_ins;

  #if RUNNER == 0
    runner_ins.RunPrinter();
  #elif RUNNER == 1
    runner_ins.RunViewer();
  #endif

  return 0;
}
