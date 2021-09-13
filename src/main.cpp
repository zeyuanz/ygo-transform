#include "../include/deck.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    string file = argv[1]; //obtain the name of file
    string content, o_deck;
    vector<Card> m, e, s;
    Deck d;
    ifstream fd_in(file);    
    fd_in >> content;
    fd_in.close();

    if (content[0] == '#') {
        d.set_format("pro2");
        d.set_cards("#main\n", "#extra\n", "!side\n");
        parse_pro2_deck(content, m, e, s);
    } else if (content[0] == 'y') {
        d.set_format("mobile");
        d.set_cards("=?main", "=&extra", "=&side");
        parse_mobile_deck(content, m, e, s);
    } else {
        cout << "invalid format.\n";
        exit(1);
    }

    o_deck = d.get_cards(m, e, s);

    ofstream fd_out(file);
    fd_out << o_deck;
    fd_out.close();
    return 0;
}