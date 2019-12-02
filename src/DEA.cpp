//
// Created by Yassine Goeller on 29/11/2019.
//

void independent_runs(const unsigned int val);
void nb_evolution_steps(const unsigned int val);
void population_size(const unsigned int val);
void solution_size(const unsigned int val);


SetUpParams::independent_runs(const unsigned int val){
    _independent_runs = val;
}

SetUpParams::nb_evolution_steps(const unsigned int val){
    _nb_evolution_steps = val;
}

SetUpParams::population_size(const unsigned int val){
    _population_size = val;
}

SetUpParams::solution_size(const unsigned int val){
    _solution_size = val;
}

