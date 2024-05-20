//
// Created by barbe on 20/05/2024.
//

#include "premiereAmeliorante.h"

Solution premiereAmeliorante::operator()(EvalTSP &evalTsp, Solution s, neighbors &methodeVoisinage) {
    double distanceSolution = evalTsp(s);
    for (int i = 0; i < methodeVoisinage.numPossibleNeighbours(s.size()); i++) {
        Solution solution_voisine = methodeVoisinage(s, i);
        double distance_voisine = evalTsp(solution_voisine);
        if (distance_voisine < distanceSolution) {
            return solution_voisine;

        }
    }
    return s;
}
