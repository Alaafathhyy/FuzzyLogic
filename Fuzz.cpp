//
// Created by Alaa on ٣١/٠٥/٢٠٢١.
//
#include <bits/stdc++.h>

#include "Fuzz.h"
#include "DeFuzz.h"

extern map<string, long double> result;

void Fuzz::membership(long double varNum, point &shape) {
    if (!check(varNum, shape)) return;
    vector<pair<long double, long double>> vect = DeFuzz::GetCoordinates(shape.cord, shape.n == 4);

    for (int indx = 0; indx < shape.n; ++indx) {
        if (varNum < shape.cord[indx] && indx - 1 >= 0) {
            long double x_1 = vect[indx].first, y_1 = vect[indx].second,
                    x_2 = vect[indx - 1].first, y_2 = vect[indx - 1].second;
            long double m = (y_2 - y_1) / (x_2 - x_1);
            long double c = y_2 - (m * x_2);
            long double y = (m * varNum) + c;

            result[shape.name] = y;
        }
    }
}

bool Fuzz::check(long double varNum, point &a) {
    long double min = *min_element(a.cord.begin(), a.cord.end());
    long double max = *max_element(a.cord.begin(), a.cord.end());
    return (min <= varNum && varNum <= max);
}
