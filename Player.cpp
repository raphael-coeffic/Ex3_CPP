/**
 * 337614747
 * racoeffic@gmail.com
 */
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace ex3 { 
    
    Player::Player (int playerNum) : ressoucrcesByDice(13){
        this->playerNum = playerNum;
        this->knights = 0;
        this->init();
    }
    void Player::init(){
        this->points = 0;
        this->resources.resize(5,0);
    }

    int Player::getPoints() {return this->points;} 
    void Player::addPoint(int num) {this->points += num;}

    void Player::rollDice(Game& game) {
        if (this->rolled) {
            throw std::invalid_argument("You can't roll the dices more than 1 time");
        }
        else {
            srand(time(nullptr));

            // rando from 1 to 6
            int die1 = std::rand() % 6 + 1;
            int die2 = std::rand() % 6 + 1;
            this->rolled = true;
            int total = die1+die2;

            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < game.getPlayer(i)->getPlaces().size(); j++)
                {
                    if (game.getPlayer(i)->getPlaces()[j].getNum() == total)
                    {
                        this->addResources(1, game.getPlayer(i)->getPlaces()[j].getType());
                    }
                    
                }
                
                
            }
            

        }
        
    }

    void Player::addResources(int num, string type) {
        if (type == "wheat") this->resources[0]+=num;
        else if(type == "rock") this->resources[1]+=num;
        else if(type == "brick") this->resources[2]+=num;
        else if(type == "lumber") this->resources[3]+=num; //bois
        else if(type == "sheep") this->resources[4]+=num;
        else printf("NO RESSOURCE\n");
    }

    void Player::endTurn(){
        this->rolled = false;
        if (this->points >= 10)
        {
            printf("The game is finish, Player number %d win.\n", this->playerNum);
        }
        
    }

    void Player::buildRoad(int start, int end, Game& game, bool first) {
        if (start > 53 || end > 53) {
            throw std::invalid_argument("Invalid index for edge.");
        }
        if ((this->resources[2] <= 0 || this->resources[3] <= 0) && !first)
        {
            throw std::invalid_argument("You don't have enough ressources for building road.");
        }
        else {
            if (game.getBoard().getEdges()[static_cast<size_t>(start)][static_cast<size_t>(end)] == -10){
                throw std::invalid_argument("The board doens't countain edge between the two index");
            }
            else if (game.getBoard().getEdges()[static_cast<size_t>(start)][static_cast<size_t>(end)] != -1)
                throw std::invalid_argument("The localisation of this edge is occuped");
        
            if (!havePath(start,game.getBoard()) && !havePath(end,game.getBoard()))
            {
                bool b = false;
                if (game.getBoard().getCorner()[start].getOwner() == playerNum || game.getBoard().getCorner()[end].getOwner() == playerNum)
                    b = true;
                
                if (b == false) 
                    throw std::invalid_argument("You don't have path for build road in this place");
             
            }
            if (!first)
            {
                this->resources[2]--;
                this->resources[3]--;
            }
            
            game.getBoard().setEdge(start, end, this->playerNum);
            printf("BUILD ROAD\n");
            
        }
         
    }
    bool Player::havePath(int vertice, Board& board) {
        for (size_t i = 0; i < 54; i++)
        {
            if (board.getEdges()[static_cast<size_t>(vertice)][i] == this->playerNum)
                return true;
        }
        return false;
    }

    void Player::buildVillage(int vertice, Game& game, bool first) { // if it is the beggin please enter true
        if (vertice > 54) {
            throw std::invalid_argument("Invalid index for village");
        }
        
        if (this->havePath(vertice, game.getBoard()) == false && first == false) 
            throw std::invalid_argument("You don't have path for build in this place");

        for (size_t i = 0; i < 54; i++)
        {
            if (game.getBoard().getEdges()[static_cast<size_t>(vertice)][i] != -10 && game.getBoard().getCorner()[i].getType() != 0)
                throw std::invalid_argument("You are too close from an another village or town");
            
        }
        
        int t = game.getBoard().getCorner()[static_cast<size_t>(vertice)].getType();
        if (t != 0) {
            throw std::invalid_argument("The localisation of this vertice is occuped");
        }
        
        
        
        if(!first) {
            if (this->resources[2] <= 0 || this->resources[3] <= 0 || this->resources[0] <= 0 || this->resources[4] <= 0)
            {
                throw std::invalid_argument("You don't have enough ressources for building village.");
            }
            this->resources[1]--;
            this->resources[2]--;
            this->resources[0]--;
            this->resources[4]--;
            game.getBoard().setCorner(vertice, 1);
            game.getBoard().getCorner()[vertice].setOwner(this->playerNum);
            

            this->addPoint(1);
            printf("BUILD VILLAGE\n");
        }
            
        else
        {
            for (size_t i = 0; i < game.getBoard().getCorner()[vertice].getNeighbors().size(); i++)
            {
                this->addResources(1, game.getBoard().getPlaces()[game.getBoard().getCorner()[vertice].getNeighbors()[i]].getType());
            }
            game.getBoard().setCorner(vertice, 1);
            game.getBoard().getCorner()[vertice].setOwner(this->playerNum);
            this->addPoint(1);
            
            printf("BUILD VILLAGE OF BEGINNING\n");
        }
        for (size_t i = 0; i < game.getBoard().getCorner()[vertice].getNeighbors().size(); i++)
        {
            this->places.push_back(game.getBoard().getPlaces()[game.getBoard().getCorner()[vertice].getNeighbors()[i]]);
        }
        
    
    }

    void Player::buildTown(int vertice, Game& game) { // if it is the beggin please enter true
        if (vertice > 54) {
            throw std::invalid_argument("Invalid index for town");
        }
        

        if (this->resources[1] < 3 || this->resources[0] < 2)
        {
            throw std::invalid_argument("You don't have enough ressources for building town.");
        }
        int t = game.getBoard().getCorner()[static_cast<size_t>(vertice)].getType();
        if (t == 0 || game.getBoard().getCorner()[static_cast<size_t>(vertice)].getOwner() != this->playerNum) {
            throw std::invalid_argument("You don't have a village in this vertice");
        }
        if (t == 1) {
            this->resources[1]-=3;
            this->resources[0]-=2;
            game.getBoard().setCorner(vertice, 2);
            this->addPoint(1);
            printf("BUILD TOWN\n");
            for (size_t i = 0; i < game.getBoard().getCorner()[vertice].getNeighbors().size(); i++)
        {
            this->places.push_back(game.getBoard().getPlaces()[game.getBoard().getCorner()[vertice].getNeighbors()[i]]);
            
        }
        
        }

    }
    int Player::translateRessource(string type) {
        if (type == "wheat") return 0;
        else if(type == "rock") return 1;
        else if(type == "brick") return 2;
        else if(type == "lumber") return 3; //bois
        else if(type == "sheep") return 4;
        else throw std::invalid_argument("Invalid ressource");
        
    }

    void Player::exchange(int num1, string ressource1, int num2, string ressource2, Player& p) {
        int type1 = translateRessource(ressource1);
        int type2 = translateRessource(ressource2);
        if (this->resources[type1] < num1 || p.getRessources()[type2] < num2)
        {
            throw std::invalid_argument("You don't have enough ressources");
        }
        else {
            this->resources[type1] -= num1;
            p.getRessources()[type1] += num1;
            this->resources[type2] += num2;
            p.getRessources()[type2] -= num2;
        }
    }

    void Player::buyDevCard(Game& game) {
        if (this->resources[1] <= 0 || this->resources[0] <= 0 || this->resources[4] <= 0)
        {
            throw std::invalid_argument("You don't have enough ressources for buy development card.");
        }
        
        if (game.haveDevCard())
        {
            DevelopmentCard* card = game.getDevCard();
            if (card->getType() == "Monopol") monopol_num++;
            if (card->getType() == "Knight") knight_num++;
            if (card->getType() == "RichYear") richYear_num++;
            if (card->getType() == "ConstructRoad") constructRoad_num++;
            if (card->getType() == "VictoryPoint") victoryPoint_num++;
            devCards.push_back(card);
        }
        else {
            throw std::invalid_argument("The players buy all the dev cards");
        }
    }

    void Player::helpUseDevCard(const std::string& type, Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2) {
        for (auto it = devCards.begin(); it != devCards.end(); ++it) {
            if ((*it)->getType() == type) {
                (*it)->use(type, *this, game, ressourceMonopol, start1, end1, start2, end2, ressource1, ressource2);
                delete *it;
                devCards.erase(it);
                return;
            }
        }
        printf("You dont have the %s card\n", type.c_str());
        // throw std::invalid_argument("You dont have the %s card\n", type.c_str());
    }

    void Player::useDevCard(const std::string& type, Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2) {
        if (type == "Monopol" && monopol_num >= 0) 
            helpUseDevCard("Monopol", game,ressourceMonopol, start1, end1, start2, end2, ressource1, ressource2);
        else if (type == "Knight" && knight_num >= 0)
            helpUseDevCard("Knight", game,ressourceMonopol, start1, end1, start2, end2, ressource1, ressource2);
        else if (type == "RichYear" && richYear_num >= 0)
            helpUseDevCard("RichYear", game,ressourceMonopol, start1, end1, start2, end2, ressource1, ressource2);
        else if (type == "ConstructRoad" && constructRoad_num >= 0)
            helpUseDevCard("ConstructRoad", game,ressourceMonopol, start1, end1, start2, end2, ressource1, ressource2);
        else if (type == "VictoryPoint" && victoryPoint_num >= 0)
            helpUseDevCard("VictoryPoint", game,ressourceMonopol, start1, end1, start2, end2, ressource1, ressource2);


    }



    
}