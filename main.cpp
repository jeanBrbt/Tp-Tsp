#include <iostream>
#include "src/InstanceTSP.h"
#include "src/Solution.h"
#include "src/EvalTSP.h"
#include "src/Greedy.h"
#include "src/SwapNeighbours.h"
#include "src/InsertionNeighbours.h"
#include "src/TwoOptNeighbours.h"
#include "src/Localsearch.h"
#include "src/localsearchMethod/meilleureAmeliorante.h"
#include "src/localsearchMethod/premiereAmeliorante.h"
#include "src/localsearchMethod/premiereAmelioranteAleatoire.h"

int main() {
    InstanceTSP instanceTsp("instances/france_10.tsp");

    Solution solution(instanceTsp);
    std::cout << solution << std::endl;

    EvalTSP evalTsp(instanceTsp);
    Greedy greedy;
    solution.shuffle();
    greedy(solution, evalTsp);

    std::cout << solution << std::endl;
    std::cout << evalTsp(solution) << std::endl;
    solution.save("solutionGreedy.tsp");

    std::cout << "Test des fonction" << std::endl;
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
    meilleureAmeliorante meilleureAmeliorante;
    premiereAmeliorante premiereAmeliorante;
    premiereAmelioranteAleatoire premiereAmelioranteAleatoire;

   // Solution solution2 = localsearch.algorithme_descente(evalTsp, solution, twoOptNeighbours);
   std::cout << "Test de l'algorithme de descente avec la méthode meilleureAmeliorante" << std::endl;
    Solution solution2 = localsearch.algorithme_descente(evalTsp, solution, swapNeighbours,meilleureAmeliorante);
    solution2.save("solution2MeilleureAmeliorante.tsp");
    std::cout << solution2 << std::endl;
    std::cout << evalTsp(solution2) << std::endl;

    std::cout << "Test de l'algorithme de descente avec la méthode premiereAmeliorante" << std::endl;
    solution2 = localsearch.algorithme_descente(evalTsp, solution, swapNeighbours,premiereAmeliorante);
    solution2.save("solution2PremiereAmeliorante.tsp");
    std::cout << solution2 << std::endl;
    std::cout << evalTsp(solution2) << std::endl;

    std::cout << "Test de l'algorithme de descente avec la méthode premiereAmelioranteAleatoire" << std::endl;
    solution2 = localsearch.algorithme_descente(evalTsp, solution, swapNeighbours,premiereAmelioranteAleatoire);
    solution2.save("solution2PremiereAmelioranteAleatoire.tsp");
    std::cout << solution2 << std::endl;
    std::cout << evalTsp(solution2) << std::endl;







    return 0;
}
