/*
	Alex, Emily, Justin, McKenzie
	Program 5
	14 November 2019
*/

#include "player.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

	srand(time(0));

	int r = 0, c = 0;
	string strVariable;
	string arrayVariable[28][11];
	ifstream fileIn("board.txt");
	while (fileIn.good()) {

		for (c = 0; c < 7; c++) {

			fileIn >> strVariable;
			arrayVariable[r][c] = strVariable;

		}

		for (c = 7; c < 11; c++) {

			arrayVariable[r][c] = "0";

		}

		getline(fileIn, strVariable);
		arrayVariable[r][7] = strVariable;
		r += 1;

	}

	cout << "Welcome to Monopoly.\nNumber of players : ";

	int intVariable;
	cin >> intVariable;
	cout << endl;

	vector<Player*> vectorVariable;
	for (int i = 1; i <= intVariable; i++) {

		cout << "Player " << i << " : ";

		string strVariable;
		cin >> strVariable;

		vectorVariable.push_back(new Player(strVariable));

	}

	while (true) {

		for (int i = 0; i < vectorVariable.size(); i++) {

			// here we need to associate the 2D array to all players
			// can't figure it out right now, too tired
			// all players need to have the same arrayVariable ( the procedure above )
			// it's just a matter of doing it.
			// modify get/set board members

			// I think that the best option is to convert this 2D array to vector<vector<int>> kind of stuff,

			vectorVariable.at(i)->playerDice();
			bool boolVariable = vectorVariable.at(i)->getBankrupt();

			if (boolVariable == true) {

				for (int j = 0; j < vectorVariable.size(); j++) {

					cout << vectorVariable.at(j)->getName()<< "\t$" << vectorVariable.at(j)->getMoney() << endl;

				}

				break;

			}

		}

	}

	return 0;

}