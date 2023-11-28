#include <iostream>
#include <cstdlib>
#include <ctime>

class GuessTheNumberGame {
private:
    int targetNumber;
    int attempts;

public:
    GuessTheNumberGame(int min, int max) {
        srand(time(0)); // Seed the random number generator with the current time
        targetNumber = rand() % (max - min + 1) + min;
        attempts = 0;
    }

    void play() {
        int guess;
        std::cout << "Welcome to the Guess the Number game!" << std::endl;
        std::cout << "I'm thinking of a number between 1 and 100. Try to guess it." << std::endl;

        do {
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            attempts++;

            if (guess < targetNumber) {
                std::cout << "Too low! Try again." << std::endl;
            } else if (guess > targetNumber) {
                std::cout << "Too high! Try again." << std::endl;
            } else {
                std::cout << "Congratulations! You guessed the number " << targetNumber << " in " << attempts << " attempts." << std::endl;
            }
        } while (guess != targetNumber);
    }
};

int main() {
    GuessTheNumberGame game(1, 100);
    game.play();
    return 0;
}
