#include <ode_solver.h>

#include <vector>

namespace odesolver{

using std::vector;

OdeSolverBase::OdeSolverBase(eom::EomBase* eom, double dt)
    : eom_ins(eom), dt(dt){
}

eom::EomBase* OdeSolverBase::GetEom(void){
    return this->eom_ins;
}

double OdeSolverBase::GetDt(void){
    return this->dt;
}

vector<double> RK4::SolveOde(const vector<double> &x){
    vector<vector<double>> k;
    vector<double> x_shifted;

    k[0] = this->GetEom()->HamiltonEq(x);

    for(int i = 0; i < (int)x.size(); i++){
        x_shifted[i] = x[i] + (this->GetDt())/2.0*k[0][i];
    }
    k[1] = this->GetEom()->HamiltonEq(x_shifted);

    for(int i = 0; i < (int)x.size(); i++){
        x_shifted[i] = x[i] + (this->GetDt())/2.0*k[1][i];
    }
    k[2] = this->GetEom()->HamiltonEq(x_shifted);

    for(int i = 0; i < (int)x.size(); i++){
        x_shifted[i] = x[i] + (this->GetDt())*k[2][i];
    }
    k[3] = this->GetEom()->HamiltonEq(x_shifted);

    vector<double> x_next;
    for(int i = 0; i < (int)x.size(); i++){
        x_next[i] = 
            x[i] + (k[0][i]+2*k[1][i]+2*k[2][i]+k[3][i])/6.0 * this->GetDt();
    }
    
    return x_next;
}

}	// namespace odesolver