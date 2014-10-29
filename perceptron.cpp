#include "perceptron.h"

#include <iostream>

Perceptron::Perceptron()
{
    _learningRate = 0.1;
    for (size_t index=0; index < _weights.size(); index++)
    {
        _weights[index] = 0.0;
    }
}

Perceptron::~Perceptron()
{

}

void Perceptron::startTraining(std::vector< std::vector<double> > x,double bias, std::vector<double> desired)
{
    _bias = bias;
    for (size_t j=0; j < x.size(); j++)
    {
        double actual = output(x[j]);
        for (size_t i=0; i < _weights.size(); i++)
        {
            _weights[i] = _weights[i] + _learningRate * (desired[j]-actual) * x[i][j];
        }
    }
}

double Perceptron::output(std::vector<double> input)
{
    double output = 0.0;
    for(size_t index=0; index < _weights.size(); index++)
    {
        output += _weights[index]*input[index];
    }
    output += _bias;
    return output;
}
