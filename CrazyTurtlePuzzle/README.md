# crazy-turtles-puzzle-game-solver
Program finds all possible valid combinations of turtle cards in game "Crazy Turtles Puzzle Game".
![turtles](https://github.com/user-attachments/assets/ccfe6978-4490-49c5-87ff-e76f26b13d92)

## Game Rules:
Crazy Turtles Puzzle Game comes with 9 square cards. Each card displayes half of an image (turtle) on every edge. 
The object of the puzzle is to arrange the nine pieces in a 3X3 square where all of the images matched up. 
For example the tail of a turtle would be one card and that would need to match the head of the turtle which was on a different card.

## One solution:
![solved](https://github.com/user-attachments/assets/86da2698-f437-4c22-a12c-0325605c0ef7)

## Details on implementation
For solving the puzzle and achive all possible solutions, backtrack approach has been used.
In the following pictures you can see how the problem is modeled. 
![image](https://github.com/user-attachments/assets/ba718b28-de7d-4b4f-9561-8029f3a4c23c)
![image](https://github.com/user-attachments/assets/8f8b30e1-7f4b-4ca6-ac46-71374010fc90)

rotation 0 = no rotation
rotation 1 = 90 degree in clockwise direction or one steр
rotation 2 = 180 degree in clockwise direction or two steps
rotation 3 = 270 degree in clockwise direction or three steps

Example: 4->1 would mean Card Number 4 that we have
rotate clockwise for 90 degrees


