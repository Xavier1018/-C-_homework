#include <iostream>
#include <cstdlib>

using namespace std;

// Base class representing a generic creature
class Creature {
protected:
    int strength;
    int hitpoints;
public:
    // Constructors with default values
    Creature(int newStrength = 10, int newHitpoints = 10) : strength(newStrength), hitpoints(newHitpoints) {}

    // Pure virtual function to get the species of the creature
    virtual string getSpecies() const = 0;

    // Pure virtual function to get the damage inflicted by the creature
    virtual int getDamage() const = 0;

    // Accessors
    int getStrength() const { return strength; }
    int getHitpoints() const { return hitpoints; }

    // Mutators
    void setStrength(int newStrength) { strength = newStrength; }
    void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }
};

// Derived class representing a demon
class Demon : public Creature {
public:
    using Creature::Creature;

    // Override the getDamage() function to include demon-specific behavior
    int getDamage() const override {
        int damage = rand() % strength + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        if (rand() % 4 == 0) {
            damage += 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }
};

// Derived class representing a human
class Human : public Creature {
public:
    using Creature::Creature;

    // Override the getSpecies() function to return "Human"
    string getSpecies() const override { return "Human"; }

    // Override the getDamage() function to include human-specific behavior
    int getDamage() const override {
        int damage = rand() % strength + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
};

// Derived class representing an elf
class Elf : public Creature {
public:
    using Creature::Creature;

    // Override the getSpecies() function to return "Elf"
    string getSpecies() const override { return "Elf"; }

    // Override the getDamage() function to include elf-specific behavior
    int getDamage() const override {
        int damage = rand() % strength + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        if (rand() % 2 == 0) {
            damage *= 2;
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        }
        return damage;
    }
};

// Derived class representing a cyberdemon
class Cyberdemon : public Demon {
public:
    using Demon::Demon;

    // Override the getSpecies() function to return "Cyberdemon"
    string getSpecies() const override { return "Cyberdemon"; }
};

// Derived class representing a balrog
class Balrog : public Demon {
public:
    using Demon::Demon;

    // Override the getSpecies() function to return "Balrog"
    string getSpecies() const override { return "Balrog"; }

    // Override the getDamage() function to include balrog-specific behavior
    int getDamage() const override {
        int damage = Demon::getDamage(); // Get damage from the demon part
        int damage2 = rand() % strength + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        return damage;
    }
};

int main() {
    srand(time(0)); // Seed random number generator

    // Create instances of different creatures
    Human human(20, 20);
    Elf elf(15, 15);
    Cyberdemon cyberdemon(25, 25);
    Balrog balrog(30, 30);

    // Simulate rounds of combat
    for (int i = 0; i < 5; ++i) {
        cout << "Round " << i + 1 << ":" << endl;
        cout << "Human damage: " << human.getDamage() << endl;
        cout << "Elf damage: " << elf.getDamage() << endl;
        cout << "Cyberdemon damage: " << cyberdemon.getDamage() << endl;
        cout << "Balrog damage: " << balrog.getDamage() << endl;
        cout << endl;
    }

    return 0;
}
