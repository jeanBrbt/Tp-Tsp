//
// Created by lucien.mousin on 08/04/2024.
//

#include <random>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "Solution.h"

Solution::Solution(InstanceTSP _i) {
    villes.resize(_i.getVilles().size());
    for(int i = 0; i < villes.size(); i++) {
        villes[i] = i;
    }
}

std::vector<int> Solution::getSolution() const {
    return this->villes;
}

int Solution::operator[](int i) const {
    if ( i < 0 )
        return this->villes[this->villes.size() + i ];
    return this->villes[i];
}

int Solution::size() const {
    return this->villes.size();
}

void Solution::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    g.seed(time(NULL));
    std::shuffle(this->villes.begin(), this->villes.end(), g);
}

void Solution::swap(int i, int j) {
    std::swap(this->villes[i], this->villes[j]);
}


std::ostream& operator<<(std::ostream &os, const Solution &sol) {
    for (auto v : sol.getSolution()) {
        os << v << " ";
    }
    return os;
}
void Solution::two_opt(int i, int j) {
    while (i < j) {
        this->swap(i, j);
        i++;
        j--;
    }
}
void Solution::save(std::string filename) {
    std::ofstream
    file(filename);
    for (auto v: this->villes) {
        file << v << " ";
    }
    file << std::endl;
}