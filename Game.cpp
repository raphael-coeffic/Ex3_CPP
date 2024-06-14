/**
 * 337614747
 * racoeffic@gmail.com
 */
#include "Game.hpp"
#include <algorithm> 
#include <random> 

namespace ex3 {
    Game::Game(string isRandom) : board(Board::getInstance(isRandom)) {
        board.initBoard(isRandom);
        // init the 3 players
        players.emplace_back(0);
        players.emplace_back(1);
        players.emplace_back(2);
        for (size_t i = 0; i < 3; i++)
        {
            this->players[i].init();
        }
        

        // Init th dev cards
        initializeDevelopmentCards();
    }

    Game::~Game() {
        // free the dev cards
        while (!cardStack.empty()) {
            delete cardStack.top();
            cardStack.pop();
        }        
        
        
    }

    void Game::initializeDevelopmentCards(string isRandom) {
        std::vector<DevelopmentCard*> developmentCards;

        // 4  victory points
        for (int i = 0; i < 4; ++i) {
            developmentCards.push_back(new VictoryPoint());
        }

        // 3 Knights
        for (int i = 0; i < 3; ++i) {
            developmentCards.push_back(new Knight());
        }

        //3 Monopols
        for (int i = 0; i < 3; ++i) {
            developmentCards.push_back(new Monopol());
        }

        // 3 ConstructRoads
        for (int i = 0; i < 3; ++i) {
            developmentCards.push_back(new ConstructRoad());
        }

        //3 RichYears
        for (int i = 0; i < 3; ++i) {
            developmentCards.push_back(new RichYear());
        }

        // shuffle the cards
        if (isRandom != "not random")
        {
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(developmentCards.begin(), developmentCards.end(), g);
        }
        
        

        // to the stack
        for (auto card : developmentCards) {
            cardStack.push(card);
        }

        developmentCards.clear();
    }

    Player* Game::getPlayer(int playerNum) {
        for (auto& player : players) {
            if (player.getPlayerNum() == playerNum) {
                return &player;
            }
        }
        return nullptr; 
    }

    std::vector<Player*> Game::getAllPlayers() {
        std::vector<Player*> playerPointers;
        for (auto& player : players) {
            playerPointers.push_back(&player);
        }
        return playerPointers;
    }
    bool Game::haveDevCard() {
        return !this->cardStack.empty();
    }

    DevelopmentCard* Game::getDevCard() {
        if (haveDevCard())
        {
            DevelopmentCard* ans = cardStack.top();cardStack.pop();
            return ans;
        }
        else return NULL;
        
    }
}
