#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<vector>
#include <iostream>

class Perceptron
{
  public:
    Perceptron();
    virtual ~Perceptron();
    void startTraining(std::vector< std::vector<double> >& x, std::vector<double>& desired);
    double output(std::vector<double>& input);
    double linearOutput(std::vector<double>& input);

  protected:
    std::vector<double> _weights;
    double _learningRate;

    void initializeVector(std::vector<double>& w, size_t size);

    double binarization(double input,double pivot);
    double totalCost(std::vector< std::vector<double> >& x, std::vector<double>& desired);

};

#endif // PERCEPTRON_H
