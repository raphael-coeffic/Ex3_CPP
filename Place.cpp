/**
 * 337614747
 * racoeffic@gmail.com
 */
#include "Place.hpp"
#include <climits>
using namespace std;
namespace ex3 {

    Place::Place() {
        this->type = "";
        this->num = -1;
        this->corners.resize(6, 0);
    }

    int Place::getNum() {
        return this->num;

    }

    void Place::setNumber(int newNum){
        num = newNum;
    }

    string Place::getType() {
        return this->type;
    }

    void Place::setType(string& type) {
        this->type = type;
    }

    
}