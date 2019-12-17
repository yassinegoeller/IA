#ifndef IA_DEA_H
#define IA_DEA_H
#include <iostream>
#include <fstream>
#include <vector>


//========================================================================
class Problem
{
public:
    Problem(double LowerBound, double UpperBound, int identity);
    ~Problem();

    int dimension() const;
    double fit_fonction(std::vector<double> x) const;
    double LowerBound() const;
    double UpperBound() const;
    int identity() const;

private:
    int _dimension, _identity;
    double _LowerBound, _UpperBound;

    double bentCigarFunction(std::vector<double> vector) const;
    double discusFunction(std::vector<double> vector) const;
    double weierstrassFunction(std::vector<double> vector) const;
};


//=======================================================================
class Solution
{

private:
    std::vector<double> _solution;
    double _fitness_current;
    const Problem& _pbm;

public:
    Solution (const Problem& pbm);
    Solution (const Solution& sol);
    ~Solution();

    const Problem& pbm() const;

    void initialize();
    double fitness();
    double get_fitness();

    std::vector<double>& get_solution();

    double& get_position_in_solution(const int index);
    void  set_position_in_solution(const int index, const double value);

};


//=======================================================================
class SetUpParams
{
    //ici vous devez mettre quelques param�tres tels que :

private:
    unsigned int   _independent_runs;         //number of independent runs
    unsigned int   _nb_evolution_steps;       // number of iterations per run
    unsigned int   _population_size;		// number of solutions in the population
    unsigned int   _solution_size;          // size of each particle
    double _Pc;
    double _Pm;

public:
    SetUpParams();
    SetUpParams(const SetUpParams& setup);

    const unsigned int   independent_runs() const;
    const unsigned int   nb_evolution_steps() const;
    const unsigned int   population_size() const;
    const unsigned int   solution_size() const;
    const double Pc() const;
    const double Pm() const;
    void independent_runs(const unsigned int val);
    void nb_evolution_steps(const unsigned int val);
    void population_size(const unsigned int val);
    void solution_size(const unsigned int val);
    void Pc(const double val);
    void Pm(const double val);

    ~SetUpParams();
};
//=======================================================================


class Algorithm
{
private:
    std::vector<Solution*> _population;     // individuals in population
    std::vector<double> _fitness_values_of_current_population;
    const SetUpParams& _setup;
    Solution* _global_best_solution;

public:
    Algorithm(const Problem& pbm,const SetUpParams& setup);
    ~Algorithm();

    const SetUpParams& setup() const;
    void initialize();

    // evaluate the current population
    void evaluate();

    const std::vector<Solution*>& current_solutions() const;

    double global_best_cost() const;

    Solution& solution(const unsigned int index) const;

    Solution& global_best_solution() const;

    // main loop of the algorithm
    void evolution();

};

#endif //IA_DEA_H
