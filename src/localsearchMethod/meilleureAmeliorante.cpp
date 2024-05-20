//
// Created by barbe on 20/05/2024.
//

#include "meilleureAmeliorante.h"

Solution meilleureAmeliorante::operator()(EvalTSP &evalTsp, Solution s,neighbors &methodeVoisinage) {
    Solution meilleure_solution = s;
    double meilleure_distance = evalTsp(s);
    for (int i = 0; i < methodeVoisinage.numPossibleNeighbours(s.size()); i++) {
        Solution solution_voisine = methodeVoisinage(s, i);
        double distance_voisine = evalTsp(solution_voisine);
        if (distance_voisine < meilleure_distance) {
            meilleure_solution = solution_voisine;
            meilleure_distance = distance_voisine;
        }
    }
    return meilleure_solution;
}
