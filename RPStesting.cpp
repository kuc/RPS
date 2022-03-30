#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#include "Throw.h"
#include "Player.h"


int getPlayer();
void AssignPlayer(int players, Player& active);

int main() {
	// A random generator seed using time
	unsigned seed = time(0);
	// Set the random generator seed before calling rand()
	srand(seed);
	int num1 = rand();

	int player;
	player = getPlayer();

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

	return 0;
}



int getPlayer() {
	int temp;
	cout << "How many players do you want?: " << endl;
	cin >> temp;
	return temp;
}

void AssignPlayer(int players, Player& active) {
	string name;
	cout << "Names for your " << players << " players: " << endl;
	for (int i = 0; i < players; i++) {
		cout << "Name " << i << ":" << endl;
		cin >> name;
		
	}

}