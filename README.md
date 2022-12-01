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

         Menu(M): Check game rules inside the game.

         Enter(E): Enter the game, followed by the options of game mode.

         Quit(Q): Quit the game/ End the running program.

  
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

            Hint(?): Player has unlimited chances of obtaining a hint, which will directly fill one character of the word in the blank each time, press "?" to do so. However, the player is not suggested to use too many of them in order to keep the game challenging.
      
            Quit(Q): Quit the game any time during the on-going round of guess

            Return(R): Return to the Mainpage, current game status will not be saved.

            Guess(a-z): Guess should be inputted with lower case of the character.

            Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
   
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
        
        word in each round is generated: 
        - 1-3: Oxford 3500 5-7 characted-long word; 
        - 4-6: IELTS 5-7 characted-long word; 
        - 7-9: IELTS 5-7 characted-long word. 
       
        Keep cycling until the end of the game
        
        
        Commands for lines of input:

            Hint(?): Player has 5 hints in total, function the same as the one in Classic Mode.
      
            Quit(Q): Quit the game any time during the on-going round of guessing, current score will not be saved.

            Return(R): Return to the Mainpage, current game status and current socre will not be saved.

            Guess(a-z): Guess should be inputted with lower case of the character.
      
            Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
## Features(Coding Requirement):
    
  1. Generation of random game sets: 
  
  - The words to be guessed in each round of the game are randomly generated from our `[dictionary].txt` by the `RandomWord.cpp`
  
   2. Data structures for storing game status:
   
   - struct `Player`: store name, password and the highest score.
   
    
   3. Dynamic memory management:
   
   - In the ScoringMode.cpp. We created a dynamic array `Playerlist`. Using `new` operator to allocate memory for the struct objects. Pointers are used to store these memory addresses. We increase the size of `Playerlist` when a new user register the game.
    
   4. File input/output:
    
   - File Input: In scoring mode. Before the game begin, we input all information stored in `User_Info txt` to `Playerlist`
    
   - File Output: In scoring mode. After the game is over, the `Playerlist` will be updated automatically with the name, password current highest score. All the records will be saved in `User_Info txt`. 
    
   5. Program codes in multiple files:
        - `gp.h`: Concludes all the functions we used.
        - `main.cpp`: The entrance of the game and welcome the players.
        - `MainPage.cpp`: The mainpage of the game, let players to choose next step.
        - `ClassicMode.cpp`: The implementation of Classic Mode of the game.
        - `ScoringMode.cpp`: The implementation of Scoring Mode of the game.
        - `DisplayClassic.cpp`: Drawing of the hangman in classic mode.
        - `DisplayScoring.cpp`: Drawing of the hangman in scoring mode.
        - `Menu.cpp`: Display the introduction and rules of the game.
        - `RandomWord.cpp`: Choose a random word from the word banks.
        - `Oxford_01.txt`: Contains words with 5 characters in the range of Oxford.
        - `Oxford_02.txt`: Contains words with 6 characters in the range of Oxford.
        - `Oxford_03.txt`: Contains words with 7 characters in the range of Oxford.
        - `IELTS_01.txt`: Contains words with 5 characters in the range of IELTS.
        - `IELTS_02.txt`: Contains words with 6 characters in the range of IELTS.
        - `IELTS_03.txt`: Contains words with 7 characters in the range of IELTS.
        - `GRE_01.txt`: Contains words with 5 characters in the range of GRE.
        - `GRE_02.txt`: Contains words with 6 characters in the range of GRE.
        - `GRE_03.txt`: Contains words with 7 characters in the range of GRE.
        - `User_Info.txt`: Stores the information of players
  
   6. Proper indentation and naming styles
   
   - To ensure readability, we use the proper indentation and naming styles.
  
   7. In-code documentation

## Compilation instruction
    
   - `make main`: compile main with all functions.
   - `./main`: Execute the game.
   - `make clean`: remove the built files.

## Video link
   `https://youtu.be/ITAVtdp0kHs`
