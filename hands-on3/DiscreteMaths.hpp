#ifndef DISCRETE_MATHS
#define DISCRETE_MATHS
#include <vector>

class DiscreteMaths
{
public:
    // Attributes
    float b1;
    float b0;

    // constructor
    DiscreteMaths();

    // Metods
    float sumX(std::vector<float>);
    float sumY(std::vector<float>);
    float sumXY(std::vector<float>, std::vector<float>);
    float sumXsumY(std::vector<float>, std::vector<float>);
    float sumSqr(std::vector<float>);
    float calcB1(std::vector<float> vect1, std::vector<float> vect2, int size);
    float calcB0(std::vector<float> vect1, std::vector<float> vect2, int size, float b1);
    float calcSSr(std::vector<float> vect1, std::vector<float> vect2, int size, float b1);
};

#endif
