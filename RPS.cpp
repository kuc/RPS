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
		delete[] throws;
}

//ostream& Player::Display(ostream& out) const {
void Player::Display(ostream& out) const {
	out << "Players Name is: " << name << endl;
	if (throws != nullptr) {
		for (int i = 0; i < 3; i++) {
			if (throws[i] == 0) {
				out << "Round " << i << ":" << " Paper" << endl;
			}
			if (throws[i] == 1) {
				out << "Round " << i << ":" << " Scissors" << endl;
			}
			if (throws[i] == 2) {
				out << "Round " << i << ":" << " Rock" << endl;
			}
		}
	}
	else
		out << "Player " << name << " has played no games yet." << endl;
	out << "There score is: " << score << endl;
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

string Player::Match(Player &p2)
{
	int p1s = 0;
	int p2s = 0;

	for (int i = 0; i < 3; i++) {
		if (throws[i] == 1 && p2.throws[i] == 2) {
			p2s++;
		}
		if (throws[i] == 2 && p2.throws[i] == 1) {
			p1s++;
		}
		if (throws[i] == 0 && p2.throws[i] == 2) {
			p1s++;
		}
		if (throws[i] == 2 && p2.throws[i] == 0) {
			p2s++;
		}
		if (throws[i] == 1 && p2.throws[i] == 0) {
			p1s++;
		}
		if (throws[i] == 0 && p2.throws[i] == 1) {
			p2s++;
		}

	}

	if (p1s < p2s) {
		p2.score++;
		//cout << p2;
		return "p2";
	}
	else if (p1s > p2s) {
		score++;
		//cout << this;
		return "p1";
	}
	else if (p1s == p2s) {
		return "tie";
	}
}

const Player& Player::operator =(const Player& right)
{
	if (this != &right) {
		name = right.name;
		score = right.score;
		if (throws != nullptr) {
			for (int i = 0; i < 3; i++) {
				throws[i] = right.throws[i];
			}
		}
	}
	return * this;
}


bool operator<(const Player& left, const Player& right)
{
	return (left.Score() < right.Score());
}

ostream& operator<<(ostream& out, const Player& player)
{
	player.Display(out);
	return out;
}

