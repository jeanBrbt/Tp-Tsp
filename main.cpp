#include <iostream>
#include "src/InstanceTSP.h"
#include "src/Solution.h"
#include "src/EvalTSP.h"
#include "src/Random.h"
#include "src/Greedy.h"
#include "src/SwapNeighbours.h"
#include "src/InsertionNeighbours.h"
#include "src/TwoOptNeighbours.h"
#include "src/Localsearch.h"
int main() {
    InstanceTSP instanceTsp("instances/france_100.tsp");

    Solution solution(instanceTsp);
    std::cout << solution << std::endl;

    EvalTSP evalTsp(instanceTsp);
    Greedy greedy;
    solution.shuffle();
    greedy(solution, evalTsp);

    std::cout << solution << std::endl;
    std::cout << evalTsp(solution) << std::endl;

// test SwapNeighbours
    SwapNeighbours swapNeighbours;
    std::cout << "Nombre de voisins possibles pour l'échange : " << swapNeighbours.numPossibleNeighbours(solution.size()) << std::endl;
       solution.shuffle();
    std::cout << "Solution avant échange : " << solution << std::endl;
    swapNeighbours(solution,2);
    std::cout << "Solution après échange : " << solution << std::endl;
// test InsertionNeighbours
    InsertionNeighbours insertionNeighbours;
    std::cout << "Nombre de voisins possibles pour l'insertion : " << insertionNeighbours.numPossibleNeighbours(solution.size()) << std::endl;
    solution.shuffle();
    std::cout << "Solution avant insertion : " << solution << std::endl;
    insertionNeighbours(solution,0);
    std::cout << "Solution après insertion : " << solution << std::endl;
    TwoOptNeighbours twoOptNeighbours;
    std::cout << "Nombre de voisins possibles pour le 2-opt : " << twoOptNeighbours.numPossibleNeighbours(solution.size()) << std::endl;
    solution.shuffle();
    std::cout << "Solution avant 2-opt : " << solution << std::endl;
    twoOptNeighbours(solution,2);
    std::cout << "Solution après 2-opt : " << solution << std::endl;

    // test Localsearch
    std::cout << "Test de l'algorithme de descente" << std::endl;
    Localsearch localsearch;
    Solution solution2 = localsearch.algorithme_descente(evalTsp, solution, twoOptNeighbours);
    std::cout << solution2 << std::endl;
    std::cout << evalTsp(solution2) << std::endl;

    std::cout << "Test de l'algorithme de descente" << std::endl;
    Solution solution3 = localsearch.algorithme_descente(evalTsp, solution, swapNeighbours);
    std::cout << solution3 << std::endl;
    std::cout << evalTsp(solution3) << std::endl;







    return 0;
}
