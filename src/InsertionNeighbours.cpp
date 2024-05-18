//
// Created by barbe on 11/05/2024.
//
#include "InsertionNeighbours.h"

Solution InsertionNeighbours::operator()(Solution sol, int index) {
    if (index <= sol.size() - 2) {
        sol.swap(index, index + 1);
    } else {
        int i = (index - 1) / (sol.size() - 2);
        int j = (index - 1) % (sol.size() - 2);
        if (j >= i - 1) {
            j = j + 2;
        }
        sol.swap(i, j);
    }
}

int InsertionNeighbours::numPossibleNeighbours(int size) const {
    return (size+1)^2;
}
