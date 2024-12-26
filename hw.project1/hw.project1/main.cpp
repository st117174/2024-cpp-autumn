#include "dataset.h"

int main() {
    try {
        Dataset dataset("./test_data.csv");
        std::cout << "First 5 rows:\n";
        dataset.head();

        std::cout << "\nLast 5 rows:\n";
        dataset.tail();

        std::cout << "\nDescribe column 'col3':\n";
        dataset.describe("col3");

        std::cout << "\nRow at index 1:\n";
        dataset.printRow(dataset[1]);

        std::cout << "\nElement at (1, 2): " << dataset(1, 2) << "\n";

        dataset.insert(1, {"4", "new_row", "10.5"});
        std::cout << "\nAfter inserting a row:\n";
        dataset.head();

        dataset.remove(1);
        std::cout << "\nAfter removing a row:\n";
        dataset.head();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
