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
	main_title = m;
	extra_title = e;
	side_title = s;
}

Deck::Deck(const Deck &d) {
	format = d.format;
	main_title = d.main_title;
	extra_title = d.extra_title;
	side_title = d.side_title;
}

// format separate main deck, extra deck and side deck into output_deck
std::string Deck::output_deck(std::vector<Card> m, std::vector<Card> e, std::vector<Card> s) {
	std::string o_deck;
	if (format == "mobile") {
		o_deck = "#created by ygopro2\n";
		o_deck += main_title;
		create_deck_pro2(o_deck, m);	

		o_deck += extra_title;
		create_deck_pro2(o_deck, e);	

		o_deck += side_title;
		create_deck_pro2(o_deck, s);	
		o_deck = o_deck.substr(0, o_deck.size()-1); // remove final '\n'
	} else if (format == "pro2") {
		o_deck = "ygo://deck";
		o_deck += main_title;
		create_deck_mobile(o_deck, m);	

		o_deck += extra_title;
		create_deck_mobile(o_deck, e);	

		o_deck += side_title;
		create_deck_mobile(o_deck, s);	
	} else {
		std::cout << "invalid deck format" << std::endl;
		exit(1);
	}
	return o_deck;
}

// create cards for pro2 format
void create_deck_pro2(std::string &o_deck, std::vector<Card> c) {
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[i].get_number(); j++) {
			o_deck += c[i].get_id();
			o_deck += '\n';
		}
	}
}

// create cards for mobile format
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

// parse pro2 deck from content to main deck, extra deck and side deck
void parse_pro2_deck(const std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s) {
	int start = 0, end = 1, count = 0;
	int m_start, m_end, e_start, e_end, s_start;
	std::map<std::string, int>  card_map_str_times;
	std::vector<std::string> content_splits;
	while (1) {
		end = content.find('\n', start);
		if (end == -1) {
			end = content.size();
			std::string substr = content.substr(start, end-start);
			content_splits.push_back(substr);
			break;
		}
		std::string substr = content.substr(start, end-start);
		if (substr == "#main") {m_start = count+1;}
		if (substr == "#extra") {e_start = count+1; m_end = count;}
		if (substr == "!side") {s_start = count+1; e_end = count;}
		content_splits.push_back(substr);
		count++;
		end++;
		start = end;
	}
	construct_card_deck_pro2(content_splits, m_start, m_end, card_map_str_times, m);
	construct_card_deck_pro2(content_splits, e_start, e_end, card_map_str_times, e);
	construct_card_deck_pro2(content_splits, s_start, content_splits.size(), card_map_str_times, s);
}

// construct pro2 deck into content_splits
void construct_card_deck_pro2(std::vector<std::string> content_splits, int start, int end, std::map<std::string, int> &card_id2times, std::vector<Card> &c) {
	card_id2times.clear(); // clear map to store cards of new category
	for (int i = start; i < end; i++) {
		card_id2times[content_splits[i]]++;
	}
	for (std::map<std::string, int>::iterator it = card_id2times.begin(); it != card_id2times.end(); it++) {
		if (it->first.size() == 0) {
			continue;
		}
		c.push_back(Card(it->first, it->second));
	}
}	

// parse mobile deck from content to main deck, extra deck and side deck
void parse_mobile_deck(std::string content, std::vector<Card> &m, std::vector<Card> &e, std::vector<Card> &s) {
	int start = content.find("main=") + 5;
	int end = content.find("&extra=");
	construct_card_deck_mobile(content.substr(start, end-start), m);

	start = end+7;
	end = content.find("&side=");
	construct_card_deck_mobile(content.substr(start, end-start), e);

	start = end+6;
	construct_card_deck_mobile(content.substr(start), s);
}

// construct mobile deck into content_splites
void construct_card_deck_mobile(std::string content, std::vector<Card> &c) {
	int start = 0, end = 0;
	bool continue_flag = true;
	while (continue_flag) {
		end = content.find('_', start);
		if (end == -1) {
			continue_flag = false;
			end = content.size();
		}
		std::string card_tmp = content.substr(start, end-start);
		if (card_tmp.size() == 0) {
			continue;
		}
		int times;
		if (card_tmp.find('*') == -1) { 
			times = 1; 
		} else { 
			if (card_tmp.find('\n') != -1) {card_tmp = card_tmp.substr(0, card_tmp.size()-1);}
			times = card_tmp[card_tmp.size()-1] - '0'; 
			card_tmp = card_tmp.substr(0, card_tmp.size()-2);
		}
		c.push_back(Card(card_tmp, times));
		end++;
		start = end;
	}
}

void indeck_to_cards(Deck *d, std::string content, std::vector<Card> &main_cards, std::vector<Card> &extra_cards, std::vector<Card> &side_cards) {
    if (content[0] == '#') {
		// set deck format to pro2
        d->set_format("pro2");
		// set title of transformed deck (i.e. title of mobile)
        d->set_trans_title("?main=", "&extra=", "&side=");
		// parse content to main, extra and side
        parse_pro2_deck(content, main_cards, extra_cards, side_cards);
    } else {
		// set deck format to mobile 
        d->set_format("mobile");
		// set title of transformed deck (i.e. title of pro2)
        d->set_trans_title("#main\n", "#extra\n", "!side\n");
		// parse content to main, extra and side
        parse_mobile_deck(content, main_cards, extra_cards, side_cards);
    }
}
