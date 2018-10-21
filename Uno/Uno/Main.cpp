#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Header.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int playerCardArrayValue[4][108];
string playerCardNumber[4][108];

int main() {
	int replay = 0;

	do {
		//Set All Cards as Playable
		for (int i = 0; i < 108; i++)
			playedDeckCards[i] = 0;


		//Randomize first player, choose a first card, and distribute the rest
		int firstPlayerInt = firstPlayer();
		firstCard();
		distributeCards();
		setColor("w");
		cout << "You are player 4." << endl;
		cout << "The random first player is player " << firstPlayerInt + 1 << endl;
		sleep_for(seconds(2));


		//Loop for all players to repeat
		for (int currentPlayer = firstPlayerInt; currentPlayer < 4; currentPlayer++) {
			setColor("w");
			cout << "\n\n\nIt is player " << currentPlayer + 1 << "'s turn. " << endl;
			currentCard();
			if (currentPlayer == 3) {
				//Display current card, hand, then let user choose a card
				displayHand(currentPlayer);
				chooseACard(currentPlayer);
				currentPlayer = -1;
			}
			else {
				computerGuess(currentPlayer);
				sleep_for(seconds(3));
			}
		}
		//Ask for Repeat Gameplay
		cout << "Would you like to play again?\n1 - Yes\n2 - No" << endl;
		cin >> replay;
	} while (replay != 2);

	system("pause");
	return 0;
}