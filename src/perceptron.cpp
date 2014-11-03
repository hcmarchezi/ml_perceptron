#include "perceptron.h"

#include <cmath>

Perceptron::Perceptron()
{
    _learningRate = 0.1;

}

Perceptron::~Perceptron()
{
}

void Perceptron::startTraining(std::vector< std::vector<double> >& x, std::vector<double>& desired)
{
    initializeVector(_weights,x[0].size());

    while(totalCost(x,desired) > 0.0)
    {
        for (size_t i=0; i < x.size(); i++)
        {
            double actual = linearOutput(x[i]);
            double error = desired[i]-actual;
            for (size_t j=0; j < x[0].size(); j++)
            {                
                _weights[j] = _weights[j] + _learningRate * error * x[i][j];
                std::cout << "_weights[" << j << "]=" << _weights[j] << " ";
            }      
            std::cout << "error=|" << linearOutput(x[i]) << "-" << desired[i] << "|=" << std::abs( linearOutput(x[i]) - desired[i] );
            std::cout << std::endl;
        }
        std::cout << "------------------------------------" << std::endl;
    }
}

double Perceptron::output(std::vector<double>& input)
{
    double result = linearOutput(input);
    result = binarization(result, 0.5);
    return result;
}

void Perceptron::initializeVector(std::vector<double>& w, size_t size)
{
    w.resize(size);
    for (size_t index=0; index < w.size(); index++)
    {
        w[index] = 0.0;
    }
}

double Perceptron::linearOutput(std::vector<double>& input)
{
    double output = 0.0;
    for(size_t index=0; index < _weights.size(); index++)
    {
        output += _weights[index]*input[index];
    }
    return output;
}

double Perceptron::binarization(double input, double pivot)
{
    double output = 0.0;
    if (input > pivot)
    {
        output = 1.0;
    }
    return output;
}

double Perceptron::totalCost(std::vector< std::vector<double> >& x, std::vector<double>& desired)
{
    double cost = 0.0;
    for (size_t i=0; i < x.size(); i++)
    {
        double diff = desired[i] - output(x[i]);
        cost += std::abs(diff);
    }
    cost = cost/(double)x.size();
    std::cout << "cost=" << cost << std::endl;
    return cost;
}
