/* 
   Rock Paper Scissors

   Programmer: Kuc

   Purpose: This program is a game of rock, paper, scissors. It will ask the user
   how many players there will be and to name them. It will play as many rounds
   as it needs to until there is only one player left. At the end it will display
   the winner which is the player who has the highest score. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#include "Throw.h"
#include "Player.h"


int getPlayer();
void AssignPlayer(int players, Player*& active);
void Play(Player*& active, Player*& inactive, int& PlayersRemain, int& PlayersInactive, int& round);
void ScoreMe(Player* active, Player* inactive, int PlayersInactive);

int main() {

	int player;
	player = getPlayer();
	int PlayersRemain = player;
	int PlayersInactive = 0;
	int whatround = 1; 

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

	while (PlayersRemain > 1) {
		Play(active, inactive, PlayersRemain, PlayersInactive, whatround);
	}

	ScoreMe(active, inactive, PlayersInactive);

	cout << "Press Any Key to Continue..." << endl;
	exit(0);
	return 0;
}



int getPlayer() {
	int temp;
	bool valid = false;
	// make sure integer is inputted
	while (!valid) {
		cout << "How many players do you want?: ";
		cin >> temp;
		if (cin.fail()) {
			cout << "Wrong input!" << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else
			valid = true;
	}
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

void Play(Player*& active, Player*& inactive, int& PlayersRemain, int& PlayersInactive, int& round) {
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

	cout << "********** Round " << round << " **********" << endl;

	string match = active[player1].Match(active[player2]);

	if (match == "p1") {
		cout << "Player " << active[player1].Name() << " Wins!" << endl << endl;
		cout << active[player1] << endl;
		cout << active[player2] << endl;
		PlayersInactive++;

		if (PlayersRemain > 1) {
			inactive[PlayersInactive - 1] = active[player2];
		}

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
		cout << "Player " << active[player2].Name() << " Wins!" << endl << endl;
		cout << active[player1] << endl;
		cout << active[player2] << endl;
		PlayersInactive++;

		if (PlayersRemain > 1) {
			inactive[PlayersInactive - 1] = active[player1];
		}

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
		cout << "Player " << active[player1].Name() << " and " << active[player2].Name() << " tied!" << endl << endl;
		cout << active[player1] << endl;
		cout << active[player2] << endl;
		// dont move anyone to inactive
	}

	round++;
}

void ScoreMe(Player* active, Player* inactive, int PlayersInactive) {
	string maxname = active[0].Name();
	int maxscore = active[0].Score();

	for (int i = 0; i < PlayersInactive; i++) {
		if (inactive[i].Score() > maxscore) {
			maxscore = inactive[i].Score();
			maxname = inactive[i].Name();
		}
	}

	cout << "The winner with a score of " << maxscore << " is " << maxname << endl;
}
