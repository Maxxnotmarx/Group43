# Group43

1. Group Members:

    He Ziyi (3035864003)
    Ma Xinyue (3035946198)
    Zhou Zihan (3035947843)

2. Game Discirption:

    This is a single-player game inspired by the world classic guessing game Hangman (For reference: https://en.wikipedia.org/wiki/Hangman_(game)), in which there are two parties playing, the one who gives out the word is the computer, and the one who guesses the word is the human player. We have 2 different modes of playing that one can choose to play with: 1) Classic Mode and 2) Scoring Mode.

3. Game Rules:

  1) Mainpage:

      A main page with the following functions:

      i) Menu(M): Check game rules inside the game.

      ii) Enter(E): Enter the game, followed by the options of game mode.

      iii) Quit(Q): Quit the game/ End the running program.

  
  2) Classic Mode:

     In each round of play, the player's goal is to correctly guess out the word randomly generated by the program so as to save the little man from being hanged to death, therefore, there are only two outcomes at the end of each round: i) One successfully comes up with the word and the little man is saved, aka "You Win"; ii) The player fails to guess out the word, and the little man is hanged, aka "You Lose".
     
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

      In this mode, first of all, you will need to create an account for the program to store your scores of each round of playing. In terms of the game outcome, there is not a specific definition of "Win" or "Lose" under this mode, as the name of the mode itself descirbes, this is a mode where your scores acummulates as you succeed to guess out more characters, with each correct character being guessed correctly counting for 3 marks, and you will get extra 2 marks if you get the whole word correctly. You have 15 chances of guessing in total and 5 hints to request for, and your target in each round is to guess as many words as possible with allowed penalties and hints you possess. Finally, you will be able to see your scores at the end of each round, you can also check out the ranking displaying every users' highest scores in descending order.

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
        
        It takes 6 steps, 5 steps and 4 steps to draw the man from the right, the girl in the middle and the boy from the left respectively. It's alright if you cannot memorize how these little man are drawed, becasue you will be able to see guessing chances left every time you guess out a correct word. And there will be a loop in fixed order of dictionaries from which the word in each round is generated: 1-3: Oxford 3500 5-7 characted-long word; 4-6: IELTS 5-7 characted-long word; 7-9: IELTS 5-7 characted-long word. As you can see, the difficulty of guessing out the word increases as you guess out more words.     
        
Commands for lines of input:

      i) Hint(?): Player has 5 hints in total, function the same as the one in Classic Mode.
      
      ii) Quit(Q): Quit the game any time during the on-going round of guessing, current score will not be saved.

      iii) Return(R): Return to the Mainpage, current game status and current socre will not be saved.

      iv) Guess(a-z): Guess should be inputted with lower case of the character.
      
      v) Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
4. Features(Coding Requirement):
    
    1) Generation of random game sets: 
    
    The guessing word is randomly selected from a specific dictionary. Take the Classic Mode for instance, the player can choose the vocabulary the word comes from and its length, but the selection of the word from that specific dictionary that the player choose is random, in which case he or she will not be able to predict what the next word is before he or she starts to guess.
    
    2) Data structures for storing game status:
    In DisplayScoring.cpp and DisplayClassic.cpp, integer times and vector output was used to store the game status by storing wrong times in the integer and the figure of the hang man in the vector. Once the wrong times increase by one, the integer times increase by one, and the vector will be updated the new figure of the hang man.
    In the scoring mode part, we also used a dynamic list to store the players' score to store the game status.
    
    3) Dynamic memory management:
    
    4) File input/output:
    
    i) File Input: 
        The game is supported by 9 dictionaries accroding to the level of study and the word length, thus we seprate all potential words that the player might encounter into 9 .txt files, everytime the player choose the dictionary to guess with, the program will read the specific .txt file and store them in a vector, then a random word will be selected from that vector. With words seperately stored in different files, it is easier and clearer of what to do if one want to add more words supply to the game.
        In order to get the users' information in the scoring mode, we also used file input to read the User_Info.txt line by line and store the information in a dynamic list. So that we can print out the information while the player want to take a look.
    
    ii) File Output:
        After playing the scoring mode game, the player has a new score if his score increased compared to his highest score, and we need to update his score, in the code, we store his new score in the dynamic list and finally output the content in the dynamic list to the User_Info.txt again to update the information of the players. At the same time, we store the rankings into the file.
    
    5) Program codes in multiple files:

    To improve the readabilty of the code and for a better code organization, feature functions are wirtten in separate files. Since we have two modes of playing, the code of each mode are written as functions in separate files. And functions displaying the game status and functions generating a random word are also defined in separate files. With feature functions defined seperately, the programmer can call the function whenever and wherever he needs.
