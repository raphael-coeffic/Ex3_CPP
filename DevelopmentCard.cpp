/**
 * 337614747
 * racoeffic@gmail.com
 */
#include "DevelopmentCard.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace ex3 {

    void Monopol::use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2) {
        this->use(game, owner, ressourceMonopol); 
    }

    void Monopol::use(Game& game, Player& owner, std::string resource) {
        std::cout << "Using Monopol card with resource: " << resource << std::endl;
        int type;
        if (resource == "wheat") type = 0;
        else if(resource == "rock") type = 1;
        else if(resource == "brick") type = 2;
        else if(resource == "lumber") type = 3;
        else if(resource == "sheep") type = 4;
        else throw std::invalid_argument("Invalid resource");
        int total = 0;
        int current = 0;
        for (int i = 0; i < 3; i++) {
            if (i != owner.getPlayerNum()) {
                current = game.getPlayer(i)->getRessources()[static_cast<size_t>(type)];
                game.getPlayer(i)->addResources((current * (-1)), resource);
                total += current;
                current = 0;
            }
        }
        owner.addResources(total, resource);
    }

    void ConstructRoad::use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2) {
        this->use(game, owner, start1, end1, start2, end2); 
    }

    void ConstructRoad::use(Game& game, Player& owner, int start1, int end1, int start2, int end2) {
        std::cout << "Using ConstructRoad card to build roads between: "
                  << start1 << "-" << end1 << " and " << start2 << "-" << end2 << std::endl;
        
        owner.buildRoad(start1, end1, game, true);
        owner.buildRoad(start2, end2, game, true);
    }

    void RichYear::use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2) {
        this->use(owner, ressource1, ressource2);
    }

    void RichYear::use(Player& owner, std::string resource1, string ressource2) {
        std::cout << "Using RichYear card with resources: " << resource1 << " " << ressource2 << std::endl;
        owner.addResources(1, resource1);
        owner.addResources(1, ressource2);

    }

    void Knight::use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2r) {
        this->use(owner); 
    }

    void Knight::use(Player& owner) {
        std::cout << "Using Knight card" << std::endl;
        owner.addKnights();
        if(owner.getKnights() == 3) {
            owner.addPoint(2);
        }
    }

    void VictoryPoint::use(const std::string& type, Player& owner, Game& game, string ressourceMonopol, int start1, int end1, int start2, int end2, string ressource1, string ressource2) {
        this->use(owner); 
    }

    void VictoryPoint::use(Player& owner) {
        std::cout << "Using VictoryPoint card" << std::endl;
        owner.addPoint(1);
    }
}
