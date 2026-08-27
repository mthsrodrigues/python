#include <iostream>
#include "SimpleMET.h"

int main() {
    SimpleMET met;

    met.Add(10.0, 5.0);
    met.Add(-10.0, -5.0);

    std::cout << "MET = " << met.Value() << std::endl;
    std::cout << "Ex = " << met.Ex() << std::endl;
    std::cout << "Ey = " << met.Ey() << std::endl;
    std::cout << "Phi = " << met.Phi() << std::endl;

    return 0;
}
