#include "DiscreteMaths.hpp"

DiscreteMaths::DiscreteMaths() {}

float DiscreteMaths::sumX(std::vector<float> vect)
{
    float totalX = 0;

    for (int i = 0; i < vect.size(); i++)
        totalX = totalX + vect[i];

    return totalX;
}

float DiscreteMaths::sumY(std::vector<float> vect)
{
    float totalY = 0;

    for (int i = 0; i < vect.size(); i++)
        totalY = totalY + vect[i];

    return totalY;
}

float DiscreteMaths::sumXY(std::vector<float> vect1, std::vector<float> vect2)
{
    float totalXY = 0;

    for (int i = 0; i < vect1.size(); i++)
        totalXY = totalXY + (vect1[i] * vect2[i]);

    return totalXY;
}

float DiscreteMaths::sumXsumY(std::vector<float> vect1, std::vector<float> vect2)
{
    return (sumX(vect1) * sumY(vect2));
}

float DiscreteMaths::sumSqr(std::vector<float> vect)
{
    float totalX = 0;

    for (int i = 0; i < vect.size(); i++)
        totalX = totalX + vect[i] * vect[i];

    return totalX;
}

float DiscreteMaths::calcB1(std::vector<float> vect1, std::vector<float> vect2, int size)
{
    const float nSumXY = size * sumXY(vect1, vect2);
    const float nSumXY_SumXsumY = nSumXY - sumXsumY(vect1, vect2);
    const float nSumSqr_SumXsumY = (size * sumSqr(vect1)) - (sumX(vect1) * sumX(vect1));
    const float b1 = nSumXY_SumXsumY / nSumSqr_SumXsumY;
    return b1;
}

float DiscreteMaths::calcB0(std::vector<float> vect1, std::vector<float> vect2, int size, float b0)
{
    const float _x = sumX(vect1) / size;
    const float _y = sumY(vect2) / size;
    const float b0 = _y - _x * b1;
    return b0;
}