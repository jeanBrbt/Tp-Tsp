//
// Created by barbe on 14/05/2024.
//

#pragma once
#include "neighbors.h"


class TwoOptNeighbours : public neighbors {
public:
    Solution operator()(Solution sol, int index) override;
    int numPossibleNeighbours(int size) const override;
};


