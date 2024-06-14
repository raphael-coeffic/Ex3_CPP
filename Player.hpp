/**
 * 337614747
 * racoeffic@gmail.com
 */
#include <string>
#include <vector>
#include "Board.hpp"
#include "Game.hpp"
#include "DevelopmentCard.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

using namespace std;
namespace ex3 {
    class Game;
}
namespace ex3 {
    class Board;
}
namespace ex3 {
    class DevelopmentCard;
}
namespace ex3 {
    class Player
    {
    private: 
        int knights; // number of knights and if the player have 3 he receive 2 points
        int playerNum; //id
        int points; 
        bool rolled = false;
        vector <int>resources; //0: wheat, 1: rock, 2: brick, 3: lumber, 4: sheep
        bool havePath(int vertice, Board& board);
        vector <Place>places;
        vector <std::string> ressoucrcesByDice;
        vector <DevelopmentCard*> devCards;
        // num of each type of dev card
        int monopol_num;
        int knight_num;
        int richYear_num;
        int constructRoad_num;
        int victoryPoint_num;
        



    public:
        Player(int playerNum);
        void addPoint(int num);
        int getPlayerNum () {return this->playerNum;} //id
        int getPoints(); //of victory
        void rollDice(Game& game);
        void endTurn();
        vector <int>& getRessources() {return this->resources;} 
        void addResources(int num, string type);
        void buildRoad(int start, int end, Game& game, bool first=false); //enter true if it is the beginning of the game
        void buildVillage(int vertice, Game& game, bool first=false);//enter true if it is the beginning of the game
        void buildTown(int vertice, Game& game);
        int translateRessource(string type); //translate from name of ressource to his num id
        // this give num1 ressources of ressource1 to p and receive num2 of ressource2
        void exchange(int num1, string ressource1, int num2, string ressource2, Player& p); 
        void addKnights(){this->knights++;}
        int getKnights(){return this->knights;}
        void buyDevCard(Game& game);
        //for each card can use by his specific using
        void useDevCard(const std::string& type, Game& game, string ressourceMonopol="", int start1=0, int end1=0, int start2=0, int end2=0, string ressource1="", string ressource2="");
        void helpUseDevCard(const std::string& type, Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2);
        void init();
        vector <Place> getPlaces() {return this->places;}
        // int getNumOfPlaces(int index) {return this->num_for_places[index];}
        // void addNumOfPlaces(int n, int index) {this->num_for_places[index]+=n;}
        
    };
    
    
}



#endif