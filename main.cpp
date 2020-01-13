#include <iostream>
#include <DEA.h>

int main() {
    srand(time(NULL));
    Problem bent{-100, 100, 1, 20};
    SetUpParams setup{};
    Algorithm DEA{bent, setup};
    DEA.evolution();
}