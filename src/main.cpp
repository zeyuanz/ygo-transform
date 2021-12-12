#include "../include/deck.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	// print usage of the prog
	if (argc == 1 || string(argv[1])=="-h") {
		cout << "Usage	ygodeck [source_file] [dest_file]\n";
		cout << "Program options:\n";
		cout << "	-h	--print this message\n";
		return 0;
	}
	/* arg parser */
    string infile = argv[1]; //obtain the name of file
    string outfile = "stdin";
    if (argc >= 3) {
        outfile = argv[2];
    }
	/* arg parser */

    vector<Card> main_cards, extra_cards, side_cards;
    Deck d;
	// copy fd_in string to content
    ifstream fd_in(infile);    
    string content( (istreambuf_iterator<char>(fd_in)),
                       (istreambuf_iterator<char>()    ));
    fd_in.close();

	// if content start with #, then it is a pro2 format deck
    if (content[0] == '#') {
		// set deck format to pro2
        d.set_format("pro2");
		// set title of transformed deck (i.e. title of mobile)
        d.set_trans_title("?main=", "&extra=", "&side=");
		// parse content to main, extra and side
        parse_pro2_deck(content, main_cards, extra_cards, side_cards);
    } else {
		// set deck format to mobile 
        d.set_format("mobile");
		// set title of transformed deck (i.e. title of pro2)
        d.set_trans_title("#main\n", "#extra\n", "!side\n");
		// parse content to main, extra and side
        parse_mobile_deck(content, main_cards, extra_cards, side_cards);
    }
	// output deck to o_deck
    string o_deck = d.output_deck(main_cards, extra_cards, side_cards);

	// strean output deck to ofstream
    if (outfile == "stdin") {
        cout << o_deck << endl;
    } else {
        ofstream fd_out(outfile);
        fd_out << o_deck << endl;
        fd_out.close();
    }
    return 0;
}
