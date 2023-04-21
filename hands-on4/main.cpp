#include "DataSet.hpp"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(const pair<float, char> &i, const pair<float, char> &j)
{
    return i.first < j.first;
}

vector<pair<float, char>> calcDistances(vector<float> x, vector<float> y, vector<char> types, int age, int loan, int size)
{
    vector<pair<float, char>> distances;
    for (int i = 0; i < size; i++)
    {
        const float distance = sqrt(pow(x[i] - age, 2) + pow(y[i] - loan, 2));
        pair<float, char> data;
        data.second = types[i];
        data.first = distance;
        distances.insert(distances.end(), data);
    }

    std::sort(distances.begin(), distances.end(), compare);

    return distances;
}

void showType(vector<pair<float, char>> distance, int k, int age, int loan)
{
    cout << "Distancias mas cercanas a EDAD:  " << age << " PRESTAMO: " << loan << endl;
    int type1 = 0;
    int type2 = 0;

    for (int i = 0; i < k; i++)
    {
        cout << "#" << i + 1 << " Dis: " << distance[i].first << " Type: " << distance[i].second << endl;
        if (distance[i].second == 'N')
            type1++;
        else
            type2++;
    }

    if (type1 < type2)
        cout << "Es del tipo: Y" << endl;
    else
        cout << "Es del tipo: N" << endl;
}

int main()
{
    // Numero de vecinos que se tomaran en cuanta
    /**
     * IMPORTANTE:
     * elija K como un número impar cuando los datos tengan un número par de clases y un número par cuando los datos tengan un número impar de clases.
     */
    const int K = 5;
    // Listado de las distancias
    vector<pair<float, char>> distances;

    // Nuevo dato : edad
    const int NEW_AGE = 24;
    // Nuevo dato : Prestamo
    const int LOAN = 145000;

    DataSet ds;
    vector<float> x;
    vector<float> y;
    vector<char> types;

    x = ds.getX();
    y = ds.getY();
    types = ds.getTypes();

    cout << "Usando el data set de ejemplo en el pagina: " << endl
         << "\t -> https://towardsdatascience.com/a-simple-introduction-to-k-nearest-neighbors-algorithm-b3519ed98e " << endl;
    cout << "* X = Edad\n* Y = Prestamo" << endl;

    distances = calcDistances(x, y, types, NEW_AGE, LOAN, x.size());
    showType(distances, K, NEW_AGE, LOAN);

    return EXIT_SUCCESS;
}
