#include <iostream>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H


class Player {

public:
	//constructor
	Player();
	~Player();

	//void Display(ostream & out) const;
	//Score();
	//Name();
	//TakeTurn();
private:
	string name;
	int score;
	int * throws = new int[3];
};


#endif
