#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Base class representing a creature
class Creature {
protected:
    int strength;       // Creature's strength
    int hitpoints;      // Creature's hitpoints

public:
    // Default constructor
    Creature() : strength(10), hitpoints(10) {}

    // Parameterized constructor
    Creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {}

    // Virtual function to get the species of the creature
    virtual string getSpecies() const { return "Creature"; }

    // Function to calculate and return damage dealt by the creature
    int getDamage() const {
        int damage = (rand() % strength) + 1;    // Random damage based on creature's strength
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }

    // Accessor functions for strength and hitpoints
    int getStrength() const { return strength; }
    int getHitpoints() const { return hitpoints; }

    // Mutator functions for strength and hitpoints
    void setStrength(int newStrength) { strength = newStrength; }
    void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }
};

// Derived class representing a human creature
class Human : public Creature {
public:
    // Constructors
    Human() : Creature() {}
    Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    // Override function to get the species of the human creature
    string getSpecies() const { return "Human"; }
};

// Derived class representing an elf creature
class Elf : public Creature {
public:
    // Constructors
    Elf() : Creature() {}
    Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    // Override function to get the species of the elf creature
    string getSpecies() const { return "Elf"; }

    // Override function to calculate damage dealt by the elf creature
    int getDamage() const {
        int damage = (rand() % getStrength()) + 1; // Random damage based on elf's strength
        cout << "The Elf attacks for " << damage << " points!" << endl;
        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= 2;    // Double damage for magical attack
        }
        return damage;
    }
};

// Derived class representing a demon creature
class Demon : public Creature {
public:
    // Constructors
    Demon() : Creature() {}
    Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    // Override function to get the species of the demon creature
    string getSpecies() const { return "Demon"; }

    // Override function to calculate damage dealt by the demon creature
    int getDamage() const {
        int damage = Creature::getDamage(); // Call base class function to calculate damage
        if (rand() % 4 == 0) {
            damage += 50;   // Additional damage for demonic attack
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }
};

// Derived class representing a cyberdemon creature
class Cyberdemon : public Demon {
public:
    // Constructors
    Cyberdemon() : Demon() {}
    Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

    // Override function to get the species of the cyberdemon creature
    string getSpecies() const { return "Cyberdemon"; }
};

// Derived class representing a balrog creature
class Balrog : public Demon {
public:
    // Constructors
    Balrog() : Demon() {}
    Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

    // Override function to get the species of the balrog creature
    string getSpecies() const { return "Balrog"; }

    // Override function to calculate damage dealt by the balrog creature
    int getDamage() const {
        int damage = Demon::getDamage();    // Call base class function to calculate damage
        int damage2 = (rand() % getStrength()) + 1; // Additional damage for balrog's speed attack
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;  // Add additional damage
        return damage;
    }
};

// Function to simulate a battle between two creatures
void battleArena(Creature& creature1, Creature& creature2) {
    cout << endl;
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        int damage1 = creature1.getDamage();    // Damage dealt by creature 1
        creature2.setHitpoints(creature2.getHitpoints() - damage1); // Reduce hitpoints of creature 2
        if (creature2.getHitpoints() <= 0) break; // Check if creature 2 is defeated
        int damage2 = creature2.getDamage();    // Damage dealt by creature 2
        creature1.setHitpoints(creature1.getHitpoints() - damage2); // Reduce hitpoints of creature 1
    }
    // Print the result of the battle
    if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
        cout << "The battle resulted in a tie!" << endl;
    }
    else if (creature1.getHitpoints() <= 0) {
        cout << "The battle is over! " << creature2.getSpecies() << " wins!" << endl;
    }
    else {
        cout << "The battle is over! " << creature1.getSpecies() << " wins!" << endl;
    }
}

// Main function
int main() {
    srand(time(0)); // Seed for random number generator

    // Create instances of different creatures
    Human h;
    Elf e;
    Cyberdemon c;
    Balrog b;

    // Print default strength and hitpoints of each creature
    cout << "default Human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    cout << "default Elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
    cout << "default Cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
    cout << "default Balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;

    cout << endl;

    // Print examples of damage inflicted by Human
    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl;
    }
    cout << endl;

    // Print examples of damage inflicted by Elf
    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
    }

    return 0; // Return 0 to indicate successful execution of the program
}