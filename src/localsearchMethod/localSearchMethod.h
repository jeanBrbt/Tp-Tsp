//
// Created by barbe on 30/04/2024.
//
#pragma once
#include "../Solution.h"
#include "../EvalTSP.h"
#include "../neighbors.h"
class localsearchMethod /*: public Solver */{
public:
    virtual Solution operator()(EvalTSP &evalTsp, Solution s,neighbors &methodeVoisinage) = 0;

};