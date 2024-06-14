/**
 * 337614747
 * racoeffic@gmail.com
 */
#include "Board.hpp"
#include <algorithm>
#include <ctime>
#include <stdexcept>

namespace ex3 {
    Board::Board(std::string isRandom) : edges(54, std::vector<int>(54, -10)), places(19), corners(54) {
        initBoard(isRandom);
    }

    void Board::initBoard(std::string isRandom) {
        initEdges();
        initValuesCases(isRandom);
        for (int i = 0; i < 54; i++) {
            Corner c;
            c.setNum(i);
            corners[static_cast<size_t>(i)] = c;
        }
    }

    void Board::initEdges() {
        createEdge(0, 1);
        createEdge(0, 29);
        for (size_t i = 1; i < 29; i++)
            createEdge(i, i + 1);

        createEdge(30, 31);
        createEdge(30, 47);
        for (size_t i = 31; i < 47; i++)
            createEdge(i, i + 1);

        createEdge(48, 49);
        createEdge(48, 53);
        for (size_t i = 49; i < 53; i++)
            createEdge(i, i + 1);

        int help = 0;
        for (size_t i = 0; i <= 10; i += 10) {
            if (i != 0) help += 6;
            createEdge(9 + 2 * i, 36 - help);
            createEdge(2 + i, 31 + help);
            createEdge(4 + i, 33 + help);
            createEdge(7 + i, 34 + help);
        }

        createEdge(19, 42);
        createEdge(22, 43);
        createEdge(24, 45);
        createEdge(27, 46);
        createEdge(47, 48);
        createEdge(32, 49);
        createEdge(35, 50);
        createEdge(38, 51);
        createEdge(41, 52);
        createEdge(44, 53);
    }

    Board& Board::getInstance(string isRandom) {
        static Board instance(isRandom);
        return instance;
    }

    void Board::initValuesCases(string isRandom) {
        std::vector<int> vec = {10, 2, 9, 12, 6, 4, 10, 9, 11, 3, 8, 8, 3, 4, 5, 5, 6, 11};
        if (isRandom != "not random") {
            std::srand(std::time(0));
            std::random_shuffle(vec.begin(), vec.end());
        }

        for (size_t i = 0; i < 19; i++) {
            if (i == 9) ++i;
            places[i].setNumber(vec[i]);  
        }
        // ble = wheat
        std::vector<std::string> types = {"rock", "sheep", "lumber", "wheat", "brick", "sheep", "brick", "wheat", "lumber", "desert", "lumber", "rock", "lumber", "rock", "wheat", "sheep", "brick", "wheat", "sheep"};
        if (isRandom != "not random") {
            std::srand(std::time(0));
            std::random_shuffle(types.begin(), types.end());
        }
        

        for (size_t i = 0; i < 19; i++) {
            places[i].setType(types[i]);  
        }
    }

    void Board::createEdge(size_t a, size_t b) {
        if (a > 53 || b > 53) {
            throw std::invalid_argument("Invalid index for edge");
        }
        edges[a][b] = -1;
        edges[b][a] = -1;
    }

    std::vector<std::vector<int>>& Board::getEdges() {
        return edges;
    }
    std::vector<Corner>& Board::getCorner(){
        return corners;
    }
    void Board::setEdge(int start, int end, int val) {
        if (start > 53 || end > 53) {
            throw std::invalid_argument("Invalid index for edge.");
        }
        this->edges[static_cast<size_t>(start)][static_cast<size_t>(end)] = val;
        this->edges[static_cast<size_t>(end)][static_cast<size_t>(start)] = val;
    }
    void Board::setCorner(int vertice, int val) {
        if (vertice > 54) {
            throw std::invalid_argument("Invalid index for corner");
        }
        this->corners[static_cast<size_t>(vertice)].setType(val);
    }
}