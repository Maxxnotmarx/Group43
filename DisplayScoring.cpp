#include<iostream>
#include<vector>
#include<string>
#include "gp.h"

using namespace std;

void display_Scoring( string word, vector< string > output, int times, char guess_blank[], vector< char > wrong_letter ) {
	if ( times == 1 ) {
		output[2] = "||     0                            ";
	}
	else if ( times == 2 ) {
		output[2] = "||     0                            ";
		output[3] = "||     \"                            ";
	}
	else if ( times == 3 ) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
		output[4] = "||    /|\\                           ";
	}
	else if ( times == 4 ) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
 		output[5] = "||   / | \\                          ";
	}
	else if ( times == 5) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
		output[6] = "||    / \\                           ";
	}
	else if ( times == 6 ) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
		output[7] = "||   /   \\                          ";
	}
	else if ( times == 7 ) {
	        output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
		output[2] = "||     0         -@-                ";
	}
	else if ( times == 8 ) {
	        output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
		output[3] = "||     \"         \\|/               ";
	}
	else if ( times == 9 ) {
		output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
                output[3] = "||     \"         \\|/               ";
		output[4] = "||    /|\\         |                 ";
	}
	else if ( times == 10 ) {
		output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
                output[3] = "||     \"         \\|/               ";
                output[4] = "||    /|\\         |                 ";
		output[5] = "||   / | \\      /```\\              ";
	}
	else if ( times == 11 ) {
		output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
                output[3] = "||     \"         \\|/               ";
                output[4] = "||    /|\\         |                 ";
                output[5] = "||   / | \\      /```\\              ";
		output[6] = "||    / \\       `/`\\`              ";
	}
	else if ( times == 12 ) {
		output[7] = "||   /   \\                          ";
                output[3] = "||     \"         \\|/               ";
                output[4] = "||    /|\\         |                 ";
                output[5] = "||   / | \\      /```\\              ";
                output[6] = "||    / \\       `/`\\`              ";
		output[2] = "||     0         -@-         0      ";
	}
	else if ( times == 13 ) {
		output[7] = "||   /   \\                          ";
                output[4] = "||    /|\\         |                 ";
                output[5] = "||   / | \\      /```\\              ";
                output[6] = "||    / \\       `/`\\`              ";
 		output[2] = "||     0         -@-         0      ";
		output[3] = "||     \"         \\|/         \"    ";
	}
	else if ( times == 14 ) {
		output[7] = "||   /   \\                          ";
                output[5] = "||   / | \\      /```\\              ";
                output[6] = "||    / \\       `/`\\`              ";
                output[2] = "||     0         -@-         0      ";
                output[3] = "||     \"         \\|/         \"    ";
		output[4] = "||    /|\\         |         /|\\    ";
	}
	else if ( times == 15 ) {
		output[7] = "||   /   \\                          ";
	        output[6] = "||    / \\       `/`\\`              ";
                output[2] = "||     0         -@-         0      ";
                output[3] = "||     \"         \\|/         \"    ";
                output[4] = "||    /|\\         |         /|\\    ";
		output[5] = "||   / | \\      /```\\       / \\   ";
	}

	for ( int i = 0; i < 12; i++) {
        	cout << output[i] << endl;
    	}
	cout<<endl;

    	for ( int i = 0; i < word.length(); i++ ) {
    		cout << guess_blank[i] << " ";
	}
	cout << endl;

	cout << "For this word, you have guessed: ";
	for ( unsigned int i = 0; i < wrong_letter.size(); i++ ) {
		cout << wrong_letter[i] << " ";
	}
	cout << endl;			  
}
