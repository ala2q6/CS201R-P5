#include "player.h""

Player::Player(string strParameter) {

	playerName = strParameter;
	playerMoney = 1300;
	playerLocation = 0;
	inJail = false;

}

void Player::setBoard(string arrayParameter[28][11]) {

	for (int i = 0; i < 28; i++) {

		for (int j = 0; j < 11; j++) {

			playerBoard[i][j] = arrayParameter[i][j];

		}

	}

}

void Player::getBoard(string arrayParameter[28][11]) {

	for (int r = 0; r < 28; r++) {

		for (int c = 0; c < 11; c++) {

			arrayParameter[r][c] = playerBoard[r][c];

		}

	}

}

void Player::playerDice() {

	int intVariable = 0;
	while (true) {

		int intVariable1 = 1 + (rand() % 6);
		int intVariable2 = 1 + (rand() % 6);

		if (intVariable1 == intVariable2) {

			cout << "Dice : " << intVariable1 + intVariable2;
			cout << "\nOh! You rolled a double!\n";

			if (intVariable == 3) {

				cout << "Uh oh! You rolled three doubles!\nYou have gone to jail!\n";
				inJail = true;
				break;

			}

			else {

				playerMove(intVariable1 + intVariable2);
				playerTurn(intVariable1 + intVariable2);
				intVariable += 1;

			}

		}

		else {

			cout << "Dice : " << intVariable1 + intVariable2;
			cout << "\nYou did not roll doubles.\n";

			playerMove(intVariable1 + intVariable2);
			playerTurn(intVariable1 + intVariable2);
			break;

		}

	}

}

void Player::playerMove(int intParameter) {

	intParameter += playerLocation;
	for (playerLocation; playerLocation <= intParameter; playerLocation++) {

		if (playerLocation % 28 == 0) {

			playerLocation = 0;
			playerMoney += 200;

		}

		else {

			playerLocation += 1;

		}

	}

}

void Player::playerTurn(int intParameter) {

	isJail();
	getProperty(intParameter);
	isAvailable(intParameter);
	isOwned(intParameter);
	getInformation();

}

void Player::isJail() { // thank you Ben for the idea

	if (inJail == true) {

		cout << "\nYou were in jail.\nYou bribed that guy over there $50 to let you out.\n";
		cout << "<Press Enter to Leave Jail>\n";

		string strVariable;
		getline(cin, strVariable);

	}

}

void Player::getProperty(int intParameter) {

	cout << "You have landed on" << playerBoard[intParameter][7] << endl << endl;
	cout << "Owner : " << playerBoard[intParameter][8] << endl;
	cout << "House : " << playerBoard[intParameter][9] << endl;
	cout << "Hotel : " << playerBoard[intParameter][10] << endl << endl;

}

int Player::getPrice(int intParameter) {

	if (playerBoard[intParameter][10] == "1") {

		return stoi(playerBoard[intParameter][10]) / 4;

	}

	else if (playerBoard[intParameter][9] != "0") {

		return stoi(playerBoard[intParameter][9]) * stoi(playerBoard[intParameter][1]);

	}

	else {

		return stoi(playerBoard[intParameter][1]);

	}

}

void Player::isAvailable(int intParameter) {

	if (playerBoard[intParameter][8] == "0") {

		string strVariable;
		cout << playerBoard[intParameter][7] << " is available.\n";
		cout << playerBoard[intParameter][7] << " is valued at $" << playerBoard[intParameter][0] << ".\n";
		while (true) {

			cout << "\n Would you like to purchase this property? [ Y - N ] : ";
			cin >> strVariable;

			if ((strVariable == "Y") || (strVariable == "y")) {

				int intVariable = stoi(playerBoard[intParameter][0]);

				if (playerMoney >= intVariable) {

					playerBoard[intParameter][8] = playerName;
					playerMoney -= intVariable;
					break;

				}

				else {

					cout << " You cannot afford this property!\n";
					break;

				}

			}

			else if ((strVariable == "N") || (strVariable == "n")) {

				cout << " You missed out! Maybe next time.\n\n";
				break;

			}

			else {

				cout << "\n Input is invalid.\n";

			}

		}

	}

}

