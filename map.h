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
    vector <Territory*> listofTerritories; 


    // getter and setter methods for Continent class
    public:
    string getContinentName();
    int getBonusValue();
    void setContinentName(string continentName);
    void setBonusValue(int bonusValue);

    // constructors for Continent class
    Continent();
    Continent(string continentName, int bonusValue);
    Continent(string continentName, int bonusValue, vector<Territory*> t);
    Continent(Continent &continent);
    ~Continent();

    //Overloads
    Continent& operator=(const Continent& t); //Overload assignment operator
    friend ostream& operator<<(ostream& output, Continent& object); //Overload stream insertion

};

//the Territory class
class Territory{
    private:
    vector <Territory*> adjacentTerritories;
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
    Territory(string territoryName, Continent continent, vector <Territory*> adjacent);
    Territory(Territory &territory);
    ~Territory();

    //Overloads
    Territory& operator=(const Territory& t); //Overload assignment operator
    friend ostream& operator<<(ostream& output, Territory& object); //Overload stream insertion

};


// class Node{
//     private:
//     Territory *data;
//     vector <string*> edges;

//     //constructors and destructors
//     Node();
//     Node(Territory t);
//     Node(Territory t, )
// }

class MapLoader{
    Map* loadMap();
};


class Map{
    vector <Continent*> con;
    bool validate();
};

