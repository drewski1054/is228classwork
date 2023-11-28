#include <iostream>

int main() {
    const int ROWS = 3;
    const int COLS = 3;
    int array[ROWS][COLS];

    
    std::cout << "Enter " << ROWS * COLS << " numbers:\n";
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            std::cout << "Enter a number for [" << i << "][" << j << "]: ";
            std::cin >> array[i][j];
        }
    }

    
    std::cout << "Contents of the array:\n";
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
