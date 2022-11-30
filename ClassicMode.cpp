// Classic Mode of Play

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <vector>
#include <stdlib.h>
#include "gp.h"

using namespace std;


// Enter the classic game mode
void Classic(){
	int times = 0;
	vector < char > guessed;
	vector < string > output;
	char voca, level, guess, guess_blank[] = {'_', '_', '_', '_', '_', '_', '_'}, input;
	string file, word;
	bool quit = true;

	// Determine the Vocabulary and Difficulty level the player want to play with
	cout << "________________________________________________________" << endl;
	cout << "  Choose Vocabulary: O: Oxford 3500; I: IELTS; G: GRE   " << endl;
	cout << "--------------------------------------------------------" << endl;
	while( cin >> voca ){
		if ( voca == 'O' || voca == 'I' || voca == 'G' ){
			break;
		}
		if( voca == 'Q' ){
			cout << "Bye Bye!" << endl;	
			exit(0);
		}
		else {
            		cout<<"Invalid input, please press: \"O\", \"I\", \"G\" to continue, or \"Q\" to quit"<<endl;
        	}
	}
	cout << "______________________________________________________________________________" << endl;
	cout << "  Choose length of the words: 1: 5-character; 2: 6-character; 3: 7-character  " << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	while ( cin >> level ){
		if ( level == '1' || level == '2' || level == '3' ){
			break;
		}
		if ( level == 'Q' ){
			cout << "Bye Bye!" << endl;
                        exit(0);
                }
		else {
			cout << "Invalid input, please press \"1\", \"2\", \"3\" to continue, or \"Q\" to quit" << endl;
		}
	}
	
	if ( voca == 'O') {
		if ( level == '1' ) {
			file = "Oxford_01.txt";
		}
		else if ( level == '2' ) {
			file = "Oxford_02.txt";
		}
		else if ( level == '3' ) {
			file = "Oxford_03.txt";
		}
	}

	else if( voca == 'I'){
		if ( level == '1' ) {
			file = "IELTS_01.txt";
		}
		else if ( level == '2' ) {
			file = "IELTS_02.txt";
		}
		else if ( level == '3' ) {
			file = "IELTS_03.txt";
		}
	}
	
	else if ( voca == 'G' ) {
		if ( level == '1' ) {
			file = "GRE_01.txt";
		}
		else if ( level == '2' ) {
			file = "GRE_02.txt";
		}
		else if ( level == '3' ) {
			file = "GRE_03.txt";
		}
	}

	word = RandomWord( file ); // Get the word of corresponding vocabulary and difficulty level

	// The game starts
	output.push_back( "____________" );
	output.push_back( "||     |    " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||          " );
	output.push_back( "||___________" );

	cout << "If you want a hint, please press \'?\'" << endl;
	cout << "You have infinite times of hints!" << endl;

	for ( int i = 0; i < output.size(); i++ ) {
		cout << output[i] << endl;
	}
	cout << endl;

	for ( int i = 0; i < word.length(); i++ ) {
		cout << guess_blank[i] << " ";
	}
	cout << endl;
	

	while ( quit && cin >> guess ){
		
		// Check if the input word is filled in the blank or not
		for ( int i = 0; i < word.length(); i ++) {
			if ( guess_blank[i] == guess ) {
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "  The character has been filled in the blank!  " << endl;
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			}
		}

		// Return to Mainpage
		if ( guess == 'R') {
			MainPage();
			break;
		}
		
		// On-going round of guessing
		else if ( isalpha( guess ) || guess == '?' ) {

			// Player requires to exit the game
			if ( guess == 'Q') {
				cout << "============" << endl;
				cout << "  Bye Bye!  " << endl;
				cout << "============" << endl;
				exit(0);
    			}
			
			else if ( guess == 'R') {
				MainPage();
                                break;
			}

			// Player requires a hint
			else if ( guess == '?' ) {
				int stop = 0;
            			int i = 0;
            			char letter;
            
            			while ( stop != 1 && i <= word.length()-1 ) {
                			if ( word[i] != guess_blank[i] ) {
                    				stop = 1;
                    				letter = word[i];
                    				guess_blank[i] = letter;
                    
                    				for ( int j = i+1; j <= word.length()-1; j++ ) {
                        				if ( word[j] == letter ) {
                            					guess_blank[j] = letter;
                        				}
                    				}
                			}
                			i+=1;
            			}
				display_L1( word, output, times, guess_blank, guessed );
        		}	

			// Player guesses the wrong character
			else if ( word.find(guess) == -1 ) {
				int count_number_of_guessed = 0;
                                for ( int i = 0; i < guessed.size(); i++ ) {
                                        if ( guessed[i] == guess ) {
                                                count_number_of_guessed += 1;
                                        }
                                }
                                if ( count_number_of_guessed == 0 ) {
                                        times++;
                                        guessed.push_back( guess );
					display_L1( word, output, times,  guess_balnk, guessed );
                                } 
				else {
					display_L1( word, output, times, guess_blank, guessed );
					cout << "..............................................." << endl;
					cout << "  You have already guessed this! It is wrong!  " << endl;
					cout << "..............................................." << endl;
				}
			}

			// Player guesses the right character
			else{
				int pos;
				pos = word.find( guess );
				while ( pos != -1 ) {
					guess_blank[pos] = word[pos];
					pos = word.find( guess, pos+1);
				}
				display_L1( word, output, times, guess_blank, guessed );
			}
			
			int count_space = 0;
			char whether_to_play_again;

		    	for ( int i=0; i < word.length(); i++ ) {
			        if ( guess_blank[i] == '_' ) {
			        	count_space += 1;
		        	}
    			}
			if ( count_space == 0 ) {
				output[0] = "____________";
                    		output[1] = "||     |    ";
                    		output[2] = "||          ";
		                output[3] = "||          ";
                		output[4] = "||          ";
	                	output[5] = "||       I'm free!";
				output[6] = "||      /    ";
                    		output[7] = "||     0    ";
                    		output[8] = "||     \"    ";
	                    	output[9] = "||    \\|/   ";
	                    	output[10] = "||    / \\   ";
				output[11] = "||___________";
					
				for ( int i = 0; i < 12; i++ ) {
        		        	cout << output[i] <<endl;
          			}

          			cout << "The correct word is: " << word << endl;
			    	cout << "*************" << endl;
				cout << "***You win!**" << endl;
				cout << "*************" << endl;
				cout << "_________________________________________________________" << endl;
		        	cout << "   Do you want to play for another round? Y: Yes N: No   " << endl;
				cout << "_________________________________________________________" << endl;
				cin >> whether_to_play_again;
				
				if ( whether_to_play_again == 'Y' ) {
					MainPage();
					break;
				}
				else if ( whether_to_play_again == 'N' ) {
					cout << "============" << endl;
					cout << "  Bye Bye!  " << endl;
					cout << "============" << endl;
					quit=false;
					break;
				}
				else {
					cout << "===========================" << endl;
					cout << "  Invalid Input, Bye Bye!  " << endl;
					cout << "===========================" << endl;
					break;
				}
			}
		}
		// Invalid input
		else {
			cout << "_________________" << endl;
			cout << "  Invalid input  " << endl;
			cout << "_________________" << endl;
		}

		// End of round
		if ( times == 4 ) {
			cout << "________________________________________________________" << endl;
                        cout << "  Do you want to play for another round? No: N; Yes: Y  " << endl;
			cout << "________________________________________________________" << endl;
                        cin >> input;
                        if ( input == 'Y' ) {
                                MainPage();
                        	break;
                        }
                        else if ( input == 'N' ) {
				cout << "============" << endl;
                                cout << "  Bye Bye!  " << endl;
				cout << "============" << endl;
                                break;
                        }
                }
	}
}
