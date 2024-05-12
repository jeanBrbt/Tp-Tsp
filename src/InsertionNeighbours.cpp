//
// Created by barbe on 11/05/2024.
//
#include "InsertionNeighbours.h"

void InsertionNeighbours::operator()(Solution& _sol, EvalTSP& _eval, int index) {
    if (index <= _sol.size() - 2) {
        _sol.swap(index, index + 1);
    } else {
        int i = (index - 1) / (_sol.size() - 2);
        int j = (index - 1) % (_sol.size() - 2);
        if (j >= i - 1) {
            j = j + 2;
        }
        _sol.swap(i, j);
    }
}

int InsertionNeighbours::numPossibleNeighbours(int size) const {
    return size * (size - 1) / 2;
}
