//
// Created by barbe on 14/05/2024.
//

#include <valarray>
#include "TwoOptNeighbours.h"

Solution TwoOptNeighbours::operator()(Solution sol, int index)  {
    int n = (1 + sqrt(1 + 8 * index)) / 2;
    int i = index - (n * (n - 1)) / 2;
    int j = sol.size() - n + i;
    sol.two_opt( i, j);
    return sol;
}
int TwoOptNeighbours::numPossibleNeighbours(int size)const {
    return size * (size - 1) / 2;
}