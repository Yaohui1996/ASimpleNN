#include "../include/ActivationFunction.h"
#include <../include/eigen-3.3.8/Eigen/Dense>

Eigen::VectorXd sigmoid(const Eigen::VectorXd &a) 
{
    Eigen::VectorXd::Index N = a.size();
    Eigen::VectorXd z = Eigen::VectorXd::Zero(N);
    for (Eigen::VectorXd::Index i = 0; i != N; ++i)
    {
        z[i] = 1 / (1 + exp(-a[i]));
    }
    return z;
}

Eigen::VectorXd diffSigmoid(const Eigen::VectorXd &z) 
{
    Eigen::VectorXd::Index N = z.size();
    Eigen::VectorXd ret = Eigen::VectorXd::Zero(N);
    for (Eigen::VectorXd::Index i = 0; i != N; ++i)
    {
        ret[i] = (1 / (1 + exp(-z[i]))) * (1 - (1 / (1 + exp(-z[i]))));
    }
    return ret;
}
