/**
 * 337614747
 * racoeffic@gmail.com
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include "Game.hpp"
#include "DevelopmentCard.hpp"
#include <string>

using namespace ex3;

TEST_CASE("Road") {
    Game g;
    
    CHECK_THROWS(g.getPlayer(0)->buildRoad(0,5,g)); // invalid index of roads on the map
    CHECK (g.getBoard().getEdges()[0][5] == -10);
    CHECK_THROWS(g.getPlayer(0)->buildRoad(0,1,g)); // don't have path to this place
    CHECK (g.getBoard().getEdges()[0][1] == -1);

    g.getPlayer(0)->buildVillage(31,g,true);
    g.getPlayer(0)->buildVillage(45,g,true);
    g.getPlayer(0)->buildRoad(45,44,g,true);
    g.getPlayer(0)->buildRoad(31,32,g,true);
    CHECK (g.getBoard().getEdges()[45][44] == 0);
    CHECK (g.getBoard().getEdges()[44][45] == 0);

    g.getPlayer(0)->buildRoad(44,43,g); 
    CHECK_THROWS(g.getPlayer(0)->buildRoad(43,42,g)); //don't have ressource
    CHECK (g.getBoard().getEdges()[44][43] == 0);

    g.getPlayer(0)->addResources(1,"lumber"); // for the example
    g.getPlayer(0)->addResources(1,"brick"); // for the example
    CHECK_THROWS(g.getPlayer(0)->buildRoad(60,43,g)); // out of the map
    CHECK_THROWS(g.getPlayer(0)->buildRoad(44,43,g)); // occuped, can see in output

    printf("Next tests\n\n");
}


TEST_CASE("Village") {
    Game g;

    g.getPlayer(0)->buildVillage(31,g,true);
    g.getPlayer(0)->buildVillage(45,g,true);
    g.getPlayer(0)->buildRoad(45,44,g,true);
    g.getPlayer(0)->buildRoad(31,32,g,true);
    CHECK (g.getBoard().getCorner()[31].getOwner() == 0); // build village

    CHECK (g.getPlayer(0)->getPoints() == 2); // check the num of victory points

    CHECK_THROWS(g.getPlayer(0)->buildVillage(60,g)); // out of the map

    g.getPlayer(0)->addResources(3,"lumber"); // for the example
    g.getPlayer(0)->addResources(3,"brick"); // for the example
    g.getPlayer(0)->addResources(1,"wheat"); // for the example
    g.getPlayer(0)->addResources(1,"sheep"); // for the example

    g.getPlayer(0)->buildRoad(44,43,g); 
    g.getPlayer(0)->buildRoad(43,42,g);

    CHECK_THROWS(g.getPlayer(0)->buildVillage(45,g)); // occuped, can see in output
    CHECK (g.getPlayer(0)->getPoints() == 2);
    g.getPlayer(0)->buildVillage(42,g);
    CHECK (g.getPlayer(0)->getPoints() == 3); // test receptiion of point
    CHECK (g.getBoard().getCorner()[42].getOwner() == 0);
  
}
void rollll(Game& g){
    g.getPlayer(0)->rollDice(g); 
    g.getPlayer(0)->endTurn();
    g.getPlayer(1)->rollDice(g); 
    g.getPlayer(1)->endTurn();
    g.getPlayer(2)->rollDice(g); 
    g.getPlayer(2)->endTurn();
}
TEST_CASE("Dice") {
    Game g;

    g.getPlayer(0)->buildVillage(31,g,true);
    g.getPlayer(0)->buildVillage(45,g,true);
    g.getPlayer(0)->buildRoad(45,44,g,true);
    g.getPlayer(0)->buildRoad(31,32,g,true);
    CHECK (g.getBoard().getCorner()[31].getOwner() == 0); // build village
    g.getPlayer(0)->addResources(3,"lumber"); // for the example
    g.getPlayer(0)->addResources(3,"brick"); // for the example
    g.getPlayer(0)->addResources(1,"wheat"); // for the example
    g.getPlayer(0)->addResources(1,"sheep"); // for the example
    g.getPlayer(0)->buildRoad(44,43,g); 
    g.getPlayer(0)->buildRoad(43,42,g);
    g.getPlayer(0)->buildVillage(42,g);
    CHECK (g.getBoard().getCorner()[42].getOwner() == 0);
    g.getPlayer(0)->addResources(3,"lumber"); // for the example
    g.getPlayer(0)->addResources(3,"brick"); // for the example
    g.getPlayer(0)->addResources(1,"wheat"); // for the example
    g.getPlayer(0)->addResources(1,"sheep"); // for the example



    int precedent = 0;
    for (size_t i = 0; i < 5; i++)
        precedent += g.getPlayer(0)->getRessources()[i];
    
    // check that we receive ressources from the exit of the dices
    for (size_t i = 0; i < 100; i++)
        rollll(g);
    
    
    int current = 0;
    for (size_t i = 0; i < 5; i++)
        current += g.getPlayer(0)->getRessources()[i];
    printf("%d \n", current);
    CHECK (current >= precedent);
    g.getPlayer(0)->rollDice(g); 
    CHECK_THROWS(g.getPlayer(0)->rollDice(g)); // roll twice


    
}

TEST_CASE("Town") {
    Game g;

    g.getPlayer(0)->buildVillage(31,g,true);
    g.getPlayer(0)->buildVillage(45,g,true);
    g.getPlayer(0)->buildRoad(45,44,g,true);
    g.getPlayer(0)->buildRoad(31,32,g,true);
    int pre = g.getPlayer(0)->getPlaces().size();
    g.getPlayer(0)->addResources(2,"wheat"); // for the example
    g.getPlayer(0)->addResources(3,"rock"); // for the example
    CHECK_THROWS(g.getPlayer(0)->buildTown(20,g)); // can't build if not village
    g.getPlayer(0)->buildTown(45,g);
    
    int current = g.getPlayer(0)->getPlaces().size();
    CHECK (pre < current);
    CHECK (9 == current);

    CHECK (g.getPlayer(0)->getPoints() == 3);
}

TEST_CASE("Development Card") {
    Game g;
    //init players and their ressources
    ConstructRoad constructRoadCard;
    g.getPlayer(0)->buildVillage(31,g,true);
    g.getPlayer(0)->buildVillage(45,g,true);
    g.getPlayer(0)->buildRoad(45,44,g,true);
    g.getPlayer(0)->buildRoad(31,32,g,true);
    CHECK_NOTHROW(constructRoadCard.use(g, *g.getPlayer(0), 44, 43, 43, 42));
    g.getPlayer(0)->addResources(3, "wheat");
    g.getPlayer(1)->addResources(2, "wheat");
    g.getPlayer(2)->addResources(1, "wheat");
    g.getPlayer(0)->addResources(2, "lumber");
    g.getPlayer(0)->addResources(2, "brick");
    //Monopol
    Monopol monopolCard;
    CHECK_NOTHROW(monopolCard.use(g, *g.getPlayer(0), "wheat"));
    CHECK(g.getPlayer(0)->getRessources()[0] == 7);
    CHECK(g.getPlayer(1)->getRessources()[0] == 0);
    CHECK(g.getPlayer(2)->getRessources()[0] == 0);

    //construct roads
    CHECK_NOTHROW(constructRoadCard.use(g, *g.getPlayer(0), 42, 41, 41, 40));

    // check the roads
    CHECK(g.getBoard().getEdges()[42][41] == 0);
    CHECK(g.getBoard().getEdges()[41][40] == 0);

    // rich year
    RichYear richYearCard;
    CHECK_NOTHROW(richYearCard.use(*g.getPlayer(0), "wheat", "rock"));

    // check that we receive the ressources
    CHECK(g.getPlayer(0)->getRessources()[0] == 8); // wheat
    CHECK(g.getPlayer(0)->getRessources()[1] == 2); // rock

    g.getPlayer(1)->addResources(20,"lumber"); // for the example
    g.getPlayer(1)->addResources(20,"brick"); // for the example
    g.getPlayer(1)->addResources(20,"wheat"); // for the example
    g.getPlayer(1)->addResources(20,"sheep"); // for the example
    g.getPlayer(1)->addResources(20,"rock"); // for the example
    //the player buy all the cards
    for (size_t i = 0; i < 16; i++)
    {
        g.getPlayer(1)->buyDevCard(g);
    }
    CHECK_THROWS(g.getPlayer(1)->buyDevCard(g));

    //receive two points by 3 knights
    g.getPlayer(1)->useDevCard("Knight",g);
    g.getPlayer(1)->useDevCard("Knight",g);
    g.getPlayer(1)->useDevCard("Knight",g);
    CHECK(g.getPlayer(1)->getPoints() == 2);

    
}


