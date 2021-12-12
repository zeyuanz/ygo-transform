/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/21 20:28:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../include/deck.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

void construct_map(map<string, int> &id2number, vector<Card> c);
void comp_cards(vector<Card> c1, vector<Card> c2, string msg);
bool comp_map(map<string, int> id2number1, map<string, int>id2number2);


int main(int argc, char** argv) {
	string f1= argv[1];
	string f2= argv[2];

	vector<Card> m1, m2, e1, e2, s1, s2;
	Deck d1, d2;

    ifstream fd1_in(f1);    
    string content1( (istreambuf_iterator<char>(fd1_in)),
                       (istreambuf_iterator<char>()    ));
    ifstream fd2_in(f2);    
    string content2( (istreambuf_iterator<char>(fd2_in)),
                       (istreambuf_iterator<char>()    ));
	fd1_in.close();
	fd2_in.close();
	indeck_to_cards(&d1, content1, m1, e1, s1);
	indeck_to_cards(&d2, content2, m2, e2, s2);
	
	comp_cards(m1, m2, "main deck");
	comp_cards(e1, e2, "extra deck");
	comp_cards(s1, s2, "side deck");
	return 0;
}
void comp_cards(vector<Card> c1, vector<Card> c2, string msg) {
	map<string, int> id2number1, id2number2;	
	construct_map(id2number1, c1);
	construct_map(id2number2, c2);
	bool equal = comp_map(id2number1, id2number2);
	if(equal) {cout << msg << " equal" << endl;}
	else {cout << msg << " not equal" << endl;}
}

void construct_map(map<string, int> &id2number, vector<Card> c) {
	for (size_t i = 0; i < c.size(); i++) {
		id2number[c[i].get_id()] = c[i].get_number();
	}
}

bool comp_map(map<string, int> id2number1, map<string, int>id2number2) {
	if (id2number1.size() != id2number2.size()) {
		cout << "[size1]: " <<id2number1.size()<<"\t[size2]: " <<id2number2.size()<<endl;
		return false;
	}

	auto it1 = id2number1.begin();
	auto it2 = id2number2.begin();
	for (;it1 != id2number1.end();it1++, it2++) {
		if (it1->first != it2->first || it1->second != it2->second) {
			cout << "[key]: " <<it1->first <<"\t[value]: " << it1->second <<endl;
			cout << "[key]: " <<it2->first <<"\t[value]: " << it2->second <<endl;
			return false;
		}
	}
	return true;
}
