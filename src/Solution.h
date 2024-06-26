#pragma once


#include <vector>
#include "InstanceTSP.h"
#include <iostream>

class Solution {
public:
    Solution(InstanceTSP i);

    int operator[](int i) const;
    int size() const;

    std::vector<int> getSolution() const;
    void shuffle();
    void swap(int i, int j);
    void two_opt(int i, int j);
    void save(std::string filename);
        protected:
    std::vector<int> villes;
};

std::ostream& operator<<(std::ostream &os, const Solution &sol);