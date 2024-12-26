#include <ctime>
#include "array_manager.h"

int main() {
    int randomValues[ARRAY_SIZE];

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        randomValues[i] = std::rand() % 100;
    }

    ArrayManager<int> manager(randomValues);

    std::cout << "Generated Array:" << std::endl;
    manager.display();

    try {
        std::cout << "Minimum Value: " << manager.findMinimum() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
