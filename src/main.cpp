#include "../include/deck.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	if (argc == 1 || string(argv[1])=="-h") {
		cout << "Usage	ygodeck [source_file] [dest_file]\n";
		cout << "Program options:\n";
		cout << "	-h	--print this message\n";
		return 0;
	}
    string infile = argv[1]; //obtain the name of file
    string outfile = "stdin";
    if (argc >= 3) {
        outfile = argv[2];
    }
    vector<Card> m, e, s;
    Deck d;
    ifstream fd_in(infile);    
    string content( (istreambuf_iterator<char>(fd_in)),
                       (istreambuf_iterator<char>()    ));
    fd_in.close();
    if (content[0] == '#') {
        d.set_format("pro2");
        d.set_cards("?main=", "&extra=", "&side=");
        parse_pro2_deck(content, m, e, s);
    } else {
        d.set_format("mobile");
        d.set_cards("#main\n", "#extra\n", "!side\n");
        parse_mobile_deck(content, m, e, s);
    }
    string o_deck = d.get_cards(m, e, s);
    if (outfile == "stdin") {
        cout << o_deck << endl;
    } else {
        ofstream fd_out(outfile);
        fd_out << o_deck << endl;
        fd_out.close();
    }
    return 0;
}
