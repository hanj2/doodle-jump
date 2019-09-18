
#Development.md . 
April 13. 
Self-studied the library SFML by watching youtube videos. 
Successfully set the path to run openframework project with SFML external library. 

April 14.
Created a main.cpp trying to set up a simple example of a doodle jump game. 
Found some images online for background, character and platforms for the game. 
Learned from a youtube video “16 easy c++ games” the function of the gravity.
Got the idea to open a blank window of SFML library but met some problems about loading images from file. 

April 15.
Went to the offices hour for help. The TA told me I set all draw() methods after closing the window. 
After rewrite the draw methods inside the for loop with window.close() at the end, the images can be loaded and displayed successfully. 
Set the background and made the doodler jump later.

April 16.
Created the keyboard method to control the character. 
However, forgot to implement the function after declaration so it didn’t work, so I just wrote all functions inside the main method. 
Set a monster and change the position of it randomly, create another type of platform with spring and update the checkbound  method.

April 20.
Found out the method to update the image by updating sf::texture so that was able to change the cloth of the character. 
Tried to set the situation to deal with the character falling on the ground but did not know how to make the condition. 
Tried when (character.y_value < 0) but it doesn’t work. Create the platform of cracked wood.

April 21.
Learned from Stackoverflow to sf::text to show message with the font I downloaded online to print out message on the screen. 
At first, the program kept complaining about sf::color could not be set so the text message was in write. 
Later fixed the problem by define a ignore message at the beginning of the cpp file.
The character is still not able to die when it should be. 

April 22.
Went to the office hours and TA told me the x and y of computer graph was (0 , 0) on the left top of the screen of the window
so instead of setting the dead condition to be (y<0) I should try something like(y>height – const num).
He taught me how to check the height by print it on the screen. Finally, my doodler is able to die! 
Added the score and height of the character and kept track of those values.

April 23.
Created a header file to store all structures of the game but was not able to implement the functions in a matched GameMachine.cpp file. 
Tried to restart the game after the death of player but got an infinite loop and unable to clear the window board.

April 24.
Went to the office hours and TA told me to write define and endif at the beginning and the end of my header file of GameMachine. 
Also, he told me since all my variables are in main.cpp and are global, 
the program gets confused when I was trying to implement functions in GameMachine.cpp. 
I set a class called GameMachine and stored all structures and functions in the class.
OOP made me implemented and moved functions from main.cpp to GameMachine.cpp successfully. 
Got rid of the infinite loop and was able to restart the game automatically. 
Added a structure of Timer to keep track of the time. 

April 25.
Added the function to update the level and costume of the character. 
In the afternoon just two hours before the code review, my computer broke down.
Warning: JUST DO NOT BUY ANY PRODUCT FROM MICROSOFT; this company REALLY enjoys drinking blood and tears of little-experienced technical students and their website won’t teach u how to solve the problem at all but force u to call them and pay for fee to request technical help :D

April 27.
Added the score machine to set the structure to print the score into a txt.file later.

April 29.
Added a new feature to keep track of the doodler's lives.

May 1
Made some functions of game logic testable and set the test cases.
