#include <eom.h>

#include <math.h>
#include <vector>
#include <iostream>

namespace eom
{

using std::vector;
using std::cout;

DoublePendulum::DoublePendulum (const double (&m)[2], const double (&l)[2]){
    /**
     * @brief set masses and lengths
     */
    // TODO: Should it be allowed the exception for single pendulum?
    try{
        if(m[0]==0 || m[1]==0 || l[0]==0 || l[1]==0){
            throw "Exception: Null parameter(s) exist.";
        }
    }catch(char *null_param_err){
        cout << null_param_err;
    }
    
    *(this->m) = *m;
    *(this->l) = *l;
}

vector<double> DoublePendulum::HamiltonEq(const vector<double> &x) {
    /**
     * @brief calculate velocity 'dqdt'
     * @param offdiag: off-diagonal part of coefficient matrix
     * @param det: determinant of coefficient matrix
     * @return velocity 'dqdt'
     */
    try{
        if(x.size() != 4){
            throw "Exception: The phase sp. dim. doesn't match.";
        }
    }catch(char *size_err){
        cout << size_err;
    }

    vector<double> dxdt(4);
    
    // for dqdt
    double offdiag = m[1]*l[0]*l[1]*cos(x[0]-x[1]);
    double det = (m[0]+m[1])*m[1]*pow(l[0]*l[1], 2.0)-pow(offdiag, 2.0);

    dxdt[0] = det*(m[1]*l[1]*l[1]*x[2]-offdiag*x[3]);
    dxdt[1] = det*(-offdiag*x[0]+(m[0]*m[1])*l[0]*l[0]*x[1]);

    // for dpdt
    double c = m[1]*l[0]*l[1]*sin(x[0]-x[1])*dxdt[0]*dxdt[1];

    dxdt[2] = -c - (m[0]+m[1])*g*l[0]*sin(x[0]);
    dxdt[3] = c - m[1]*g*l[1]*cos(x[1]);

    return dxdt;
}

} // namespace eom