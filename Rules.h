//
// Created by Alaa on ٣١/٠٥/٢٠٢١.
//
#include "output.h"

#ifndef GA3_INFERENCE_H
#define GA3_INFERENCE_H

extern vector<pair<string, long double>> inferOutput;
extern  map<string, long double> result;
class Rules {

    static void calc(vector<pair<string, long double>> &update, string &oper);

public:
    static void modify(output &out);
};


#endif //GA3_INFERENCE_H
