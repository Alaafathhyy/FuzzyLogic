//
// Created by Alaa on ٣١/٠٥/٢٠٢١.
//
#include "point.h"

#ifndef GA3_FUZZ_H
#define GA3_FUZZ_H

class Fuzz {


    static bool check(long double varNum, point &a);

public:
    static void membership(long double varNum, point &a);


};


#endif //GA3_FUZZ_H
