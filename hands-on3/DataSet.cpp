#include "DataSet.hpp"

DataSet::DataSet()
{
    x = {-3, -2, -1, 0, 1, 2, 3};
    y = {7.5, 3, 0.5, 1, 3, 6, 14};
}

std::vector<float> DataSet::getX()
{
    return x;
}

std::vector<float> DataSet::getY()
{
    return y;
}