void Player::isOwned(int intParameter) {

	if (playerBoard[intParameter][8] != "0") {

		if (playerBoard[intParameter][8] != playerName) {

			string strVariable;
			int intVariable = getPrice(intParameter);
			cout << " This property has already been purchased by : " << playerBoard[intParameter][8] << endl;
			cout << " You owe : $" << intVariable << "\n\n<Press Enter to pay rent>\n";
			getline(cin, strVariable);
			playerMoney -= intVariable;

		}

		else {

			cout << " You own" << playerBoard[intParameter][7] << "\n\n";

		}

	}

}

void Player::getInformation() {

	vector<int> vectorVariable;
	for (int r = 0; r < 28; r++) {

		if (playerBoard[r][8] == playerName) {

			vectorVariable.push_back(r);

		}

	}

	if (vectorVariable.size() != 0) {

		cout << "Would you like to purchase a house/hotel for :\n\n";//

		while (true) {

			int intVariable = 0;
			for (int r = 0; r < vectorVariable.size(); r++) {

				cout << r + 1 << ". " << playerBoard[vectorVariable.at(r)][7] << endl;
				intVariable += 1;

			}

			cout << "\n<Enter X to Exit>\n\nInput : ";

			string strVariable;
			cin >> strVariable;
			cout << endl;

			if (strVariable == "X") {

				break;

			}

			else {

				if ((stoi(strVariable) >= 1) && (stoi(strVariable) <= intVariable)) {

					setInformation(vectorVariable[stoi(strVariable) - 1]);
					break;

				}

				else {

					cout << "Input is invalid.\n\n";

				}

			}

		}

	}

}

void Player::setInformation(int intParameter) {

	while (true) {

		if (playerBoard[intParameter][9] == "4") {

			while (true) {

				cout << "1. 1H : $" << playerBoard[intParameter][10] << endl;
				cout << "\n<Enter X to Exit>\n\nInput : ";

				string strVariable;
				cin >> strVariable;
				cout << endl;

				if (strVariable == "X") {

					break;

				}

				else {

					if (strVariable == "1") {

						int intVariable = stoi(playerBoard[intParameter][10]);
						
						if (playerMoney >= intVariable) {

							cout << "Your hotel was purchased for" << playerBoard[intParameter][7] << endl;
							playerMoney -= intVariable;
							break;

						}

						else {

							cout << "\nYou cannot afford this!\n";
							break;

						}

					}

					else {

						cout << "Input is invalid.\n\n";

					}

				}

			}

		}

		else {

			while (true) {

				int intVariable = stoi(playerBoard[intParameter][9]);
				
				if (intVariable == 0) { intVariable = 1; }

				int i = 1;
				for (intVariable; intVariable < 5; intVariable++) {

					cout << i << ". " << intVariable << "h : " << playerBoard[intParameter][intVariable + 1] << endl;
					i += 1;

				}

				cout << "\n<Enter X to Exit>\n\nInput : ";

				string strVariable;
				cin >> strVariable;
				cout << endl;

				if (strVariable == "X") {

					break;

				}

				else {

					if ((i >= 1) && (i <= 5)) {

						int intVariable = stoi(playerBoard[intParameter][i + 1]);

						if (playerMoney >= intVariable) {

							cout << "Your house(s) was/were purchased for" << playerBoard[intParameter][7] << endl;
							playerMoney -= intVariable;
							break;

						}

						else {

							cout << "\nYou cannot afford this!\n";
							break;

						}

					}

					else {

						cout << "\nInput is invalid.\n";

					}

				}

			}

		}

		break;

	}

}

bool Player::getBankrupt() {

	if (playerMoney < 0) {

		return isBankrupt = true;

	}

}

int Player::getMoney() {

	return playerMoney;

}

string Player::getName() {

	return playerName;

}