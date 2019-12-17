#include "DEA.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

//=======================================================================
Problem::Problem(double LowerBound, double UpperBound,int i) : _LowerBound{LowerBound}, _UpperBound{UpperBound},_dimension{20},_identity{i}
{}

Problem::Problem(const Problem& pb) : _LowerBound{pb._LowerBound}, _UpperBound{pb._UpperBound},_dimension{20},_identity{pb._identity}
{}

int Problem::dimension() const{
    return _dimension;
}

Problem::~Problem() {}

double Problem::UpperBound() const
{ return _UpperBound;}

double Problem::LowerBound() const
{ return _LowerBound;}

double Problem::fit_fonction(std::vector<double> x) const {
    double resultat;
    switch(identity()){
        case 1 :
            resultat = bentCigarFunction(x);
            break;
        case 2 :
            resultat = discusFunction(x);
            break;
        case 3 :
            resultat = weierstrassFunction(x);
            break;
        case 4 : ;
        case 5 : ;
        case 6 : ;
    }
    return resultat;
}

double Problem::bentCigarFunction(std::vector<double> x) const {
    double resultat = x.at(0);
    for(int i=1; i<_dimension; i++) {
        resultat += pow(10,6) * pow(x.at(i),2);
    }
    return resultat;
}

double Problem::discusFunction(std::vector<double> x) const {
    double resultat = pow(10,6) * pow(x.at(0),2);
    for(int i=1; i<_dimension; i++){
        resultat += pow(x.at(i),2);
    }
    return resultat;
}

double Problem::weierstrassFunction(std::vector<double> x) const {
    const double pi = 3.14159265358979323846;
    double resultat1 = 0, resultat2 = 0, a = 0.5;
    int b = 3, kmax = 20;
    for(int i=0; i<_dimension; ++i){
        for(int k=0; k<=kmax; ++k) {
            resultat1 += (pow(a,k) * cos((2*pi*pow(b, k)) * x.at(i)+0.5));
            resultat2 += pow(a,k) * cos(2*pi*pow(b,k)*0.5);
        }
    }
    resultat2 = _dimension * resultat2;

    return resultat1 - resultat2;
}

int Problem::identity() const
{
    return _identity;
}

//=======================================================================

Solution::Solution(const Solution &sol) : _solution{sol._solution}, _fitness_current{sol._fitness_current}, _pbm{sol._pbm}{}

Solution::Solution(const Problem &pbm) : _solution{}, _fitness_current{}, _pbm{pbm}
{
    initialize();
    _fitness_current = fitness();
}

Solution::~Solution(){}

const Problem& Solution::pbm() const{
    return _pbm;
}
void Solution::initialize()
{
    srand(time(NULL));
    double taille = _pbm.UpperBound()-_pbm.LowerBound();
    double aleatoire = (double) rand() / RAND_MAX;
    for(int i = 0; i < _pbm.dimension(); ++i)
    {
        _solution[i] = _pbm.LowerBound() + aleatoire * taille;

    }
}

double Solution::fitness() {
    return this->_pbm.fit_fonction(this->_solution);
}

double Solution::get_fitness()
{
    return _fitness_current;
}

std::vector<double> & Solution::get_solution()
{
    return _solution;
}

double & Solution::get_position_in_solution(const int index)
{
    return _solution[index];
}

void Solution::set_position_in_solution(const int index, const double value)
{
    _solution[index] = value;
}

//=======================================================================

SetUpParams::SetUpParams() : _independent_runs{30}, _nb_evolution_steps{50000},
_population_size{40}, _solution_size{20}, _Pc{0.5}, _Pm{0.1}
{}

SetUpParams::SetUpParams(const SetUpParams &setup) : _independent_runs{setup._independent_runs},
_nb_evolution_steps{setup._nb_evolution_steps}, _population_size{setup.population_size()},
_solution_size{setup._solution_size}, _Pc{setup._Pc}, _Pm{setup._Pm}
{}

SetUpParams::~SetUpParams()
{}

const unsigned int SetUpParams::independent_runs() const {
    return _independent_runs;
}

const unsigned int SetUpParams::nb_evolution_steps() const {
    return _nb_evolution_steps;
}

const unsigned int SetUpParams::population_size() const {
    return _population_size;
}

const unsigned int SetUpParams::solution_size() const {
    return _solution_size;
}

const double SetUpParams::Pc() const {
    return _Pc;
}

const double SetUpParams::Pm() const {
    return _Pm;
}

void SetUpParams::independent_runs(const unsigned int val) {
    _independent_runs = val;
}

void SetUpParams::nb_evolution_steps(const unsigned int val) {
    _nb_evolution_steps = val;
}

void SetUpParams::population_size(const unsigned int val) {
    _population_size = val;
}

void SetUpParams::solution_size(const unsigned int val) {
    _solution_size = val;
}

void SetUpParams::Pc(const double val) {
    _Pc = val;
}

void SetUpParams::Pm(const double val) {
    _Pm = val;
}

//=======================================================================

Algorithm::Algorithm(const Problem &pbm, const SetUpParams &setup): _setup{setup} {
    for(int i = 0; i < setup.population_size(); ++i) {
        _population[i] = new Solution {pbm};
       _fitness_values_of_current_population[i] = _population[i]->fitness();
       if (_global_best_solution->get_fitness() < _fitness_values_of_current_population[i])
           _global_best_solution = _population[i];
    }
}
