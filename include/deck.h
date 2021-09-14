/*
 * =====================================================================================
 *
 *       Filename:  deck.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/21 23:15:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef DECK_H_
#define DECK_H_
#include <string>
#include <vector>
#include <map>

class Card {
	private:
		std::string id;
		int number;
	public:
		Card(std::string s1, int number);
		Card(const Card &c);
		Card() {};
		~Card() {};
		std::string get_id() {return id;}
		int get_number() {return number;}
};

class Deck {
	private:
		std::string format;
		std::string main;
		std::string extra;
		std::string side;
	public:
		Deck(std::string f, std::string m, std::string e, std::string s);
		Deck(const Deck &d);
		Deck() {};
		~Deck() {};
		void set_format(std::string f) {format = f;}
		void set_cards(std::string m, std::string e, std::string s) {main = m; extra = e; side = s;}
		std::string get_cards(std::vector<Card> m, std::vector<Card> e, std::vector<Card> s);
};

void create_deck_pro2(std::string &o_deck, std::vector<Card> c);
void create_deck_mobile(std::string &o_deck, std::vector<Card> c);

void parse_pro2_deck(std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s);
void parse_mobile_deck(std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s);
void construct_card_deck(std::vector<std::string> content_splits, int start, int end, std::map<std::string, int> &card_map_str_times, std::vector<Card> &c);

#endif