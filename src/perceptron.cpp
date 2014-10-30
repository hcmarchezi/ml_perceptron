#include "perceptron.h"

#include <iostream>

Perceptron::Perceptron()
{
    _learningRate = 0.1;

}

Perceptron::~Perceptron()
{
}

void Perceptron::startTraining(std::vector< std::vector<double> > x,std::vector<double> desired)
{
    _weights.resize(x[0].size());
    for (size_t index=0; index < _weights.size(); index++)
    {
        _weights[index] = 0.0;
        std::cout << "_weights[" << index << "]=" << _weights[index] << std::endl;
    }

    std::cout << std::endl;

    for (size_t i=0; i < x.size(); i++)
    {
        double actual = output(x[i]);
        double error = desired[i]-actual;
        for (size_t j=0; j < x[0].size(); j++)
        {
            std::cout << "_weights[" << j << "]=" << _weights[j] << "+" << _learningRate << "*" << error << "*" << x[i][j] << std::endl;
            _weights[j] = _weights[j] + _learningRate * error * x[i][j];
            std::cout << "_weights[" << j << "]=" << _weights[j] << std::endl;
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
    return output;
}
