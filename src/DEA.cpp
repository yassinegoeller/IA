//
// Created by Yassine Goeller on 29/11/2019.
//
#include "DEA.h"
//=======================================================================
int Problem::dimension() const{
    return _dimension;
}
//=======================================================================
Solution::Solution(const Solution &sol) : _solution{sol._solution}, _fitness_current{sol._fitness_current}, _pbm{sol._pbm}{}
const Problem& Solution::pbm() const{
    return _pbm;
}
//=======================================================================
void SetUpParams::independent_runs(const unsigned int val){
    _independent_runs = val;
}

void SetUpParams::nb_evolution_steps(const unsigned int val){
    _nb_evolution_steps = val;
}

void SetUpParams::population_size(const unsigned int val){
    _population_size = val;
}

void SetUpParams::solution_size(const unsigned int val){
    _solution_size = val;
}
//=======================================================================