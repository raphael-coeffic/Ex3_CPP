/**
 * 337614747
 * racoeffic@gmail.com
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Place.hpp"
#include "Corner.hpp"
#include "Player.hpp"
using namespace std;
namespace ex3 {
    class Board {
    private:
        void createEdge(size_t a, size_t b); // create a edge with value -1 between a and b
        void initEdges(); // init the edges of the map
        void initValuesCases(std::string isRandom="not random"); // init the cases of the map with value, ressources...
        vector<vector<int>> edges;
        vector<Place> places;
        vector<Corner> corners;
        
        // Private Constructor
        Board(string isRandom="not random");

        

    public:
        // use Singleton
        static Board& getInstance(string isRandom="not random");
        void initBoard(std::string isRandom);
        std::vector<std::vector<int>>& getEdges();
        std::vector<Corner>& getCorner();
        void setEdge(int start, int end, int val);
        void setCorner(int vertice, int val); // 1: village, 2: town
        vector<Place> getPlaces() {return this->places;}

    };
}

#endif // BOARD_HPP