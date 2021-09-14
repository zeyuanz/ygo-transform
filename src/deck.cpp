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
#include <map>
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
	if (format == "mobile") {
		o_deck = "#created by ygopro2\n";
		o_deck += main;
		create_deck_pro2(o_deck, m);	

		o_deck += extra;
		create_deck_pro2(o_deck, e);	

		o_deck += side;
		create_deck_pro2(o_deck, s);	
	} else if (format == "pro2") {
		o_deck = "ygo://deck";
		o_deck += main;
		create_deck_mobile(o_deck, m);	

		o_deck += extra;
		create_deck_mobile(o_deck, e);	

		o_deck += side;
		create_deck_mobile(o_deck, s);	
	} else {
		std::cout << "invalid deck format" << std::endl;
		exit(1);
	}
	return o_deck;
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
		if (c[i].get_number() != 1) {
			o_deck += "*";
			o_deck += std::to_string(c[i].get_number());
		}
		if (i != c.size()-1) {
			o_deck += "_";
		}
	}
}

void parse_pro2_deck(const std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s) {
	int start = 0, end = 1, count = 0;
	int m_start, m_end, e_start, e_end, s_start;
	std::map<std::string, int>  card_map_str_times;
	std::vector<std::string> content_splits;
	while (end < content.size()) {
		end = content.find('\n', start);
		if (end == -1) {
			break;
		}
		std::string substr = content.substr(start, end-start);
		if (substr == "#main") {m_start = count+1;}
		if (substr == "#extra") {e_start = count+1; m_end = count;}
		if (substr == "!side") {s_start = count+1;}
		content_splits.push_back(substr);
		count++;
		end++;
		start = end;
	}
	construct_card_deck(content_splits, m_start, m_end, card_map_str_times, m);
	construct_card_deck(content_splits, e_start, e_end, card_map_str_times, e);
	construct_card_deck(content_splits, s_start, content_splits.size(), card_map_str_times, s);
}

void construct_card_deck(std::vector<std::string> content_splits, int start, int end, std::map<std::string, int> &card_map_str_times, std::vector<Card> &c) {
	card_map_str_times.clear(); // clear map to store cards of new category
	for (int i = start; i < end; i++) {
		card_map_str_times[content_splits[i]]++;
	}
	for (std::map<std::string, int>::iterator it = card_map_str_times.begin(); it != card_map_str_times.end(); it++) {
		c.push_back(Card(it->first, it->second));
	}
}	

void parse_mobile_deck(std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s) {

}
