#ifndef IA_DEA_H
#define IA_DEA_H
#include <iostream>
#include <fstream>
#include <vector>

#define BENT_CIGAR_FUNCTION 1
#define DISCUS_FUNCTION 2
#define WEIERSTRASS_FUNCTION 3
#define KATSUURA_FUNCTION 4
#define HAPPY_CAT_FUNCTION 5
#define HG_BAT_FUNCTION 6


//========================================================================
class Problem
{
public:
    Problem(double LowerBound, double UpperBound, int identity, int dimension);
    Problem(const Problem& pb);

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
    double katsuuraFunction(std::vector<double> vector) const;
    double happyCatFunction(std::vector<double> vector) const;
    double HGBatFunction(std::vector<double> vector) const;
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

    const Problem& pbm() const;

    void initialize();
    double fitness();
    double get_fitness() const;

    std::vector<double>& get_solution();

    double get_position_in_solution(const int index) const;
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
    double _CR;

public:
    SetUpParams();
    SetUpParams(const SetUpParams& setup);

    const unsigned int   independent_runs() const;
    const unsigned int   nb_evolution_steps() const;
    const unsigned int   population_size() const;
    const unsigned int   solution_size() const;
    const double CR() const;
    void independent_runs(const unsigned int val);
    void nb_evolution_steps(const unsigned int val);
    void population_size(const unsigned int val);
    void solution_size(const unsigned int val);
    void CR(const double val);

    ~SetUpParams();
};
//=======================================================================


class Algorithm
{
private:
    std::vector<Solution> _population;     // individuals in population
    std::vector<double> _fitness_values_of_current_population;
    const SetUpParams& _setup;
    Solution _global_best_solution;

public:
    Algorithm(const Problem& pbm,const SetUpParams& setup);

    const SetUpParams& setup() const;
    void initialize();

    // evaluate the current population
    void evaluate();

    const std::vector<Solution>& current_solutions() const;

    double global_best_cost() const;

    Solution solution(const unsigned int index) const;

    Solution global_best_solution() const;

    // main loop of the algorithm
    void evolution();

};

#endif //IA_DEA_H
