#include<iostream>
#include<vector>
#include<string>
#include "gp.h"

using namespace std;

void display_L1( string word, vector< string > output, int times, char guess_blank[], vector< char > guessed ) {
	if ( times == 1 ) {
		output[2] = "||     0   ";
	}
	else if ( times == 2 ) {
		output[2] = "||     0   ";
		output[3] = "||     \"   ";
	}
	else if ( times == 3 ) {
		output[2] = "||     0   ";
                output[3] = "||     \"   ";
		output[4] = "||    /|\\  ";
	}
	else if ( times == 4 ) {
		output[2] = "||     0   ";
                output[3] = "||     \"   ";
                output[4] = "||    /|\\  ";
		output[5] = "||    / \\  ";
	}

	for ( int i = 0; i < 12; i++) {
        	cout << output[i] << endl;
        }
	cout << endl;

	for ( int i = 0; i < word.length(); i++) {
	    	cout << guess_blank[i] << " ";
	}
	cout << endl;

	cout << "Wrong guesses: ";
	for ( unsigned int i=0; i < guessed.size(); i++) {
		cout << guessed[i] << " ";
	}
	cout << endl;
	
    	if ( times == 4 ) {
		cout << "*************" << endl;
		cout << "**You lose!**" << endl;
		cout << "*************" << endl;
		cout << "The word is: " << word << endl;
	}				  
}
