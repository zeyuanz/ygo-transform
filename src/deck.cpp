/*
 * =====================================================================================
 *
 *       Filename:  deck.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/21 23:12:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <vector>
#include <iostream>
#include "../include/deck.h"

Card::Card(std::string s1, int n) {
	id = s1;
	number = n;
}

Card::Card(const Card &c) {
	id = c.id;
	number = c.number;
}

Deck::Deck(std::string f, std::string m, std::string e, std::string s) {
	format = f;
	main = m;
	extra = e;
	side = s;
}

Deck::Deck(const Deck &d) {
	format = d.format;
	main = d.main;
	extra = d.extra;
	side = d.side;
}

std::string Deck::get_cards(std::vector<Card> m, std::vector<Card> e, std::vector<Card> s) {
	std::string o_deck;
	if (format == "pro2") {
		o_deck = "#created by ygopro2\n";
		o_deck += main;
		create_deck_pro2(o_deck, m);	

		o_deck += extra;
		create_deck_pro2(o_deck, e);	

		o_deck += side;
		create_deck_pro2(o_deck, s);	
	} else if (format == "mobile") {
		o_deck = "ygo://deck";
		o_deck += main;
		create_deck_mobile(o_deck, m);	

		o_deck += extra;
		create_deck_pro2(o_deck, e);	

		o_deck += side;
		create_deck_pro2(o_deck, s);	
	} else {
		std::cout << "invalid deck format" << std::endl;
		exit(1);
	}
}

void create_deck_pro2(std::string &o_deck, std::vector<Card> c) {
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[i].get_number(); j++) {
			o_deck += c[i].get_id();
			o_deck += '\n';
		}
	}
}

void create_deck_mobile(std::string& o_deck, std::vector<Card> c) {
	for (int i = 0; i < c.size(); i++) {
		o_deck += c[i].get_id();
		o_deck += "*";
		if (c[i].get_number() != 1) {
			o_deck += c[i].get_number();
		}
		if (i != c.size()-1) {
			o_deck += "_";
		}
	}
}

void parse_pro2_deck(std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s) {
	std::vector<std::string> content_splits;
	int start = 0, end = 1;
	while (1) {
		end = content.find('\n', start);
		if (end == -1) {
			break;
		}
		content_splits.push_back(content.substr(start, end));
		start = end;
	}
}

void parse_mobile_deck(std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s) {

}
