// Copyright 2020 @applejxd
#include "./include/runner.h"

#include <cmath>
#include <iostream>
#include <vector>
#include "./include/types.h"

namespace runner {

using std::vector;
using types::CanonVar;

Runner::Runner(void)
    : eom_ins_ptr(new eom::DoublePendulum(this->m, this->l)),
      solver_ins_ptr(
          new odesolver::RK4(this->eom_ins_ptr, this->dt, this->t_end)) {}

/** Print results */
void Runner::RunPrinter() {
  // Set initial conditions
  CanonVar var(M_PI, M_PI, 0., 0.);
  this->solver_ins_ptr->SolveOde(var);
  // Solve ODE
  vector<CanonVar> answers = this->solver_ins_ptr->GetAnswer();
  // Print the solution
  for (const auto& answer : answers) {
    std::cout << "(" << answer.theta1 << ", " << answer.theta2 << ")"
              << std::endl;
  }
}

void Runner::RunViewer() {
  // Set initial conditions
  CanonVar var(M_PI, M_PI, 0., 0.01);
  this->solver_ins_ptr->SolveOde(var);
  // Solve ODE
  vector<CanonVar> answers = this->solver_ins_ptr->GetAnswer();

  char code = static_cast<char>(-1);
  for (const auto& answer : answers) {
    array<double, 2> length{1., 1.};
    this->viewer_ins.DrawPendulum(answer, length);
    // milisecond
    code = static_cast<char>(cv::waitKey(10));
  }
}

}  // namespace runner
