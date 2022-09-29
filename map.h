#include <iostream>
#include <vector>
using namespace::std;
// // the Node class
// class Node{
//     private:
//     Territory* territory;
//     vector <string> adjacentTerritory;



// };
// the Continent class
class Continent{
    private:
    string* continentName;
    int* bonusValue;


    // getter and setter methods for Continent class
    public:
    string getContinentName();
    int getBonusValue();
    void setContinentName(string continentName);
    void setBonusValue(int bonusValue);

    // constructors for Continent class
    Continent();
    Continent(string continentName, int bonusValue);
    Continent(Continent &continent);
};

//the Territory class
class Territory{
    private:
    string* territoryName;
    Continent* continent;
    int* noOfArmies;

    // getter and setter methods for Territory class
    public:
    string getTerritoryName();
    Continent getContinent();
    int getNoOfArmies();
    void setTerritoryName(string territoryName);
    void setContinent(Continent &continent);
    void setNoOfArmies(int noOfArmies);

    // constructors for Territory class
    Territory();
    Territory(string territoryName, Continent continent, int noOfArmies);
    Territory(Territory &territory);
};

class MapLoader{
    Map* loadMap();
};


class Map{
    bool validate();
};

