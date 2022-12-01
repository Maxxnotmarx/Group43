#include <iostream>
#include <string>
#include "gp.h"
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

// make up a structure to store the information of the users
struct Player{
	string name;
	string password;
	int score;
};

// enter the scoring mode, no paramter input
void Scoring(){
    
	Player *playerList;    // create a dynamic array to store the information of the players

        string player_name, player_password;    // declare the information type
        int player_score, wrong_time=0, size=3, player_index;    // initialize the wrong times as 0 and size equals to 3 since we only have 3 players' information now
        bool outer=true, inner=true, search_name=false, check_password=false;    // set up some booleans to jump out of loops later


	ifstream fin1;
	fin1.open("User_Info.txt");    // open the User_Info.txt file to read in players' information
	
	string line;
	int num_user=0;
	while (getline(fin1,line)){
		num_user+=1;    // count the number of players
	}
	size=num_user;    // make the size equals to the number of players
	fin1.close();

	playerList = new Player[size];    // set the dynamic array

	int current_score=0,i=0;    // initial the score

	ifstream fin2;
	fin2.open("User_Info.txt");
	
	// read the players' information and store them into the dynamic array
	while(getline(fin2,line)){
		string name,password;
		int current_score;
		int index1,index2;

		index1=line.find(';');
		index2=line.find('|');

		name=line.substr(0,index1);
		password=line.substr(index1+1,6);
		current_score=stoi(line.substr(index2+1,line.length()-index2-1));
		playerList[i].name=name;
		playerList[i].password=password;
		playerList[i].score=current_score;
		i+=1;
	}
	fin2.close();

	while (outer) {
        	inner=true;
        	wrong_time=0;
		search_name=false;
		cout<<"======================"<<endl;
        	cout<<"Please input your name"<<endl;    // ask the player to input the name
		cout<<"======================"<<endl;
        	cout<<"If you input the wrong name, you can press \"return\" to jump back"<<endl;
		cout<<"# Note that \"return\" is not a valid name!"<<endl;
        	while(inner){
            		cin>>player_name;
	    		cout<<endl;
			
			// search the name and determine whethter there already exist such player
            		for (int i=0; i<size; i++){
                    		if (playerList[i].name == player_name){
                        		search_name=true;
                        		player_index=i;
                    		}
            		}
			
		        if (search_name){    // if the name was found to be set before, we need to check his password to confirm that this is his account
				cout<<"This username is being created before, if this is your account please enter the password."<<endl;
				cout<<"If this is not your account, please enter \"return\" to input a new username again."<<endl;
				cout<<"----------------------------"<<endl;
				cout<<"Please input your password: "<<endl;
				cout<<"----------------------------"<<endl;
				check_password=true;
				while(check_password){ //input the password
		                	cin>>player_password;
        	                        
        		        	if (player_password=="return"){//will return to input username step
                        			check_password=false;
						inner=false;
						search_name=false;
			                }
					
					// if the password is true and we know that this is his account
	                		if (playerList[player_index].password==player_password){
						cout<<"**********************"<<endl;
						cout<<"Welcome back! "<<player_name<<endl;
                	    			player_score=playerList[player_index].score;
						check_password=false;
						inner=false;
						outer=false;
						cout<<"**********************"<<endl;
                        			cout<<"Your current highest score is "<<player_score<<endl; //display current score
						cout<<"----------------------------------"<<endl;
                    			}
					
					// if the password is wrong, we need to remind him about this and tell him how many times of inputting passwords left
		                	else {
        		            		wrong_time+=1;
				    		cout<<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"<<endl;
                	    			cout<<"Wrong Password! You have "<<3-wrong_time<<" times to input your password."<<endl;
			    			cout<<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"<<endl;
                    			}
					
					// if the maximum of wrong times was reached, we jumpy back to the step of inputting name
                    			if (wrong_time==3){
	                        		cout<<"You have input 3 times of wrong password!"<<endl;
		                    		cout<<"We will jump to the first step!"<<endl;
						cout<<"================================"<<endl;
						cout<<endl;
						check_password=false;
        			        	inner=false;
                			}
                		}
			}
			
			// if the name was not created before, we let the player create an account and set his passwords and store them into the dynamic array
        	    	else {
                		string temp_password;
                		check_password=true;
				
		                cout<<"You have no account now! We will create an account for you!"<<endl;
				cout<<"--------------------------------------------------------------"<<endl;
	        	        cout<<"If you input the wrong name, you can press \"return\" to jump back"<<endl;
        	        	cout<<"Please set your 6-character password!"<<endl;
				cout<<"# Note that \"return\" is not a valid password!"<<endl;
				cout<<"-------------------------------------------------"<<endl;

                		while(check_password){
	                    		cin>>player_password;
						
					// ask the player to confirm passwords if the passwords are in proper type
					if (player_password.length()==6&&player_password!="return"){
						cout<<"····························"<<endl;
						cout<<"Please confirm your password"<<endl; //confirm
	                    			cin>>temp_password;
						
						// if the confirm is right, the password was set up successfully, and so the account was created successfully
				    		if (temp_password==player_password){
                		        		cout<<"Password set successfully!"<<endl;
							cout<<"**************************"<<endl;
                        				check_password=false;
								
							// insert a new struct(representing the new player's account information) into the dynamic array
                            				Player *temp=new Player[size]; //copy all the current user information to the temp dynamic array
                            				for (int i=0;i<size;i++){
                                				temp[i]=playerList[i];
	                        			}
        	                			delete []playerList; //delete the original playerList dynamic array
                	        			playerList= new Player[size+1]; //create a new dynamic array with one more size, in order to add the new user to our user information
                        				for (int i=0;i<size;i++){ //add all current user to our current playerList dynamic array
	                                			playerList[i]=temp[i];
	                            			}
	                            			delete []temp; //delete the temp dynamic array
	
		                        		playerList[size].name=player_name;//add the new user to the current dynamic array
        		                		playerList[size].password=player_password;
                		        		playerList[size].score=0;
                        				size++;//size+1
							inner=false;
        			                	outer=false;
							player_index=size;
	                    			}
						else if (temp_password=="return"){
                	    				inner=false;
                        				check_password=false;
						}
                        			else {
							cout<<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"<<endl;
        	                    			cout<<"The password was different from the one you set just now! Please set again!"<<endl;
                	        		}
					}
        	        		else if (player_password=="return"){
                	    			inner=false;
                        			check_password=false;
                    			}
					else if(player_password.length()!=6){
						cout<<"Please set a 6-character password!"<<endl;
					}
                		}
            		}
		}
	}

	cout << "#######################################" << endl;
    	cout << "###  Welcome to the Hangman 2022 !  ###" <<endl;
    	cout << "#######################################" << endl;
	

    	char voca, guess, guess_blank[] = {'_', '_', '_', '_', '_', '_', '_'};
    	int num_hint=5,times=0,choose_word=0, score=0;
    	string word,file;
    	vector <string> guessed_words;
	
    	// create a vecotr to store the figure of hang man
    	vector <char> wrong_letter;
	
    	// initialize the game status
    	vector< string > output;
    	output.push_back("___________________________________ ");
    	output.push_back("||     |          |          |      ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||                                  ");
    	output.push_back("||__________________________________");

    	// first print out the shape of the shelf
    	for (int i=0;i<output.size();i++){
	        cout <<output[i]<<endl;
    	}
    	cout<<endl;
    	cout<<"Now you can guess the words!"<<endl;
    	cout<<endl;
    	cout<<"_ _ _ _ _"<<endl;


	while(times<15){
        	// determine word
        	if (choose_word%9==0){
            		file = "Oxford_01.txt";
            		word = RandomWord(file); 
        	}
        	else if (choose_word%9==1){
            		file = "Oxford_02.txt";
            		word = RandomWord(file);
        	}
	        else if (choose_word%9==2){
        		file = "Oxford_03.txt";
            		word = RandomWord(file);
        	}
        	else if (choose_word%9==3){
            		file = "IELTS_01.txt";
            		word = RandomWord(file);
        	}
        	else if (choose_word%9==4){
            		file = "IELTS_02.txt";
            		word = RandomWord(file);
        	}
        	else if (choose_word%9==5){
            		file = "IELTS_03.txt";
            		word = RandomWord(file);
       		}
        	else if (choose_word%9==6){
            		file = "GRE_01.txt";
            		word = RandomWord(file);
        	}
        	else if (choose_word%9==7){
            		file = "GRE_02.txt";
            		word = RandomWord(file);
        	}
        	else if (choose_word%9==8){
            		file = "GRE_03.txt";
            		word = RandomWord(file);
        	}

        	choose_word+=1;
    
    	    	// guess
        	while(cin>>guess){
	    		//determine whether the correct letter is already guessed before
            		if ( guess == 'R'){ // return to the mainpage
                		MainPage();
                		break;
            		}

            		if( guess == 'Q'){ //quit the game
                		cout << "**************" << endl;
                		cout << "** Bye Bye! **"<<endl;
                		cout << "**************" << endl;
                		exit(0);
            		}

            		if( isalpha(guess) || guess == '?'){ //require for the hint
                		//hint
                		if ( guess == '?' ){
                    			if (num_hint >0){ //Determine if there is still a chance for hint
                        			int stop=0;
                        			int i=0;
			                        char letter;
                        			num_hint-=1;
                        			while(stop!=1&&i<=word.length()-1){//search and fill in the first blank
                            				if(word[i]!=guess_blank[i]){
                                				stop=1;
                                				letter=word[i];
                                				guess_blank[i]=letter;

                                				for (int j=i+1;j<=word.length()-1;j++){//Look for duplicate hint letter within the word, and if so fill in each blank
                                    					if(word[j]==letter){
                                        					guess_blank[j]=letter;                                    
                                    					}
                                				}
                            				}
                            				i+=1;
                        			}
			            		display_Scoring( output, times);
                        			for ( int i = 0; i < word.length(); i++ ) {
      			            			cout << guess_blank[i] << " ";  // output the guessed blank for the current word
 		                		}
 		                		cout << endl;

     		            			cout << "For this word, you have guessed: ";
 	        	        		for ( unsigned int i = 0; i < wrong_letter.size(); i++ ) {
      	    		        			cout << wrong_letter[i] << " ";    // output the wrong letters that have been guessed for this word
 		                		}
 		                		cout << endl;
                    			}
                    			else{ //no chance for hint
                        			cout<<endl;
                        			cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
                        			cout<<"$ Sorry, you do not have any hint anymore, please guess by your own. $"<<endl;
                        			cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
                        			cout<<endl;
                    			}
                		}
                		
				// Player guesses the wrong character
                		else if( word.find(guess) == -1 ){//start to check whether the wrong letter is guessed already
                    			int count_number_of_guessed=0;
                    			for (int i=0;i<wrong_letter.size();i++){
                        			if (wrong_letter[i]==guess){//already guessed before, and is wrong. Not counted as another wrong guess
                            				count_number_of_guessed+=1; 
                        			}
                    			}
                    			if (count_number_of_guessed==0){ //no wrong guess for this letter before, wrong guess +1
                        			times++;
                        			wrong_letter.push_back(guess); //store the wrong guess
			            		display_Scoring( output, times);
                        			for ( int i = 0; i < word.length(); i++ ) {
          			        		cout << guess_blank[i] << " ";  // output the guessed blank for the current word
 	    	            			}
 		                		cout << endl;

 		                		cout << "For this word, you have guessed: ";
 	    	            			for ( unsigned int i = 0; i < wrong_letter.size(); i++ ) {
      			            			cout << wrong_letter[i] << " ";    // output the wrong letters that have been guessed for this word
                        			}
 	                    			cout << endl;
                    			}
                    			else{
                        			cout<<endl;
                        			cout<<"==========================================="<<endl;
                        			cout<<"You have already guessed this! It is wrong!"<<endl;
                        			cout<<"==========================================="<<endl;
                        			cout<<endl;
                    			}
                		}

                		// Player guesses the right character
                		else{
                    			int pos;
                    			int foundINblank = 0;
                    			for ( int i = 0; i < word.length(); i ++) { 
                        			if ( guess_blank[i] == guess ) {
                            			foundINblank += 1;
                        		}
                    		}
                    		pos = word.find( guess ); //find position 
                    		while( pos != -1){//position found
                        		score+=3; //score +3
                        		guess_blank[pos] = word[pos];//fill the blank
                        		pos = word.find( guess, pos+1); //repeat to check duplicate letter, fill them all
                    		}
		            	display_Scoring( output, times);
                    		for ( int i = 0; i < word.length(); i++ ) {
	      			        cout << guess_blank[i] << " ";  // output the guessed blank for the current word
 			        }
 		        	cout << endl;

 		            	cout << "For this word, you have guessed: ";
 		            	for ( unsigned int i = 0; i < wrong_letter.size(); i++ ) {
  			            cout << wrong_letter[i] << " ";    // output the wrong letters that have been guessed for this word
 		            	}
 		            	cout << endl;
                    
                    		if (foundINblank != 0){
                        	cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                        	cout << "  The character has been filled in the blank!  " << endl;
                        	cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    	}
                }
		
                //check complete
                int count_space=0;
                for (int i=0;i<word.length();i++){ //search for the blank
                    	if (guess_blank[i]=='_'){
                        	count_space+=1;
                    	}
                }

                if (count_space==0){//no blank, complete
                    	guessed_words.push_back(word);
                    	for (int j=0;j<7;j++){
                        	guess_blank[j]='_';
                    	}
                    	wrong_letter.clear(); //clear all the wrong letter stored in this word, ready for the next word
                    	score+=2; // additional 2 score is added
			
		        display_Scoring (output, times);
			
    		        cout<<endl;
                    	cout<<"* The word you guessed correct is: "<<word<<"."<<endl;
                    	cout<<"* Your current score is: "<<score<<"."<<endl;
                    	cout<<"* The chances you left is: "<<15-times<<"."<<endl;
                    	cout<<"* You still have "<<num_hint<<" hints can be used"<<"."<<endl;
                    	cout<<"* Now you can guess the next word! Good luck!"<<endl;
		        cout<<endl;
		    		    
	    	        cout<<" New Word: "<<endl;
		        if (word.length()==5){ //display blanks
    			        cout<<"_ _ _ _ _ _"<<endl;
	    	        } else if(word.length()==6){
		    	        cout<<"_ _ _ _ _ _ _"<<endl;
		        }
		        else{
			        cout<<"_ _ _ _ _"<<endl;
		        }
		        break;
                }
        }

        else{
        	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout<<"invalid input, please read the instruction carefully and input again."<<endl;
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        }

        if (times==15){// total 15 wrong guess could be make
	    	cout<<endl;
                cout<<"**************"<<endl;
                cout<<"* GAME OVER! *"<<endl;
                cout<<"**************"<<endl;
                cout<<endl;
                cout<<"· The right word is: "<<word<<endl; //show the player what the last unguessed word is
                cout<<"· Your score is: "<<score<<endl; //display the score
                cout<<"· The words you have guessed out were: "<<endl;
		    
                for (int i5=0; i5<guessed_words.size(); i5++){//display the words user guessed out
                	cout<<"     "<<guessed_words[i5]<<endl;
                }
		
		for (int i=0;i<size;i++){//renew the highest score, and store it
			if (playerList[i].name==player_name){
				if (score>playerList[i].score){
					playerList[i].score=score;
				}
			}
	        }
		
    	       	char see_ranking;
	        string temp_name,temp_password;
		int temp;
		cout<<"Do you want to see the ranking? 1: yes; 0: no "<<endl;
	        cin>>see_ranking;
		
    		// if the player wants to see the ranking
		if (see_ranking=='1'){
			Player *playerList_ranked =playerList;// create a dynamic array called different name but with the same content
			cout<<"------------------Ranking------------------"<<endl;
			
        		// use bubble sort to sort the players according to their scores from high to low
	        	for (int i=0;i<size-1;i++){
    				for (int j=0;j<size-1-i;j++){
	    				if (playerList_ranked[j].score<playerList_ranked[j+1].score){
		    		            	temp=playerList_ranked[j].score;
			    		        temp_name=playerList_ranked[j].name;
				    	        temp_password=playerList_ranked[j].password;
					        playerList_ranked[j].password=playerList_ranked[j+1].password;
					        playerList_ranked[j].score=playerList_ranked[j+1].score;
					        playerList_ranked[j].name=playerList_ranked[j+1].name;
						playerList_ranked[j+1].name=temp_name;
						playerList_ranked[j+1].score=temp;
					        playerList_ranked[j+1].password=temp_password;
				         }
			        }
	        	}
			
    			// output the ranking
	    		for (int z=0;z<size;z++){
		    	        cout<<playerList_ranked[z].name<<":"<<playerList_ranked[z].score<<endl;
		        }
		        cout<<endl;
		        cout<<"*************************"<<endl;
                    	cout<<"*** End of this round ***"<<endl;
			cout<<"*************************"<<endl;
			
			char whether_to_play_again;
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
				break;
			}
			else {
				cout << "===========================" << endl;
				cout << "  Invalid Input, Bye Bye!  " << endl;
				cout << "===========================" << endl;
				break;
			}
		}
	        else{
                	cout<<"Bye bye!"<<endl;
		}

		// store the new information into the User_Info.txt
		ofstream fout;
	        fout.open("User_Info.txt");
	        for (int z=0;z<size;z++){
    			fout<<playerList[z].name<<";"<<playerList[z].password<<"|"<<playerList[z].score<<endl;
		}
		fout.close();
	        delete [] playerList;
		    
                break; //game over
            }
        }
    }
}
