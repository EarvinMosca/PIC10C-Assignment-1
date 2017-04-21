/* *************************************
Earvin Mosca
April 21, 2017

Implementation of Card class,
Hand class,and Player class.
************************************* */

#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>



/* *************************************************
Card class
************************************************* */

/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card(){
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}

string Card::get_spanish_card_name() const{
	string spanishCardName = get_spanish_rank() + " de " + get_spanish_suit();
	return spanishCardName;

}
// Accessor: returns a string with the suit of the card in English 

string Card::get_english_suit() const {

	string englishSuitName;
	switch (suit) {
	case OROS:
		englishSuitName = "coins";
		break;
	case COPAS:
		englishSuitName = "cups";
		break;
	case ESPADAS:
		englishSuitName = "spades";
		break;
	case BASTOS:
		englishSuitName = "clubs";
		break;
	default: break;
	}
	return englishSuitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string englishRankName;
	switch (rank) {
	case AS:
		englishRankName = "Ace";
		break;
	case DOS:
		englishRankName = "Two";
		break;
	case TRES:
		englishRankName = "Three";
		break;
	case CUATRO:
		englishRankName = "Four";
		break;
	case CINCO:
		englishRankName = "Five";
		break;
	case SEIS:
		englishRankName = "Six";
		break;
	case SIETE:
		englishRankName = "Seven";
		break;
	case SOTA:
		englishRankName = "Jack";
		break;
	case CABALLO:
		englishRankName = "Knight";
		break;
	case REY:
		englishRankName = "King";
		break;
	default: break;
	}
	return englishRankName;
}

string Card::get_english_card_name() const{
	string englishCardName = get_english_rank() + " of " + get_english_suit();
	return englishCardName;

}


// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank)+1;
}

//Prints out the card.
void Card::print_card() const{
	cout << setw(get_spanish_card_name().length() + 7) << get_spanish_card_name();

	cout << setw(7) << "(" << setw(get_english_card_name().length()) << get_english_card_name() << ")." << endl;

	return;
}


// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */
Hand::Hand() {
	vector<Card> cards(0);
}

//Keeps track of the total value of the hand(keeping track of the fact that King,Knight, and Jack are half points each).
double Hand::sum() const{
	double sum = 0;
	double value = 0;
	for (int i = 0; i < cards.size(); i++){
		cards[i].get_rank();
		if (cards[i].get_rank() == 10 || cards[i].get_rank() == 11 || cards[i].get_rank() == 12)
			value = 0.5;
		else
			value = (double)cards[i].get_rank();

		sum += value;
	}

	return sum;
}

void Hand::print_hand() const{
	string longestCardName = " ";
	int longWordLength = longestCardName.length();

	for (int i = 0; i < cards.size(); i++){
		if (cards[i].get_spanish_card_name().length()>longWordLength)
			longestCardName = cards[i].get_spanish_card_name();
		longWordLength = longestCardName.length();
	}

	for (int i = 0; i<cards.size(); i++)

		cout << setw(7) << " " << setw(longWordLength) << right << cards[i].get_spanish_card_name()
		<< setw(7) << "(" << cards[i].get_english_card_name() << ")." << endl;



	return;
}

void Hand::fileprint_hand(string name) const{
	ofstream fout;
	fout.open(name.c_str(), ios::app);


	string longestCardName = " ";
	int longWordLength = longestCardName.length();

	for (int i = 0; i < cards.size(); i++){
		if (cards[i].get_spanish_card_name().length()>longWordLength)
			longestCardName = cards[i].get_spanish_card_name();
		longWordLength = longestCardName.length();
	}

	for (int i = 0; i<cards.size(); i++)

		fout << setw(7) << " " << setw(longWordLength) << right << cards[i].get_spanish_card_name()
		<< setw(7) << "(" << cards[i].get_english_card_name() << ")." << endl;

	fout.close();

	return;
}

//Gets a card from the vector cards.
Card Hand::get_card(int position) const {
	return cards[position];
}

//Gets the size of the hand.
int Hand::get_handSize() const {
	return cards.size();
}

//Sorts the cards in the hand by rank(suit is irrelevant).
void Hand::sort_hand() {
	sort(cards.begin(), cards.end());
}

//Adds a new(random) card to the hand.
void Hand::draw_card() {
	Card newCard;
	cards.push_back(newCard);
	return;
}

//Resets the hand to 0. Use at end of rounds.
void Hand::reset_hand() {
	cards.resize(0);
	return;
}




/* *************************************************
Player class
************************************************* */
// Implemente the member functions of the Player class here.
