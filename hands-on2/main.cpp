#include "DataSet.hpp"
#include "DiscreteMaths.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
    cout << "Usando el data set de ejemplo en el pagina: " << endl
         << "\t -> https://www.displayr.com/what-is-linear-regression/ " << endl;
    cout << "* X = ventas\n* Y = publicidad" << endl;

    DataSet ds;
    DiscreteMaths dm;
    vector<float> x;
    vector<float> y;

    x = ds.getX();
    y = ds.getY();

    const float b1 = dm.calcB1(x, y, x.size());
    const float b0 = dm.calcB0(x, y, x.size(), b1);

    cout << "\nSum de X:\t\t" << dm.sumX(x) << endl;
    cout << "Sum de Y:\t\t" << dm.sumY(y) << endl;
    cout << "Sum de X * Y:\t\t" << dm.sumXY(x, y) << endl;
    cout << "Sum de X * Sum de Y:\t" << dm.sumXsumY(x, y) << endl;
    cout << "Sum de X^2:\t\t" << dm.sumSqr(x) << endl;
    cout << "Sum de X * Sum de X:\t" << dm.sumX(x) * dm.sumX(x) << endl;

    cout << "Ecuacion de Regresión:\n\t y = B0 + B1x" << endl;
    cout << "\t y = " << b0 << " + " << b1 << "X" << endl;

    return EXIT_SUCCESS;
}
