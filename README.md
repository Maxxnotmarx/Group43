# Group43

1. Group Members:

    He Ziyi (3035864003)
    Ma Xinyue (3035946198)
    Zhou Zihan (3035947843)

2. Game Discirption:

    This is a single-player game inspired by the world classic guessing game Hangman (For reference: https://en.wikipedia.org/wiki/Hangman_(game)), in which there are two parties, the one who gives out the word is the computer, and the one who guesses the word is the player. We have 2 different modes of playing that one can choose to play with: 1) Classic Mode and 2) Scoring Mode.

3. Game Rules:

  1) Mainpage:

      A main page with the following functions:

      i) Menu(M): Check game rules inside the game.

      ii) Enter(E): Enter the game, followed by the options of game mode.

      iii) Quit(Q): Quit the game/ End the running program.

  
  2) Classic Mode:

     In each round of play, the player's goal is to correctly guess the word provided by the computer so as to save the little man from being hanged to death, therefore, there are only two results at the end of each round: i) One successfully comes up with the word and the little man is saved, aka "You Win"; ii) The player fails to guess the word, and the little man is hanged, aka "You Lose".
     
     Another thing worth mentioning is the drawing steps of the little man, every time the player guesses a wrong character, one penalty will be imposed.
     
                    0 Penalty(start)     1 Penalty           2 Panalties       3 Panalties      Panalties(lose)
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

     In this mode, the player has three options of where the word comes from: i) Oxford 3500; ii) IELTS; iii) GRE, the above vocabularies are levels of words that corresponds with one's level of study, which are High School, Undergraduate and Postgraducate respectively. Under each vocabularies, the player can choose words of three different lengthes: i) 5 character-long; ii) 6 character-long; iii) 7 character-long. Once the player finishes choosing the vocabularies and length of the word, the guessing game begins!

      i) Hint(?): Player has unlimited chances of obtaining a hint, which will directly fill one character of the word in the blank each time, press "?" to do so. However, the player is not suggested to use too many of them in order to keep the game being challenging.
      
      ii) Quit(Q): The player can quit the game any time during the on-going round of guess, press "Q" to do so.

      iii) Return(R): Return to the Mainpage, but current game status will not be saved.

      iv) Guess(a-z): Guess should be inputted with lower case of the character.

      v) Invalid Input: Any input that does not match with the above inputs of command, the program will let you input again.
      
   
   3) Scoring Mode:


