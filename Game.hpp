/**
 * 337614747
 * racoeffic@gmail.com
 */
#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"
#include "DevelopmentCard.hpp"
#include <vector>
#include <stack>
namespace ex3 {
    class DevelopmentCard;
}
namespace ex3 {
    class Game {
    private:
        Board& board;
        std::vector<Player> players; // all my players
        std::stack<DevelopmentCard*> cardStack; // dev cards

        void initializeDevelopmentCards(string isRandom="not random"); 

    public:
        Game(std::string isRandom="not random");
        ~Game(); 
        Player* getPlayer(int playerNum); // for get a player by index
        std::vector<Player*> getAllPlayers(); // return us tue vector of our players
        Board& getBoard() { return board; } 
        DevelopmentCard* getDevCard();
        bool haveDevCard();
    };
}

#endif // GAME_HPP