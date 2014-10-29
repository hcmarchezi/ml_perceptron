#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<vector>

class Perceptron
{
  public:
    Perceptron();
    virtual ~Perceptron();
    void startTraining(std::vector< std::vector<double> > x,double bias,std::vector<double> desired);
    double output(std::vector<double> input);

  protected:
    std::vector<double> _weights;
    double _bias;
    double _learningRate;
};

#endif // PERCEPTRON_H