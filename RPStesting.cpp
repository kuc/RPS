#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#include "Throw.h"
#include "Player.h"


int getPlayer();
void AssignPlayer(int players, Player*& active);
void Play(Player*& active, Player*& inactive, int& PlayersRemain, int& PlayersInactive, int player);

int main() {
	// A random generator seed using time
	//unsigned seed = time(0);
	// Set the random generator seed before calling rand()
	//srand(seed);
	//int num1 = rand();

	int player;
	player = getPlayer();
	int PlayersRemain = player;
	int PlayersInactive = 0;

	Player* active = new Player[player];
	if (!active) {
		cout << "Memory not allocated" << endl;
		return 0;
	}

	Player* inactive = new Player[player];
	if (!inactive) {
		cout << "Memory not allocated" << endl;
		return 0;
	}

	AssignPlayer(player, active);

	//while (PlayersRemain > 1) {
	//	// call play function
	//}

	cout << player << endl;
	Play(active, inactive, PlayersRemain, PlayersInactive, player);

	return 0;
}



int getPlayer() {
	int temp;
	cout << "How many players do you want?: " << endl;
	cin >> temp;
	return temp;
}

void AssignPlayer(int players, Player*& active) {
	string name;
	cout << "Names for your " << players << " players: " << endl;
	for (int i = 0; i < players; i++) {
		cout << "Name " << i+1 << ": ";
		cin >> name;
		Player P(name);
		active[i] = P;
	}

}

void Play(Player*& active, Player*& inactive, int& PlayersRemain, int& PlayersInactive, int const player) {
	unsigned seed = time(0);
	srand(seed);

	int player1 = rand() % PlayersRemain;
	int player2 = rand() % PlayersRemain;

	// make sure the player is not playing themselves
	while (player1 == player2) {
		player1 = rand() % PlayersRemain;
		player2 = rand() % PlayersRemain;
	}

	active[player1].TakeTurn();
	active[player2].TakeTurn();

	//cout << active[player1] << endl;
	//cout << active[player2] << endl;

	string match = active[player1].Match(active[player2]);

	if (match == "p1") {
		cout << "Player " << active[player1].Name() << " Wins!" << endl;;
		cout << active[player1] << endl;
		PlayersInactive++;

		if (player2 < 0 || player2 >= PlayersRemain) {
			cerr << "Illegal Pos - Cannot erase" << endl;
			return;
		}
		for (int i = player2; i < PlayersRemain - 1; i++) {
			active[i] = active[i + 1];
		}

		PlayersRemain--;
		// move p2 to inactive
	}
	if (match == "p2") {
		cout << "Player " << active[player2].Name() << " Wins!" << endl;;
		cout << active[player2] << endl;
		PlayersInactive++;



		if (player1 < 0 || player1 >= PlayersRemain) {
			cerr << "Illegal Pos - Cannot erase" << endl;
			return;
		}
		for (int i = player1; i < PlayersRemain - 1; i++) {
			active[i] = active[i + 1];
		}

		PlayersRemain--;
		// move p1 to inactive
	}
	if (match == "tie") {
		cout << "Player " << active[player1].Name() << " and " << active[player2].Name() << " tied!" << endl;;
		cout << active[player1] << endl;
		cout << active[player2] << endl;
		// dont move anyone to inactive
	}
}
