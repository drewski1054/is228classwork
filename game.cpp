#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int health;

public:
    Character(std::string n, int h) : name(n), health(h) {}

    virtual void attack() = 0; 

    bool isAlive() {
        return health > 0;
    }

    std::string getName() {
        return name;
    }

    void takeDamage(int damage) {
        health -= damage;
    }
};
class Knight : public Character {
public:
    Knight(std::string n) : Character(n, 100) {}

    void attack() override {
        std::cout << name << " swings a sword bravely!" << std::endl;
    }
};

class Archer : public Character {
public:
    Archer(std::string n) : Character(n, 80) {}

    void attack() override {
        std::cout << name << " shoots an arrow accurately!" << std::endl;
    }
};
int main() {
    Knight knight("Sir Arthur");
    Archer archer("Robin");

    Character* player;
    std::string choice;

    std::cout << "Choose your character (Knight/Archer): ";
    std::cin >> choice;

    if (choice == "Knight") {
        player = &knight;
    } else {
        player = &archer;
    }

    std::cout << "You have chosen: " << player->getName() << std::endl;

    
    int monsterHealth = 50;
    while (player->isAlive() && monsterHealth > 0) {
        player->attack();
        monsterHealth -= 20;
        std::cout << "Monster attacks back!" << std::endl;
        player->takeDamage(10);
    }

    if (player->isAlive()) {
        std::cout << "You defeated the monster!" << std::endl;
    } else {
        std::cout << "You have been defeated." << std::endl;
    }

    return 0;
}
