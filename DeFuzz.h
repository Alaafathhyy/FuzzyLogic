//
// Created by Alaa on ٢٩/٠٥/٢٠٢١.
//
#include <bits/stdc++.h>
#include "point.h"

using namespace std;
#ifndef GA3_DEFUZZ_H
#define GA3_DEFUZZ_H
extern vector<point> Output;
extern vector<pair<string, long double>> inferOutput;


class DeFuzz {



    static long double Centroid(vector<pair<long double, long double>> v);

    void InitAllCentorids();


public:
    map<string, long double> centroidMap;
    DeFuzz();
    static vector<pair<long double, long double>> GetCoordinates(const vector<long double> &cor, bool f);//1 for triangle , 0 for tripozidal

     long double CalcOuptput();
};


#endif //GA3_DEFUZZ_H
