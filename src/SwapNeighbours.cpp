//
// Created by barbe on 11/05/2024.
//

#include <valarray>
#include "SwapNeighbours.h"

void SwapNeighbours::operator()(Solution& _sol, EvalTSP& _eval, int index)  {
    int n =  (1 + sqrt(1 + 8 * index)) / 2;
    int i = index - (n * (n - 1)) / 2;
    int j = _sol.size() - n + i;
    _sol.swap(i, j);
}

int SwapNeighbours::numPossibleNeighbours(int size)const {
    return size * (size - 1) / 2;
}
