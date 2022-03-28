#include <iostream>
using namespace std;

#include "Throw.h"
#include "Player.h"

// Throw
Throw::Throw() {
	options = 0;
}

// Player
Player::Player() {
	name = "RandomUser";
	score = 0;
	for (int i = 0; i < 3; i++) {
		throws[i] = -1;
	}
}

