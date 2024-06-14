/**
 * 337614747
 * racoeffic@gmail.com
 */
#include "Corner.hpp"
#include <set>
using namespace std;

namespace ex3 { 
    Corner::Corner() {
        this->owner = -1;
        this->num = 0;
        this->type = 0;
    }

    void Corner::setNum(int n) {
        this->num = n;
        init_neighbors(n);
    }
    void Corner::setOwner(int numPlayer) {
        this->owner = numPlayer;
    }

    void Corner::init_neighbors(int n) {
        if (n >=2 && n <= 29) {
            if (n % 2 == 0) this->neighbors.resize(2);
            else this->neighbors.resize(1);
        }
        if (n >=30 && n <= 53)
            this->neighbors.resize(3);
        
        if (n == 0 || n ==1 ) {this->neighbors.resize(1); this->neighbors = {0};}
        else if (n==2) {this->neighbors.resize(2); this->neighbors = {0,1};}
        else if (n==3) {this->neighbors.resize(1);this->neighbors = {1};}
        else if (n==4) {this->neighbors.resize(2);this->neighbors = {1,2};}
        else if (n==6) {this->neighbors.resize(1);this->neighbors = {2};}
        else if (n==7) {this->neighbors.resize(2);this->neighbors = {2,6};}
        else if (n==8) {this->neighbors.resize(1);this->neighbors = {6};}
        else if (n==9) {this->neighbors.resize(2);this->neighbors = {6,11};}
        else if (n==10) {this->neighbors.resize(1);this->neighbors = {11};}
        else if (n==11) {this->neighbors.resize(1);this->neighbors = {11};}
        else if (n==12) {this->neighbors.resize(2);this->neighbors = {11,15};}
        else if (n==13) {this->neighbors.resize(1);this->neighbors = {15};}
        else if (n==14) {this->neighbors.resize(2);this->neighbors = {15,18};}
        else if (n==15) {this->neighbors.resize(1);this->neighbors = {18};}
        else if (n==16) {this->neighbors.resize(1);this->neighbors = {18};}
        else if (n==17) {this->neighbors.resize(2);this->neighbors = {18,17};}
        else if (n==18) {this->neighbors.resize(1);this->neighbors = {17};}
        else if (n==19) {this->neighbors.resize(2);this->neighbors = {17,16};}
        else if (n==20) {this->neighbors.resize(1);this->neighbors = {16};}
        else if (n==21) {this->neighbors.resize(1);this->neighbors = {16};}
        else if (n==22) {this->neighbors.resize(2);this->neighbors = {12,16};}
        else if (n==23) {this->neighbors.resize(1);this->neighbors = {12};}
        else if (n==24) {this->neighbors.resize(2);this->neighbors = {12,7};}
        else if (n==25) {this->neighbors.resize(1);this->neighbors = {7};}
        else if (n==26) {this->neighbors.resize(1);this->neighbors = {7};}
        else if (n==27) {this->neighbors.resize(2);this->neighbors = {7,3};}
        else if (n==28) {this->neighbors.resize(1);this->neighbors = {3};}
        else if (n==29) {this->neighbors.resize(2);this->neighbors = {3,0};}
        else if (n==30) {this->neighbors.resize(3);this->neighbors = {0,3,4};}
        else if (n==31) {this->neighbors.resize(3);this->neighbors = {0,1,4};}
        else if (n==32) {this->neighbors.resize(3);this->neighbors = {1,4,5};}
        else if (n==33) {this->neighbors.resize(3);this->neighbors = {1,2,5};}
        else if (n==34) {this->neighbors.resize(3);this->neighbors = {2,5,6};}
        else if (n==35) {this->neighbors.resize(3);this->neighbors = {5,6,10};}
        else if (n==36) {this->neighbors.resize(3);this->neighbors = {6,10,11};}
        else if (n==37) {this->neighbors.resize(3);this->neighbors = {10,11,15};}
        else if (n==38) {this->neighbors.resize(3);this->neighbors = {10,14,15};}
        else if (n==39) {this->neighbors.resize(3);this->neighbors = {14,15,18};}
        else if (n==40) {this->neighbors.resize(3);this->neighbors = {14,17,18};}
        else if (n==41) {this->neighbors.resize(3);this->neighbors = {13,14,17};}
        else if (n==42) {this->neighbors.resize(3);this->neighbors = {13,16,17};}
        else if (n==43) {this->neighbors.resize(3);this->neighbors = {12,13,16};}
        else if (n==44) {this->neighbors.resize(3);this->neighbors = {8,12,13};}
        else if (n==45) {this->neighbors.resize(3);this->neighbors = {7,8,12};}
        else if (n==46) {this->neighbors.resize(3);this->neighbors = {3,7,8};}
        else if (n==47) {this->neighbors.resize(3);this->neighbors = {3,4,8};}
        else if (n==48) {this->neighbors.resize(3);this->neighbors = {4,8,9};}
        else if (n==49) {this->neighbors.resize(3);this->neighbors = {4,5,9};}
        else if (n==50) {this->neighbors.resize(3);this->neighbors = {5,9,10};}
        else if (n==51) {this->neighbors.resize(3);this->neighbors = {9,10,14};}
        else if (n==52) {this->neighbors.resize(3);this->neighbors = {9,13,14};}
        else if (n==53) {this->neighbors.resize(3);this->neighbors = {8,9,13};}
    }
}