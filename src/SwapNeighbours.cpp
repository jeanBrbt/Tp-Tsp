//
// Created by barbe on 11/05/2024.
//

#include <valarray>
#include "SwapNeighbours.h"

Solution SwapNeighbours::operator()(Solution sol, int index)  {
    int n =  (1 + sqrt(1 + 8 * index)) / 2;
    int i = index - (n * (n - 1)) / 2;
    int j = sol.size() - n + i;
    sol.swap(i, j);
    return sol;
}

int SwapNeighbours::numPossibleNeighbours(int size)const {
    return size * (size - 1) / 2;
}
