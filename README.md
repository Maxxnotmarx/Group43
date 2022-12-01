## Group43

    Group Members:

    He Ziyi (3035864003)
    Ma Xinyue (3035946198)
    Zhou Zihan (3035947843)

## Game Discirption:

   This is a single-player game inspired by the world classic guessing game Hangman (For reference: https://en.wikipedia.org/wiki/Hangman_(game)), in which there are two parties playing, the one who gives out the word is the computer, and the one who guesses the word is the human player. We have 2 different modes of playing that one can choose to play with: 1) Classic Mode and 2) Scoring Mode.

## Game Rules:

  1) Mainpage:

      A main page with the following functions:

      i) Menu(M): Check game rules inside the game.

      ii) Enter(E): Enter the game, followed by the options of game mode.

      iii) Quit(Q): Quit the game/ End the running program.

  
  2) Classic Mode:

     The player's goal is to correctly guess out one word randomly generated by the program.
     
     There are only two outcomes at the end of each round: 
     -  Guess the correct word in a limited number of times, aka "You Win".
     -  Fail to guess the correct word in a limited number of times, aka "You Lose".
   
     
                    0 Penalty(start)     1 Penalty           2 Panalties       3 Panalties      4 Panalties(Lose)
                     ______________    ______________      ______________     ______________    ______________
                     ||     |          ||     |            ||     |           ||     |          ||      |
                     ||                ||     0            ||     0           ||     0          ||      0
                     ||                ||                  ||     "           ||     "          ||      "
                     ||                ||                  ||                 ||    /|\         ||     /|\
                     ||                ||                  ||                 ||                ||     / \
                     ||                ||                  ||                 ||                ||
                     ||                ||                  ||                 ||                ||
                     ||                ||                  ||                 ||                ||
                     ||___________     ||___________       ||_____________    ||_____________   ||_____________ 

     In this mode, the player can choose the word comes from: 
     
     - Oxford 3500
     - IELTS
     - GRE
  
     Under each vocabularies, the player can choose words of three different lengthes: 
     
     - 5 character-long; 
     - 6 character-long; 
     - 7 character-long. 

Commands for lines of input:

      i) Hint(?): Player has unlimited chances of obtaining a hint, which will directly fill one character of the word in the blank each time, press "?" to do so. However, the player is not suggested to use too many of them in order to keep the game challenging.
      
      ii) Quit(Q): Quit the game any time during the on-going round of guess

      iii) Return(R): Return to the Mainpage, current game status will not be saved.

      iv) Guess(a-z): Guess should be inputted with lower case of the character.

      v) Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
   
   3) Scoring Mode:

       The player's goal is to guess as many words as possible that are randomly generated by the program and get the higest score.

       Guessing the correct letter as well as the word will score points.
       
                                                15 penalties(End of the round)
                                            ___________________________________ 
                                           ||     |          |          |      
                                           ||     0         -@-         0      
                                           ||     "         \|/         "    
                                           ||    /|\         |         /|\    
                                           ||   / | \      /```\       / \   
                                           ||    / \       `/`\`              
                                           ||   /   \                          
                                           ||                                  
                                           ||                                  
                                           ||                                  
                                           ||__________________________________
        
        word in each round is generated: 1-3: Oxford 3500 5-7 characted-long word; 4-6: IELTS 5-7 characted-long word; 7-9: IELTS 5-7 characted-long word. As you can see, the difficulty of guessing out the word increases as you guess out more words.    
        
Commands for lines of input:

      i) Hint(?): Player has 5 hints in total, function the same as the one in Classic Mode.
      
      ii) Quit(Q): Quit the game any time during the on-going round of guessing, current score will not be saved.

      iii) Return(R): Return to the Mainpage, current game status and current socre will not be saved.

      iv) Guess(a-z): Guess should be inputted with lower case of the character.
      
      v) Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
## Features(Coding Requirement):
    
  1. Generation of random game sets: 
  
  The guessing word is randomly selected from a specific dictionary. Take the Classic Mode for instance, the player    can choose the vocabulary the word comes from and its length, but the selection of the word from that specific dictionary that the player choose is random, in which case he or she will not be able to predict what the next word is before he or she starts to guess. The generation of random word is achieved by defining the RandomWord() function in RandomWord.cpp.
    
   2. Data structures for storing game status:
    
   a) In DisplayScoring.cpp and DisplayClassic.cpp, integer times and vector output was used to store the game status by storing wrong times in the integer and the figure of the hang man in the vector. Once the wrong times increase by one, the integer times increase by one, and the vector will be updated the new figure of the hang man.
   b) In the scoring mode part, we also used a dynamic array to store the players' score to store the game status.
    
   3. Dynamic memory management:
    
   Dynamic memory managemen is used in the ScoringMode.cpp. We created a dynamic array called Playerlist. Its purpose is to store user information, including username, maximum score, and password. When the player chooses to enter scoring mode to play the game, system will ask the player to enter a username, determine if the username exists, and if it does, ask for a password, and if it doesn't, create a new pointer to store the latest user's address. Whenever a new user registers for the scoring mode, the size of the Playerlist will be increased by one, and store the new user information.
    
   4. File input/output:
    
   File Input: 
    a) The game is supported by 9 dictionaries accroding to the level of study and the word length, thus we seprate all potential words that the player might encounter into 9 .txt files. In the RandomWord.cpp, everytime the player choose the dictionary to guess with, the program will read the specific .txt file and store them in a vector, then a random word will be selected from that vector using the RandomWord() function. With words seperately stored in different files, it is easier and clearer of what to do if one want to add more words supply to the game.
    b) i) In order to get the users' information in the scoring mode, we also used file input to read the User_Info.txt line by line to store the information in the dynamic array. Therefore, we can print out the ranking information while the player want to take a look.
      ii) By use "getline()" and some calculations, we are able to extract the current number of players from User_Info.txt. We do this is to provide a initial size for the "Playerlist" which is the dynamic array we created. 
    
   File Output:
    After playing the scoring mode game, the player has a new score if his score increased compared to his highest score, and we need to update his score, in the code, we store his new score in the dynamic array and finally output the contents in the dynamic array to the User_Info.txt again to update the information of the players. At the same time, we store the rankings into the file.
    
   5. Program codes in multiple files:

   To improve the readabilty of the code and for a better code organization, feature functions are wirtten in separate files. Since we have two modes of playing, the code of each mode are written as functions in separate files. And functions displaying the game status and functions generating a random word are also defined in separate files. With feature functions defined seperately, the programmer can call the function whenever and wherever he needs.
