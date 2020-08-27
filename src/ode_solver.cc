#include <ode_solver.h>

#include <vector>

namespace odesolver{

using std::vector;

vector<double> RK4::SolveOde(const vector<double> &x){
    /**
     * @brief 
     */
    vector<vector<double>> k;
    vector<double> x_shifted;

    k[0] = this->eom_impl->HamiltonEq(x);

    for(int i = 0; i < (int)x.size(); i++){
        x_shifted[i] = x[i] + (this->dt)/2.0*k[0][i];
    }
    k[1] = this->eom_impl->HamiltonEq(x_shifted);

    for(int i = 0; i < (int)x.size(); i++){
        x_shifted[i] = x[i] + (this->dt)/2.0*k[1][i];
    }
    k[2] = this->eom_impl->HamiltonEq(x_shifted);

    for(int i = 0; i < (int)x.size(); i++){
        x_shifted[i] = x[i] + (this->dt)*k[2][i];
    }
    k[3] = this->eom_impl->HamiltonEq(x_shifted);

    vector<double> x_next;
    for (int i = 0; i < (int)x.size(); i++){
        x_next[i] = 
            x[i] + (k[0][i]+2*k[1][i]+2*k[2][i]+k[3][i])/6.0 * this->dt;
    }
    
    return x_next;
}

}	// namespace odesolver