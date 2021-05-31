//
// Created by Alaa on ٢٩/٠٥/٢٠٢١.
//

#include "DeFuzz.h"
#include "point.h"


void DeFuzz::InitAllCentorids() {
    for (auto &shape:Output) {
        // calculate for each shape the centroid point
        this->centroidMap[shape.name] = Centroid(GetCoordinates(shape.cord, shape.n == 4));

    }
}

vector<pair<long double, long double>> DeFuzz::GetCoordinates(const vector<long double> &v, bool f) {
    vector<pair<long double, long double>> vec;
    long double trepArr[4] = {0.0, 1.0, 1.0, 0.0};
    long double triArr[3] = {0.0, 1.0, 0.0};
    for (int i = 0; i < v.size(); i++) {
        vec.emplace_back(v[i], f ? trepArr[i] : triArr[i]);
    }
    return vec;

}

long double DeFuzz::Centroid(vector<pair<long double, long double>> points) {
    long double Area = 0;
    long double sumx = 0;
    for (int i = 0; i + 1 < (int) points.size(); i++) {
        long double term = (points[i].first * points[i + 1].second - points[i].second * points[i + 1].first);
        sumx += (points[i].first + points[i + 1].first) * term;
        Area += term;
    }
    Area /= 2;
    return sumx / (6 * Area);
}

long double DeFuzz::CalcOuptput() {
    long double Dom = 0, Num = 0;
    for (auto &out:inferOutput) {
        Num += out.second * this->centroidMap[out.first];
        Dom += this->centroidMap[out.first];
    }
    return Num / Dom;
}

DeFuzz::DeFuzz() {
    InitAllCentorids();
}
