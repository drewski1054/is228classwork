#include <iostream>
#include <cstdlib>
#include <ctime>


class RockPaperScissorsGame {
public:
    void play() {
        srand(time(0));

        char userChoice;
        char computerChoice;

        std::cout << "Welcome to the Rock, Paper, Scissors game!" << std::endl;
        std::cout << "Choose (R)ock, (P)aper, or (S)cissors: ";
        std::cin >> userChoice;

        
        int randomNum = rand() % 3; 
        if (randomNum == 0) {
            computerChoice = 'R';
        } else if (randomNum == 1) {
            computerChoice = 'P';
        } else {
            computerChoice = 'S';
        }

        std::cout << "Computer chose: " << computerChoice << std::endl;

        if (userChoice == computerChoice) {
            std::cout << "It's a tie!" << std::endl;
        } else if ((userChoice == 'R' && computerChoice == 'S') ||
                   (userChoice == 'P' && computerChoice == 'R') ||
                   (userChoice == 'S' && computerChoice == 'P')) {
            std::cout << "You win!" << std::endl;
        } else {
            std::cout << "Computer wins!" << std::endl;
        }
    }
};

int main() {
    RockPaperScissorsGame game;
    game.play();
    return 0;
}
