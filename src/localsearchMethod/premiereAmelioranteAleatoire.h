//
// Created by barbe on 20/05/2024.
//
#pragma once
#include "localsearchMethod.h"
#include "../EvalTSP.h"
#include "../neighbors.h"
#include "../Solution.h"

class premiereAmelioranteAleatoire : public localsearchMethod {
    Solution operator()(EvalTSP &evalTsp, Solution s,neighbors &methodeVoisinage) override;
};

