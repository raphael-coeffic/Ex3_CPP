/**
 * 337614747
 * racoeffic@gmail.com
 */
#ifndef CORNER_HPP
#define CORNER_HPP

#include <vector>

namespace ex3 {
    class Corner {
    private:
        int num;
        int owner;
        int type; //0: free, 1: village, 2: town
        std::vector<int> neighbors;
        void init_neighbors(int n); //for each Corner init wich neighbors place do he has

    public:
        Corner();
        void setNum(int n);
        void setOwner(int numPlayer);
        int getOwner() {return this->owner;};
        int getType() {return this->type;}
        void setType(int type) {this->type = type;}
        std::vector<int> getNeighbors() {return this->neighbors;}

    };
}

#endif // CORNER_HPP