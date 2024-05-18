//
// Created by barbe on 30/04/2024.
//
#pragma once
#include "Solver.h"
#include "Solution.h"
class neighbors /*: public Solver */{
public:
    virtual Solution operator()(Solution sol, int index) = 0;

    virtual int numPossibleNeighbours(int size) const = 0;
};