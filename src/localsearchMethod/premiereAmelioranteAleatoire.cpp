//
// Created by barbe on 20/05/2024.
//

#include <algorithm>
#include <random>
#include "premiereAmelioranteAleatoire.h"

Solution premiereAmelioranteAleatoire::operator()(EvalTSP &evalTsp, Solution s, neighbors &methodeVoisinage) {
    std::vector<int> order;
    for (int i = 0; i < methodeVoisinage.numPossibleNeighbours(s.size()); i++) {
        order.push_back(i);
    }
    std::shuffle(order.begin(), order.end(), std::mt19937(std::random_device()()));
    double distanceSolution = evalTsp(s);
    for (int i = 0; i < methodeVoisinage.numPossibleNeighbours(s.size()); i++) {
        Solution solution_voisine = methodeVoisinage(s, order[i]);
        double distance_voisine = evalTsp(solution_voisine);
        if (distance_voisine < distanceSolution) {
            return solution_voisine;

        }
    }
    return s;
}
