//
// Created by barbe on 11/05/2024.
//
#pragma once

#include "Neighbourgs.h"




class InsertionNeighbours : public Neighbours {
public:
    void operator()(Solution& _sol, EvalTSP& _eval, int index) override;
    int numPossibleNeighbours(int size) const override;
};