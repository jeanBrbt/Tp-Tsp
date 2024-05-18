//
// Created by barbe on 11/05/2024.
//
#pragma once

#include "neighbors.h"
#include "Solution.h"
class SwapNeighbours : public neighbors {
public:
    Solution operator()(Solution sol, int index) override;
    int numPossibleNeighbours(int size) const override;
};
