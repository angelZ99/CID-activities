#include "DataSet.hpp"
#include "DiscreteMaths.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
    cout << "Usando el data set de ejemplo en el pagina: " << endl
         << "\t -> https://www.varsitytutors.com/hotmath/hotmath_help/topics/quadratic-regression " << endl;

    DataSet ds;
    DiscreteMaths dm;
    vector<float> x;
    vector<float> y;

    x = ds.getX();
    y = ds.getY();

    const float b1 = dm.calcB1(x, y, x.size());
    const float b0 = dm.calcB0(x, y, x.size(), b1);
    const float SSr = dm.calcSSr(x, y, x.size(), b1);

    cout << "\nSum de X:\t\t" << dm.sumX(x) << endl;
    cout << "Sum de Y:\t\t" << dm.sumY(y) << endl;
    cout << "Sum de X^2:\t\t" << dm.sumSqr(x) << endl;
    cout << "Sum de Y^2:\t\t" << dm.sumSqr(y) << endl;
    cout << "Sum de X * Y:\t\t" << dm.sumXY(x, y) << endl;

    cout << "Ecuacion de Regresión cuadratica:\n\t y = B0 + B1 x + B2 x^2" << endl;
    cout << "\t y = " << b0 << " + " << b1 << "X" << endl;
    cout << "Suma de Cuadrados de regresion: " << SSr << endl;

    return EXIT_SUCCESS;
}
