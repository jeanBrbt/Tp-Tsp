//
// Created by barbe on 14/05/2024.
//

#include <limits>
#include "Localsearch.h"

Solution Localsearch::meilleur_ameliorante(EvalTSP &evalTsp, Solution s, neighbors &methodeVoisinage) {
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


Solution Localsearch::algorithme_descente(EvalTSP &evalTsp, Solution s, neighbors &methodeVoisinage) {
    Solution solution = s;
    double distance_solution = evalTsp(s);
    Solution meilleure_solution = s;
    double meilleure_distance = std::numeric_limits<double>::infinity();
    while (meilleure_distance > distance_solution) {
        meilleure_solution = solution;
        meilleure_distance = distance_solution;
        solution = meilleur_ameliorante(evalTsp, solution, methodeVoisinage);
        distance_solution = evalTsp(solution);
    }
    return meilleure_solution;
}