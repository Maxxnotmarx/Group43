// Main Page Function

#include <iostream>
#include <fstream>
#include <string>
#include "gp.h"

using namespace std;

void MainPage(){
	cout<<endl;
	cout << "   -------------------------------Main Page-------------------------------" << endl;
	cout << "   _______________________________________________________________________" << endl;
    	cout << "   ************  M: menu; E: enter the game; Q: quit the game;  **********" << endl;
	cout << "   -----------------------------------------------------------------------" << endl;
	char input;
	cout << "   ***********************************************************************" << endl;
	cout << "   _______________________________________________________________________\n";
	cout << "   ||                            /      				||\n";
	cout << "   ||                           0                                       ||\n";
	cout << "   ||                            \"                                      ||\n";
	cout << "   ||                           /|\\                                     ||\n";
	cout << "   ||                           / \\                                     ||\n";
	cout << "   ||                                                                   ||\n";
	cout << "   ||                                                    	        ||\n";
	cout << "   ||                  *************************                        ||\n";
	cout << "   ||                  **** ENJOY YOUR GAME ****                        ||\n";
	cout << "   ||                  *************************                        ||\n";
	cout << "   ||___________________________________________________________________||\n\n";
	cout << "   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;

    	while( cin >> input ) {
		if ( input == 'M' ) {
		    	// cout Menu.txt
		    	menu();
	    	}
		else if ( input == 'E' ) {
			char mode;
			
			cout << "mode: C: classic; S: scoring" << endl;

			while( cin >> mode ) {
				if ( mode == 'Q' ) {
					cout << "Bye Bye!" << endl;
					exit(0);
				}

		    		if ( mode == 'C' ) {
			    		Classic();
		                	break;
			    	}
		    		else if ( mode == 'S' ) {
				    	Scoring();
        		        	break;
		    		}

				else{
					cout << "Invalid input, please press \"C\", \"S\" to continue, or \"Q\" to quit" << endl;
				}
	    		}
			break;
		}
	
	    	else if ( input == 'Q' ) {
		    	cout << "Bye bye" << endl;
		    	exit(0);
	    	}
	
	  	else {
		    	cout << "Invalid input" << endl;
	    	}
    	}
}
