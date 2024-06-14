/**
 * 337614747
 * racoeffic@gmail.com
 */
#ifndef PLACE_HPP
#define PLACE_HPP

#include <string>
#include <vector>
using namespace std;
namespace ex3 {
    class Place {
    private:
        string type; //0: wheat, 1: rock, 2: brick, 3: lumber, 4: sheep
        int num;
        vector<int> corners;

    public:
        Place();
        int getNum();
        void setNumber(int newNum);
        string getType();
        void setType(string& type);

    };
}

#endif // PLACE_HPP