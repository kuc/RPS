#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Throw.h"
#include "Player.h"



// Throw
Throw::Throw() {
	options = 3;
}
int Throw::Shoot() {
	return (rand() % options); 

	// 0 = paper
	// 1 = scissors
	// 2 = rock
}

// Player
Player::Player() {
	name = " ";
}

Player::Player(string n) {
	name = n;
}

Player::~Player() {
	if (throws)
		delete throws;
}

ostream& Player::Display(ostream& out, Player r) const {
	for (int i = 0; i < 3; i++) {
		if (r.throws[i] == 0) {
			out << "Round " << i << ":" << " Paper" << endl;
		}
		if (r.throws[i] == 1) {								
			out << "Round " << i << ":" << " Scissors" << endl;
		}	
		if (r.throws[i] == 2) {
			out << "Round " << i << ":" << " Rock" << endl;
		}
	}
	out << "There score is: " << score << endl;
	return out;
// Display rock,paper,scissors
// display score

}

int Player::Score() const {
	return score;
}

string Player::Name() const
{
	return name;
}

void Player::TakeTurn()
{
	Throw *t = new Throw;
	for (int i = 0; i < 3; i++) {
		throws[i] = t->Shoot();
	}
}

string Player::Match(Player &p1, Player &p2)
{
	int p1s = 0;
	int p2s = 0;

	for (int i = 0; i < 3; i++) {
		if (p1.throws[i] == 1 && p2.throws[i] == 2) {
			p2s++;
		}
		if (p1.throws[i] == 2 && p2.throws[i] == 1) {
			p1s++;
		}
		if (p1.throws[i] == 0 && p2.throws[i] == 2) {
			p1s++;
		}
		if (p1.throws[i] == 2 && p2.throws[i] == 0) {
			p2s++;
		}
		if (p1.throws[i] == 1 && p2.throws[i] == 0) {
			p1s++;
		}
		if (p1.throws[i] == 0 && p2.throws[i] == 1) {
			p2s++;
		}
	}

	if (p1s < p2s) {
		p2.score++;
		return p2.name;
	}
	else
		p1.score++;
		return p1.name;
}


ostream& operator<<(ostream& out, const Player& player)
{
	player.Display(out, player);
	return out;
}

