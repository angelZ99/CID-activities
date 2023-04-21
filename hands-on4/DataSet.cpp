#include "DataSet.hpp"

DataSet::DataSet()
{
    // Edad
    x = {25, 35, 45, 20, 35, 52, 23, 40, 60, 48, 33, 48};
    // Prestamo
    y = {
        40000,
        60000,
        80000,
        20000,
        120000,
        18000,
        95000,
        62000,
        1000000,
        2200000,
        150000,
        142000,
    };
    // Tipo de clase del valor
    types = {
        'N',
        'N',
        'N',
        'N',
        'N',
        'N',
        'Y',
        'Y',
        'Y',
        'Y',
        'Y',
        'Y',
    };
}

std::vector<float> DataSet::getX()
{
    return x;
}

std::vector<float> DataSet::getY()
{
    return y;
}

std::vector<char> DataSet::getTypes()
{
    return types;
}
