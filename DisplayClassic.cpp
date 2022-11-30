#include<iostream>
#include<vector>
#include<string>
#include "gp.h"

using namespace std;

// display_L1 function is the drawing hang man in the Classic Mode.
// There are totally five input parameters, word, output, times, guess_blank and guessed.
// String word is the word to be guessed; output is the figure of hang man; times is the wrong times that player has guessed;
// guess_blank contains the characters that were guessed out and rest characters represented by '_';
// guessed contains the wrong letters that have been guessed.
// This function is a void function so no returned values. We directly print what we want in the function.

void display_L1( string word, vector< string > output, int times, char guess_blank[], vector< char > guessed ) {
	if ( times == 1 ) {
		output[2] = "||     0   ";    // draw the head of the hang man
	}
	else if ( times == 2 ) {
		output[2] = "||     0   ";
		output[3] = "||     \"   ";    // draw the neck of the hang man
	}
	else if ( times == 3 ) {
		output[2] = "||     0   ";
                output[3] = "||     \"   ";
		output[4] = "||    /|\\  ";    // draw the hands of the hang man
	}
	else if ( times == 4 ) {
		output[2] = "||     0   ";
                output[3] = "||     \"   ";
                output[4] = "||    /|\\  ";
		output[5] = "||    / \\  ";    // draw the feet of the hang man
	}

	for ( int i = 0; i < 12; i++) {
        	cout << output[i] << endl;    // output the figure of the hang man
        }
	cout << endl;

	for ( int i = 0; i < word.length(); i++) {
	    	cout << guess_blank[i] << " ";    // output the guessed blanks
	}
	cout << endl;

	cout << "For this word, you have guessed: ";
	for ( unsigned int i=0; i < guessed.size(); i++) {
		cout << guessed[i] << " ";    // output the wrong guesses
	}
	cout << endl;
	
    	if ( times == 4 ) {
		cout << "*************" << endl;
		cout << "**You lose!**" << endl;    // there are no chances any  more
		cout << "*************" << endl;
		cout << "The word is: " << word << endl;    // tell the player what the word exactly is
	}				  
}
