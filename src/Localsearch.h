//
// Created by barbe on 14/05/2024.
//
#pragma once
#include "Solution.h"
#include <vector>
#include "EvalTSP.h"
#include "neighbors.h"

class Localsearch {
public:
    Solution meilleur_ameliorante(EvalTSP &evalTsp, Solution s,neighbors &methodeVoisinage);

    Solution algorithme_descente(EvalTSP &evalTsp, Solution s, neighbors &methodeVoisinage);
};


