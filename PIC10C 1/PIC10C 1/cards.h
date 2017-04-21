/* *************************************
Earvin Mosca
April 21, 2017

Interface of Card class, Hand class, and
Player class.
************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {
public:
	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors 
	string get_spanish_suit() const;
	string get_spanish_rank() const;
	string get_spanish_card_name()const;

	/*
	These are the only functions you'll need to code
	for this class. See the implementations of the two
	functions above to get an idea of how to proceed.
	*/
	string get_english_suit() const;
	string get_english_rank() const;
	string get_english_card_name() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;

	//Prints out the card.
	void print_card() const;

	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1. 
	// Useful if you want to sort the cards.
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};


class Hand {
public:
	// A vector of Cards
	//Constructors
	Hand();

	//Accessors
	double sum() const;
	void print_hand() const;
	Card get_card(int position) const;
	int get_handSize() const;
	void fileprint_hand(string name) const;

	//Mutators
	void draw_card();
	void reset_hand();
	void sort_hand();

private:

	vector<Card> cards;
};


class Player {
public:
	// Constructor. 
	//    Assigns initial amount of money
	Player(int m);

	//Accessors
	int get_money() const;

	//Mutators
	void lose_bet(int b);
	void win_bet(int b);



private:
	int money;
	
};

#endif