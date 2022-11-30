#include<iostream>
#include<vector>
#include<string>
#include "gp.h"

using namespace std;

// display_Scoring function is the drawing hang man in the Scoring Mode.
// There are totally five input parameters, word, output, times, guess_blank and wrong_letter.
// String word is the word to be guessed; output is the figure of hang man; times is the wrong times that player has guessed;
// guess_blank contains the characters that were guessed out and rest characters represented by '_';
// wrong_letters contains the wrong letters that have been guessed.
// This function is a void function so no returned values. We directly print what we want in the function.

void display_Scoring( vector< string > output, int times ) {
	if ( times == 1 ) {
		output[2] = "||     0                            ";    // draw the head of 'father'
	}
	else if ( times == 2 ) {
		output[2] = "||     0                            ";
		output[3] = "||     \"                            ";    // draw the neck of 'father'
	}
	else if ( times == 3 ) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
		output[4] = "||    /|\\                           ";    // draw the arms of 'father'
	}
	else if ( times == 4 ) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
 		output[5] = "||   / | \\                          ";    // draw the hands of 'father'
	}
	else if ( times == 5) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
		output[6] = "||    / \\                           ";    // draw the legs of 'father'
	}
	else if ( times == 6 ) {
		output[2] = "||     0                            ";
                output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
		output[7] = "||   /   \\                          ";    // draw the feet of 'father'
	}
	else if ( times == 7 ) {
	        output[3] = "||     \"                            ";
                output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
		output[2] = "||     0         -@-                ";    // draw the head of 'mother'
	}
	else if ( times == 8 ) {
	        output[4] = "||    /|\\                           ";
                output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
		output[3] = "||     \"         \\|/               ";    // draw the neck of 'mother'
	}
	else if ( times == 9 ) {
		output[5] = "||   / | \\                          ";
                output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
                output[3] = "||     \"         \\|/               ";
		output[4] = "||    /|\\         |                 ";     // draw the body of 'mother'
	}
	else if ( times == 10 ) {
		output[6] = "||    / \\                           ";
                output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
                output[3] = "||     \"         \\|/               ";
                output[4] = "||    /|\\         |                 ";
		output[5] = "||   / | \\      /```\\              ";    // draw the dress of 'mother'
	}
	else if ( times == 11 ) {
		output[7] = "||   /   \\                          ";
                output[2] = "||     0         -@-                ";
                output[3] = "||     \"         \\|/               ";
                output[4] = "||    /|\\         |                 ";
                output[5] = "||   / | \\      /```\\              ";
		output[6] = "||    / \\       `/`\\`              ";    // draw the feet of 'mother'
	}
	else if ( times == 12 ) {
		output[7] = "||   /   \\                          ";
                output[3] = "||     \"         \\|/               ";
                output[4] = "||    /|\\         |                 ";
                output[5] = "||   / | \\      /```\\              ";
                output[6] = "||    / \\       `/`\\`              ";
		output[2] = "||     0         -@-         0      ";    // draw the head of 'child'
	}
	else if ( times == 13 ) {
		output[7] = "||   /   \\                          ";
                output[4] = "||    /|\\         |                 ";
                output[5] = "||   / | \\      /```\\              ";
                output[6] = "||    / \\       `/`\\`              ";
 		output[2] = "||     0         -@-         0      ";
		output[3] = "||     \"         \\|/         \"    ";    // draw the neck of 'child'
	}
	else if ( times == 14 ) {
		output[7] = "||   /   \\                          ";
                output[5] = "||   / | \\      /```\\              ";
                output[6] = "||    / \\       `/`\\`              ";
                output[2] = "||     0         -@-         0      ";
                output[3] = "||     \"         \\|/         \"    ";
		output[4] = "||    /|\\         |         /|\\    ";    // draw the hands of 'child'
	}
	else if ( times == 15 ) {
		output[7] = "||   /   \\                          ";
	        output[6] = "||    / \\       `/`\\`              ";
                output[2] = "||     0         -@-         0      ";
                output[3] = "||     \"         \\|/         \"    ";
                output[4] = "||    /|\\         |         /|\\    ";
		output[5] = "||   / | \\      /```\\       / \\   ";    // draw the feet of 'child'
	}

	for ( int i = 0; i < 12; i++) {
        	cout << output[i] << endl;    // output the figure of the game status
    	}
	cout<<endl;			  
}
