# EX3 (CATAN) IN C++

_Author: Raphael Coeffic, 337614747, racoeffic@gmail.com_

In this project, I implemented a version of the game Catan.

I implemented the rules like the rules of the readme of the project. All the project is based on a structure of the map by corners(we have 54 corners) and places (19). The corners are connected like in the real map of the game. This structure have this appearance:

                  1      3      5
                /   \  /   \  /   \
              0      2       4     6
              |  #0  |   #1  | #2  |
             29     31      33     7
            /   \  /   \   /   \  /   \
          28     30     32      34      8
          |  #3  |   #4  |   #5  |  #6  |
          27     47     49       35     9
        /    \  /   \  /   \   /   \  /   \
      26      46     48     50      36     10
      |  #7   |   #8  |  #9  |  #10  | #11  |
      25      45     53     51      37      11
       \    /   \   /  \   /  \    /  \    / 
         24      44     52      38      12
         |   #12  | #13  |  #14  |  #15  |
         23      43     41      39      13
          \     /   \  /   \   /   \   / 
             22      42     40      14
             |   #16 |  #17  |  #18  |
             21      19      17      15
              \    /    \   /   \   /
                20        18      16

I imlemented a lot of class for this project and this is their explications:

## Corner:
The files of the object `Corner` give us the option for each corner of the map to save the owner of the corner or to know if he is free, to know each type of construction do he countain and the most important, we can know each place do the corner touch for know each ressource do we can receive.

## Place:
The files of the object `Place` help us to stock the value (for the dice) that the place receive and him element.

## Player :
The files of the object `Player` are very importants because we do by them all the actions of the players and stock their ettributes like developent card that the player buy, the  num of points... We use this class for effectuate all the actions of the player and a lot of actions of the game like all the type of building(roads, village...) and for execute exchange between the players.

## Development card:
In this file, I implented the logic of the cards and implemented all the subclass by heritage of the main one. I also implemented here the using of these cards.

## Board:
For build the `board`, we use a **Singleton** because we want only one instance of board for our game and we don't want to have errors because of this. This object is finally the most important one because he implemtn the map of the game and can change the values of the map with the actions of the players.

## Game:
This file implemented the union for the exercice for play with all the functions of the game. He is countain the board and the players fo the game. He also stock the dev card of the game.

Finally, I also implemented a `catan.cpp` that run like in the demo an example of a turn of the game,a `Makefile` and a `test.cpp` that test the main functions of the project.
For compile the project please enter `make`, for only the example of demo `catan.cpp` and for only the tests `make test`
For run please enter  `./catan` or `./test`.
