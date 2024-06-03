#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

class Creature {
protected:
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain

public:
    Creature(int newStrength = 10, int newHitpoints = 10)
        : strength(newStrength), hitpoints(newHitpoints) {}

    virtual int getDamage() const {
        int damage = (rand() % strength) + 1;
        return damage;
    }

    virtual string getSpecies() const = 0;

    int getHitpoints() const { return hitpoints; }
    void setHitpoints(int hp) { hitpoints = hp; }
    int getStrength() const { return strength; }
    void setStrength(int str) { strength = str; }
};

class Human : public Creature {
public:
    Human(int newStrength = 10, int newHitpoints = 10)
        : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Human";
    }

    int getDamage() const override {
        int damage = Creature::getDamage();
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
};

class Elf : public Creature {
public:
    Elf(int newStrength = 10, int newHitpoints = 10)
        : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Elf";
    }

    int getDamage() const override {
        int damage = Creature::getDamage();
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        if ((rand() % 10) == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= 2;
        }
        return damage;
    }
};

class Demon : public Creature {
public:
    Demon(int newStrength = 10, int newHitpoints = 10)
        : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Demon";
    }

    int getDamage() const override {
        int damage = Creature::getDamage();
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        if ((rand() % 100) < 5) {
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
            damage += 50;
        }
        return damage;
    }
};

class Cyberdemon : public Demon {
public:
    Cyberdemon(int newStrength = 10, int newHitpoints = 10)
        : Demon(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Cyberdemon";
    }
};

class Balrog : public Demon {
public:
    Balrog(int newStrength = 10, int newHitpoints = 10)
        : Demon(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Balrog";
    }

    int getDamage() const override {
        int damage = Demon::getDamage();
        int damage2 = (rand() % strength) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        return damage;
    }
};

void battleArena(Creature& creature1, Creature& creature2) {
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        int damage1 = creature1.getDamage();
        int damage2 = creature2.getDamage();

        creature1.setHitpoints(creature1.getHitpoints() - damage2);
        creature2.setHitpoints(creature2.getHitpoints() - damage1);

        cout << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hitpoints left." << endl;
        cout << creature2.getSpecies() << " has " << creature2.getHitpoints() << " hitpoints left." << endl;

        if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
            cout << "The battle is a tie!" << endl;
            return;
        }
        else if (creature1.getHitpoints() <= 0) {
            cout << creature2.getSpecies() << " wins the battle!" << endl;
            return;
        }
        else if (creature2.getHitpoints() <= 0) {
            cout << creature1.getSpecies() << " wins the battle!" << endl;
            return;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    Human h(30, 100);
    Elf e(30, 100);
    Cyberdemon c(40, 100);
    Balrog b(50, 100);

    cout << "Battle between Human and Elf:" << endl;
    battleArena(h, e);

    cout << "\nBattle between Cyberdemon and Balrog:" << endl;
    battleArena(c, b);

    cout << "\nBattle between Elf and Balrog:" << endl;
    battleArena(e, b);

    return 0;
}

