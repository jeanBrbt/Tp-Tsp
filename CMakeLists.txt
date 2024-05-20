cmake_minimum_required(VERSION 3.26)
project(TSP2024)

set(CMAKE_CXX_STANDARD 17)

add_executable(TSP2024 main.cpp
        src/InstanceTSP.cpp
        src/InstanceTSP.h
        src/Solution.cpp
        src/Solution.h
        src/EvalTSP.cpp
        src/EvalTSP.h
        src/Solver.h
        src/Solver.h
        src/Random.cpp
        src/Random.h
        src/Random.h
        src/Greedy.cpp
        src/Greedy.h
        src/neighbors.h
        src/SwapNeighbours.cpp
        src/SwapNeighbours.h
        src/InsertionNeighbours.cpp
        src/InsertionNeighbours.h
        src/TwoOptNeighbours.cpp
        src/TwoOptNeighbours.h
        src/Localsearch.cpp
        src/Localsearch.cpp
        src/Localsearch.h
        src/Localsearch.cpp
        src/Localsearch.cpp
        src/localsearchMethod/meilleureAmeliorante.cpp
        src/localsearchMethod/meilleureAmeliorante.h
        src/localsearchMethod/premiereAmeliorante.cpp
        src/localsearchMethod/premiereAmeliorante.h
        src/localsearchMethod/premiereAmelioranteAleatoire.cpp
        src/localsearchMethod/premiereAmelioranteAleatoire.h)
