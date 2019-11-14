#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class Player {

private:

	string playerName;
	string playerBoard[28][11];
	int playerMoney, playerLocation;
	bool inJail, isBankrupt;

public:

	Player(string strParameter);

	void setBoard(string arrayParameter[28][11]);
	void getBoard(string arrayParameter[28][11]);

	void playerDice();
	void playerMove(int intParameter);
	void playerTurn(int intParameter);
	void isJail();
	void getProperty(int intParameter);
	int getPrice(int intParameter);
	void isAvailable(int intParameter);
	void isOwned(int intParameter);
	void getInformation();
	void setInformation(int intParameter);
	bool getBankrupt();

	int getMoney();
	string getName();

};