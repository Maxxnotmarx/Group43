# Group43

1. Group Members:

    He Ziyi (3035864003)
    Ma Xinyue (3035946198)
    Zhou Zihan (3035947843)

2. Game Discirption:

    This is a single-player game inspired by the world classic guessing game Hangman (For reference: https://en.wikipedia.org/wiki/Hangman_(game)), in which there are two parties, the one who gives out the word is the computer, and the one who guesses the word is the human player. We have 2 different modes of playing that one can choose to play with: 1) Classic Mode and 2) Scoring Mode.

3. Game Rules:

  1) Mainpage:

      A main page with the following functions:

      i) Menu(M): Check game rules inside the game.

      ii) Enter(E): Enter the game, followed by the options of game mode.

      iii) Quit(Q): Quit the game/ End the running program.

  
  2) Classic Mode:

     In each round of play, the player's goal is to correctly guess the word randomly generated by the program so as to save the little man from being hanged to death, therefore, there are only two results at the end of each round: i) One successfully comes up with the word and the little man is saved, aka "You Win"; ii) The player fails to guess the word, and the little man is hanged, aka "You Lose".
     
     Another thing worth mentioning is the drawing steps of the little man, every time the player guesses a wrong character, one penalty will be imposed.
     
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

     In this mode, the player has three options of where the word comes from: i) Oxford 3500; ii) IELTS; iii) GRE, the above vocabularies corresponds with one's level of study, which are High School, Undergraduate and Postgraducate respectively. Under each vocabularies, the player can choose words of three different lengthes: i) 5 character-long; ii) 6 character-long; iii) 7 character-long. Once the player finishes choosing the vocabularies and length of the word, the guessing game begins!

Commands for lines of input:

      i) Hint(?): Player has unlimited chances of obtaining a hint, which will directly fill one character of the word in the blank each time, press "?" to do so. However, the player is not suggested to use too many of them in order to keep the game challenging.
      
      ii) Quit(Q): Quit the game any time during the on-going round of guess

      iii) Return(R): Return to the Mainpage, current game status will not be saved.

      iv) Guess(a-z): Guess should be inputted with lower case of the character.

      v) Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
   
   3) Scoring Mode:

      In this playing mode, you will need to create an acount for the game to store your scores of each round of playing. There is not a specific definition of "win" or "Lose" in the mode, as the name of the mode itself descirbes, this is a mode where your scores acummulates as you make it to guess out more characters, with each correct character being guessed correctly counting for 3 marks, and you have 15 chances of guessing in total and 5 hints to request for, so your target in each round is to guess as many words as possible with allowing penalties and hints you possess. Finally, you will be able to see your scores at the end of each round, you can also check out the ranking displaying every users' highest scores in descending order.

       There will be 3 little mans being hanged up at the end of each round, it looks something like the following:
       
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
        
        It takes 6 steps, 5 steps and 4 steps to draw the man from the right, the girl in the middle and the boy from the left respectively. It's alright if you cannot memorize how these little man are drawed, becasue you will be informed the guessing chance left every time you guess out a correct word. And there will be a loop of fixed order of vocabularies from which the word in each round is generated: 1-3: Oxford 3500 5-7 characted-long word; 4-6: IELTS 5-7 characted-long word; 7-9: IELTS 5-7 characted-long word. As you can see, the difficulty of guessing out the word increases as you guess out more words.     
        
Commands for lines of input:

      i) Hint(?): Player has 5 hints in total, function the same as the one in Classic Mode.
      
      ii) Quit(Q): Quit the game any time during the on-going round of guess, current score will not be saved.

      iii) Return(R): Return to the Mainpage, current game status and current socre will not be saved.

      iv) Guess(a-z): Guess should be inputted with lower case of the character.
      
      v) Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
4. Features(Coding Requirement):
    
    1) Generation of random game sets:
    
    2) Data structures for storing game status:
    
    3) Dynamic memory management:
    
    4) File input/output:
    
    5) Program codes in multiple files:
