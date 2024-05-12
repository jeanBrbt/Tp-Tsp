//
// Created by barbe on 30/04/2024.
//
#pragma once
#include "Solver.h"

class Neighbours : public Solver {
public:
    virtual void operator()(Solution &_sol, EvalTSP &_eval, int index) = 0;
    virtual int numPossibleNeighbours(int size) const = 0;
    virtual ~Neighbours() {}
};