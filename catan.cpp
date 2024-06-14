/**
 * 337614747
 * racoeffic@gmail.com
 */
#include "Board.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
using namespace ex3;

int main() {
    Game g;
        
    // placements of player 0
    g.getPlayer(0)->buildVillage(31,g,true);
    g.getPlayer(0)->buildVillage(45,g,true);
    g.getPlayer(0)->buildRoad(45,44,g,true);
    g.getPlayer(0)->buildRoad(31,32,g,true);
    printf("%d \n", g.getPlayer(0)->getPoints());

    // placements of player 1
    g.getPlayer(1)->buildVillage(34,g,true);
    g.getPlayer(1)->buildVillage(41,g,true);
    g.getPlayer(1)->buildRoad(41,40,g,true);
    g.getPlayer(1)->buildRoad(33,34,g,true);
    printf("%d \n", g.getPlayer(1)->getPoints());

    // placements of player 2
    g.getPlayer(2)->buildVillage(43,g,true);
    g.getPlayer(2)->buildVillage(39,g,true);
    g.getPlayer(2)->buildRoad(39,38,g,true);
    g.getPlayer(2)->buildRoad(43,42,g,true);
    printf("%d \n", g.getPlayer(2)->getPoints());

    // player 0 playing
    g.getPlayer(0)->rollDice(g);
    try
    {
        g.getPlayer(0)->rollDice(g);// You can't roll the dices more than 1 time
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        g.getPlayer(0)->buildRoad(41,40,g); // this place is occuped can't build
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    g.getPlayer(0)->endTurn();

    // player 1 playing
    g.getPlayer(1)->rollDice(g);
    g.getPlayer(1)->exchange(1,"rock",1,"lumber",*g.getPlayer(2));
    g.getPlayer(1)->exchange(0,"rock",0,"brick",*g.getPlayer(2));
    g.getPlayer(1)->addResources(1,"wheat"); // for the example
    g.getPlayer(1)->addResources(1,"sheep"); // for the example
    g.getPlayer(1)->addResources(1,"rock"); // for the example
    g.getPlayer(1)->buyDevCard(g);
    // you only can use what you receive
    g.getPlayer(1)->useDevCard("Monopol", g, "lumber");
    g.getPlayer(1)->useDevCard("VictoryPoint", g);
    g.getPlayer(1)->useDevCard("RichYear", g,"",0,0,0,0,"lumber","brick");
    g.getPlayer(1)->useDevCard("ConstructRoad", g,"",33,4,4,3);
    g.getPlayer(1)->useDevCard("Knight", g);
    g.getPlayer(1)->buildRoad(33,4,g);
    g.getPlayer(1)->buildRoad(3,4,g);
    g.getPlayer(1)->addResources(1,"lumber"); // for the example
    g.getPlayer(1)->addResources(1,"brick"); // for the example
    g.getPlayer(1)->buildVillage(3,g);
    g.getPlayer(1)->addResources(1,"lumber"); // for the example
    g.getPlayer(1)->addResources(1,"brick"); // for the example
    g.getPlayer(1)->addResources(1,"wheat"); // for the example
    g.getPlayer(1)->addResources(1,"sheep"); // for the example

    printf("%d \n", g.getPlayer(1)->getPoints());

    g.getPlayer(1)->endTurn();

    // player 2 playing
    g.getPlayer(2)->rollDice(g);
    g.getPlayer(2)->endTurn();

    return 0;
}
