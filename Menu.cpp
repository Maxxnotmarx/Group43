// Menu Page
#include "gp.h"
#include <iostream>
using namespace std;

void menu() {
    
    cout << "  ------------------------Hello! Welcome to the HANGMAN game!----------------------" << endl;
    cout << "  ------------------------------------MAIN MENU------------------------------------\n\n\n";
    
    cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout << "   $$$$-$$$$-$$$$-$$$$----------RULES FOR CLASSIC MODEL---------$$$$-$$$$-$$$$-$$$$\n";
    cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
    
    cout << "\t1. There will be number of blanks generated depending on the word length you choose.\n\n";
    cout << "\t2. Try to guess each letter of the word.\n\n";
    cout << "\t3. Each wrong guess displays the parts of the hangman.\n\n";
    cout << "\t2. You can make total 4 wrong guesses.\n";
    cout << "\t4. When the hangman is fully drawn, YOUR LOSE!!.\n\n";
    cout << "\t5. You can get hints as many times as you need.\n\n";
    
    
    cout << "\t6. There are THREE different dictionaries to choose:\n\n";
    
    cout << "\t\t>OXFORD\n";
    cout << "\t\t>IELTS\n";
    cout << "\t\t>GRE\n\n";
    
    
    
    cout<<"     ______________________________________________________________________\n";
    cout<<"     ||                            /      \n";
    cout<<"     ||         Save me!!  >>>>   0      \n";
    cout<<"     ||                            \"   \n";
    cout<<"     ||                           /|\\   \n";
    cout<<"     ||                           / \\   \n";
    cout<<"     ||                                              Save him!! >>>>  O \n";
    cout<<"     ||                                                             \\ |/ \n";
    cout<<"     ||                                                              / \\\n";
    cout<<"     ||                                                              --- \n";
    cout<<"     ||                                                               ||   \n";
    cout<<"     ||_____________________________________________________________________\n\n";
    
    cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout << "   $$$$-$$$$-$$$$-$$$$----------RULES FOR SCORING MODEL---------$$$$-$$$$-$$$$-$$$$\n";
    cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
    
    cout << "\t0. Register or login to your account.\n\n";
    cout << "\t1. There will be number of blanks generated each round.\n\n";
    cout << "\t2. Try to guess each letter of the word.\n\n";
    cout << "\t3. Three points for guessing a letter correctly.\n\n";
    cout << "\t4. two extra points for guessing a complete word, ranked by score. \n\n";
    cout << "\t5. Each wrong guess displays the parts of the hangman.\n\n";
    cout << "\t6. When the hangmans are fully drawn, YOUR LOSE!!.\n\n";
    cout << "\t7. When the game is over, the score will be counted.\n\n";
    cout << "\t8. system will save the score of each player and rank them.\n\n";
    cout << "\t9. Try to get the highest score, we are waiting for you to challenge!\n\n";
    
    cout<<"     ______________________________________________________________________\n";
    cout<<"     ||     |          |          |     \n";
    cout<<"     ||     0         -@-         0     \n";
    cout<<"     ||     \"         \\|/         \"   \n";
    cout<<"     ||    /|\\         |         /|\\    \n";
    cout<<"     ||   / | \\      /```\\       / \\   \n";
    cout<<"     ||    / \\       `/`\\`                 Try it now! >>>> O\n";
    cout<<"     ||   /   \\                                             \" \n";
    cout<<"     ||                                                   \\ | > \n";
    cout<<"     ||                                                     | \n";
    cout<<"     ||                                                    / \\  \n";
    cout<<"     ||_____________________________________________________________________\n\n";

    cout<<"This is the end of menu, press 'E' to enter the game or 'Q' to exit the game"<<endl;
}
