/**
 * 337614747
 * racoeffic@gmail.com
 */
#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>
#include "Game.hpp"
#include "Player.hpp"

namespace ex3 {

    class DevelopmentCard {
    public:
        virtual ~DevelopmentCard() = default;
        virtual void use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol="", int start1=0, int end1=0, int start2=0, int end2=0, string ressource1="", string ressource2="") = 0; // Méthode virtuelle pure
        virtual std::string getType() const = 0; // overriding
    };

    class Monopol : public DevelopmentCard { 
    public:
        Monopol() {}
        void use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol="", int start1=0, int end1=0, int start2=0, int end2=0, string ressource1="", string ressource2="") override; // Surcharge de la méthode use
        void use(Game& game, Player& owner, std::string resource); 
        std::string getType() const override { return "Monopol"; }
    };

    class ConstructRoad : public DevelopmentCard {
    public:
        ConstructRoad() {}
        void use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol="", int start1=0, int end1=0, int start2=0, int end2=0, string ressource1="", string ressource2="") override; // Surcharge de la méthode use
        void use(Game& game, Player& owner, int start1, int end1, int start2, int end2); 
        std::string getType() const override { return "ConstructRoad"; } 
    };

    class RichYear : public DevelopmentCard {
    public:
        RichYear() {}
        void use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol="", int start1=0, int end1=0, int start2=0, int end2=0, string ressource1="", string ressource2="") override; // Surcharge de la méthode use
        void use(Player& owner, std::string resource1, string ressource2); 
        std::string getType() const override { return "RichYear"; }
    };

    class Knight : public DevelopmentCard {
    public:
        Knight() {}
        void use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol="", int start1=0, int end1=0, int start2=0, int end2=0, string ressource1="", string ressource2="") override; // Surcharge de la méthode use
        void use(Player& owner); 
        std::string getType() const override { return "Knight"; } 
    };

    class VictoryPoint : public DevelopmentCard {
    public:
        VictoryPoint() {}
        void use(const std::string& type, Player& owner,  Game& game, string ressourceMonopol="", int start1=0, int end1=0, int start2=0, int end2=0, string ressource1="", string ressource2="") override; // Surcharge de la méthode use
        void use(Player& owner); 
        std::string getType() const override { return "VictoryPoint"; } 
    };
}

#endif // DEVELOPMENTCARD_HPP