#include "DEA.h"


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

double Problem::fit_fonction(std::vector<double> x) const {
    double resultat;
    switch(_identity){
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
    return identity();
}

//=======================================================================
Solution::Solution(const Solution &sol) : _solution{sol._solution}, _fitness_current{sol._fitness_current}, _pbm{sol._pbm}{}
Solution::~Solution(){}
const Problem& Solution::pbm() const{
    return _pbm;
}


double Solution::get_fitness()
{
    return _fitness_current;
}


double Solution::fitness() {
    switch (this->_pbm.identity()) {
        case 1:;
        case 2:;
        case 3:;
        case 4:;
        case 5:;
        case 6:;
    };

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