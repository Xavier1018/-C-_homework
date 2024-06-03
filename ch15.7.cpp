#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Dice
{
public:
	Dice();
	Dice(int numSides);
	virtual int rollDice()const;
protected:
	int numSides;
};

Dice::Dice()
{
	numSides = 6;
	srand(time(NULL));
}
Dice::Dice(int numSides)
{
	this->numSides = numSides;
	srand(time(NULL));
}
int Dice::rollDice()const
{
	return (rand() % numSides) + 1;
}
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}

class LoadedDice:public Dice
{
public:
	LoadedDice();
	LoadedDice(int numSides) :Dice(numSides) {}
	int rollDice()const override;
};

int LoadedDice::rollDice()const
{
	if (rand() % 2 == 0) {
		return numSides;
	}else{
		return Dice::rollDice();
	}
}
int main()
{
	LoadedDice die1(6);
	LoadedDice die2(8);

	for (int i = 0; i < 10; ++i) {
		cout << "Roll " << i + 1 << ": " << rollTwoDice(die1, die2) << endl;
	}
	return 0;
}