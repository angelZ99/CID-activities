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
    const float SSxx = sumSqr(vect1) - (1 / size * (sumX(vect1) * sumX(vect1)));
    const float SSyy = sumSqr(vect2) - (1 / size * (sumX(vect2) * sumX(vect2)));
    const float SSxy = sumXY(vect1, vect2) - (1 / size) * (sumX(vect1)) * (sumY(vect2));

    const float b1 = SSxx / SSxy;
    return b1;
}

float DiscreteMaths::calcB0(std::vector<float> vect1, std::vector<float> vect2, int size, float b1)
{
    const float _x = sumX(vect1) / size;
    const float _y = sumY(vect2) / size;
    const float b0 = _y - b1 * _x;
    return b0;
}

float DiscreteMaths::calcSSr(std::vector<float> vect1, std::vector<float> vect2, int size, float b1)
{
    const float SSxy = sumXY(vect1, vect2) - (1 / size) * (sumX(vect1)) * (sumY(vect2));

    const float SSr = b1 * SSxy;
    return SSr;
}