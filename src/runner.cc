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

void Runner::RunPrinter() {
  CanonVar var(M_PI / 10., M_PI / 10., 0., 0.);
  this->solver_ins_ptr->SolveOde(var);
  vector<CanonVar> answers = this->solver_ins_ptr->GetAnswer();
  for (const auto& answer : answers) {
    std::cout << "(" << answer.theta1 << ", " << answer.theta2 << ")"
              << std::endl;
  }
}

}  // namespace runner
