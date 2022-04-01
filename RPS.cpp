#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Throw.h"
#include "Player.h"



// Throw Constructor
Throw::Throw() {
	options = 3;
}

//***********************************************************
// 
// Shoot() picks a random number in the range 0-2
// 
// Sent in: Nothing
// Sent back: a number from 0-2
// 
//***********************************************************
int Throw::Shoot() {
	return (rand() % options); 

	// 0 = paper
	// 1 = scissors
	// 2 = rock
}

// Player Constructor
Player::Player() {
	name = " ";
}

// Player Value Constructor
Player::Player(string n) {
	name = n;
}

// Player Deconstructor
Player::~Player() {
	if (throws)
		delete[] throws;
}

//***********************************************************
// 
// Display() shows the players name, what they threw each round,
// if they even played, and their score
// 
// Sent in: implicit
// Sent back: Nothing
// 
//***********************************************************
void Player::Display(ostream& out) const {
	out << "Player's Name is: " << name << endl;
	if (throws != nullptr) {
		for (int i = 0; i < 3; i++) {
			if (throws[i] == 0) {
				out << "Throw " << i+1 << ":" << " Paper" << endl;
			}
			if (throws[i] == 1) {
				out << "Throw " << i+1 << ":" << " Scissors" << endl;
			}
			if (throws[i] == 2) {
				out << "Throw " << i+1 << ":" << " Rock" << endl;
			}
		}
	}
	else
		out << "Player " << name << " has played no games yet." << endl;
	out << name << "'s score is: " << score << endl;
// Display rock,paper,scissors
// display score

}

//***********************************************************
// 
// Score() shows the score of the player
// 
// Sent in: Nothing
// Sent back: players score
// 
//***********************************************************
int Player::Score() const {
	return score;
}

//***********************************************************
// 
// Name() shows the name of the player
// 
// Sent in: Nothing
// Sent back: the name of the player
// 
//***********************************************************
string Player::Name() const
{
	return name;
}

//***********************************************************
// 
// TakeTurn() fills the array throw by calling the function Shoot() to fill each index
// 
// Sent in: Nothing
// Sent back: Nothing
// 
//***********************************************************
void Player::TakeTurn()
{
	Throw *t = new Throw;
	for (int i = 0; i < 3; i++) {
		throws[i] = t->Shoot();
	}
}

//***********************************************************
// 
// Match() figures out which player has the highest score at
// the end of all three rounds
// 
// Sent in: implicit and p2
// Sent back: which player won or tied
// 
//***********************************************************
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

//***********************************************************
// 
// operator = makes sure each part of the Player class is
// copied over
// 
// Sent in: implicit and right
// Sent back: implicit
// 
//***********************************************************
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

//***********************************************************
// 
// operator < compares the score of two players
// 
// Sent in: left and right Player class
// Sent back: true or false
// 
//***********************************************************
bool operator<(const Player& left, const Player& right)
{
	return (left.Score() < right.Score());
}

//***********************************************************
// 
// operator << hides a call to the Display function
// 
// Sent in: Player class
// Sent back: out
// 
//***********************************************************
ostream& operator<<(ostream& out, const Player& player)
{
	player.Display(out);
	return out;
}

