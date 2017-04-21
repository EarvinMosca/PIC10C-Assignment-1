/* *************************************
Earvin Mosca
April 21, 2017

The program runs the game "Siete y Medio"
and records the rounds played in
"gamelog.txt".

************************************* */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"
using namespace std;


// Global constants (if any)


// Non member functions declarations.
void playGame(int b, Player &p, Player &d);

// Non member functions implementations.
void playGame(int b, Player &p, Player &d, int g) {
	string hit;
	Hand player1;
	ofstream fout;

	fout.open("gamelog.txt", ios::app);

	player1.draw_card();
	cout << "Your cards:" << endl;
	player1.print_hand();
	cout << endl;
	cout << "Your total is " << player1.sum() << ". " << "Do you want another card?(y/n)";
	cin >> hit;

	fout << "-----------------------------------------------" << endl
		<< endl << "Game number: " << g << setw(17) << "Money Left: $" << p.get_money()
		<< endl << "Bet: " << b << endl << endl
		<< "Your Cards:" << endl;

	while (hit == "y") {
		cout << "New card:" << endl;
		player1.draw_card();
		player1.get_card(player1.get_handSize() - 1).print_card();
		cout << endl << endl;
		player1.sort_hand();
		cout << "Your cards:" << endl;
		player1.print_hand();
		cout << endl;
		cout << "Your total is " << player1.sum() << ". " << "Do you want another card?(y/n)";
		cin >> hit;
	}

	Hand dealer;
	dealer.draw_card();

	cout << "Dealer's cards:" << endl;
	dealer.print_hand();
	cout << "Dealer's total is " << dealer.sum() << "." << endl;

	while (dealer.sum() < 5.5){
		dealer.draw_card();
		cout << "New card:" << endl;
		dealer.get_card(dealer.get_handSize() - 1).print_card();
		cout << endl << endl;
		dealer.sort_hand();
		cout << "Dealer's cards:" << endl;
		dealer.print_hand();
		cout << "Dealer's total is " << dealer.sum() << "." << endl;

	}


	if (player1.sum() > dealer.sum() && player1.sum() <= 7.5){
		cout << "You win " << b << "." << endl;
		p.win_bet(b);
		d.lose_bet(b);
	}
	else if (dealer.sum() > 7.5 && player1.sum() <= 7.5) {
		cout << "You win " << b << "." << endl;
		p.win_bet(b);
		d.lose_bet(b);
	}
	else if (player1.sum() < dealer.sum() && dealer.sum() <= 7.5){
		cout << endl << "Too bad. You lose " << b << "." << endl;
		p.lose_bet(b);
	}
	else if (player1.sum() > 7.5 && dealer.sum() <= 7.5) {
		cout << endl << "Too bad. You lose " << b << "." << endl;
		p.lose_bet(b);
	}
	else if (player1.sum() == dealer.sum() && player1.sum() <= 7.5) {
		cout << endl;
		cout << "Nobody wins." << endl;
	}
	else {
		cout << endl << "Too bad. You lose " << b << "." << endl;
		p.lose_bet(b);
	}


	player1.fileprint_hand("gamelog.txt");
	fout << "Your total: " << player1.sum() << "." << endl << endl;
	fout << "Dealer's cards: " << endl;
	dealer.fileprint_hand("gamelog.txt");
	fout << "Dealer's total is " << dealer.sum() << "." << endl << endl;

	fout.close();
}

// Stub for main
int main(){
	Player player1(100);
	Player dealer(900);
	int bet;
	int gameRound = 1;
	
	srand( static_cast<int>( time(0) ));

	while (player1.get_money() > 0 && dealer.get_money() > 0){
		cout << "You have $" << player1.get_money() << "." << " Enter bet: ";
		cin >> bet;
		if (bet <= player1.get_money())
			playGame(bet, player1, dealer, gameRound);
		else
			cout << "You do not have the money to bet that much." << endl;
		gameRound++;
	}



	return 0;
}
