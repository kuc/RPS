#include <iostream>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H


class Player {

public:
	//(de)constructor(s)
	Player();
	Player(string n);
	~Player();

	// Accessors
	void Display(ostream& out) const;
	int Score() const;
	string Name() const;
	void TakeTurn();
	string Match(Player& p2);

	// Assignment Operator
	const Player& operator =(const Player& right);

private:
	string name;
	int score = 0;
	int * throws = new int[3];
};

bool operator < (const Player& left, const Player& right);
ostream& operator << (ostream& out, const Player& player);

#endif
