# PIC10C-Assignment-1
Homework 1 for Spring 2017 PIC10C

   Earvin Mosca  
   April 21, 2017  

   The program runs the game "Siete y Medio"  
   and records the rounds played in   
   "gamelog.txt".  

The goal of the game is to get cards whose total value comes the closest to 71/2 without going over it. Getting a card total over 7 1/2 is called "busting". 

When a player makes a bet against the dealer. There are 4 possible outcomes:

1. The player comes closer to 7 1/2 than the dealer or the dealer busts but the player did not bust. In this case the player wins the round and the player's money increases by the amount that was bet.
1. The dealer comes closer to 7 1/2 than the player, or the player busts.In this case the player loses the round and the player's money decreases by the amount that was bet.
1. Both, the player and dealer bust.In this case the player loses the round and the player's money decreases by the amount that was bet. This is called house advantage. 
1. Both the player and the dealer have the same total and  they do not bust.In this case a tie is declared and no money is exchanged.
