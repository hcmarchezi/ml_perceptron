#include <iostream>
#include <vector>

#include "perceptron.h"

int main()
{
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << " Perceptron training for AND operation " << std::endl;

    // Training for AND operation
    std::vector< std::vector<double> > x;
    x.resize(4);
    x[0].resize(3);
    x[1].resize(3);
    x[2].resize(3);
    x[3].resize(3);

    std::vector<double> desired;
    desired.resize(4);

    x[0][0]= 1.0; x[0][1]=-1.0; x[0][2]=-1.0; desired[0]=-1.0;
    x[1][0]= 1.0; x[1][1]= 1.0; x[1][2]=-1.0; desired[1]=-1.0;
    x[2][0]= 1.0; x[2][1]=-1.0; x[2][2]= 1.0; desired[2]=-1.0;
    x[3][0]= 1.0; x[3][1]= 1.0; x[3][2]= 1.0; desired[3]= 1.0;

    for(size_t i=0; i< x.size(); i++)
    {
        for(size_t j=0; j < x[0].size();j++)
        {
            std::cout << "x[" << i << "," << j << "]=" << x[i][j] << " ";
        }
        std::cout << "y[" << i << "]=" << desired[i] << std::endl;
    }

    Perceptron perceptron;
    perceptron.startTraining(x,desired);

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << " Results: " << std::endl;

    for (size_t i=0; i < x.size(); i++)
    {
        std::cout << i << " Input: ";
        for (size_t j=0; j < x[0].size(); j++)
        {
            std::cout << x[i][j] << ", ";
        }
        double output = perceptron.output(x[i]);
        std::cout << ": " << output << std::endl;
    }

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    return 0;
}

