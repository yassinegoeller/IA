#include "DEA.h"
#include <cmath>
#include <cstdlib>
#include <ctime>


//=======================================================================
Problem::Problem(double LowerBound, double UpperBound,int i) : _LowerBound{LowerBound}, _UpperBound{UpperBound},_dimension{20},_identity{i}
{}

int Problem::dimension() const{
    return _dimension;
}

Problem::~Problem() {}

double Problem::UpperBound() const
{ return _UpperBound;}

double Problem::LowerBound() const
{ return _LowerBound;}

//=======================================================================
Solution::Solution(const Solution &sol) : _solution{sol._solution}, _fitness_current{sol._fitness_current}, _pbm{sol._pbm}{}
Solution::~Solution(){}
const Problem& Solution::pbm() const{
    return _pbm;
}
void Solution::initialize()
{
    srand(time(NULL)); SetUpParams param{};
    double taille = _pbm.UpperBound()-_pbm.LowerBound();
    double aleatoire = (double) rand() / RAND_MAX;
    for(int i = 0; i < param.population_size(); ++i)
    {
        _solution[i] = _pbm.LowerBound() + aleatoire * taille;

    }
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