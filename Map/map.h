#pragma once
#include <iostream>
#include <vector>
using namespace std;

// // the Node class
// class Node{
//     private:
//     Territory* territory;
//     vector <string> adjacentTerritory;
// };
// the Continent class

class Territory;
class Map;
class MapLoader;
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
    // ~Continent();

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
    // this will eventually be a player object
    string* playerName;

    // getter and setter methods for Territory class.
public:
    string getTerritoryName();
    Continent *getContinent();
    int getNoOfArmies();
    string getPlayerName();
    void setTerritoryName(string territoryName);

    //Im confused to why we are passing the reference to the continent here???
    //Previously it (Continent &continent) i changed it to a pointer because in the add territory
    //we are passing a continent pointer to set the continent name when territory found is true
    void setContinent(Continent *continent);
    void setNoOfArmies(int noOfArmies);
    void setPlayerName(string playerName);

    // constructors for Territory class
    Territory();
    Territory(string territoryName, Continent *continent);
    Territory(Territory &territory);
    // ~Territory();

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
private:
    //Creation of a map in the MapLoader so that you can access the list of territories and continents from the loader itself
    Map* realMap;
public:

    Map* loadMap();
    vector<Continent*> listOfContinents();
    void addTerritory(string tName, string cName);
};


class Map{
private:
    vector <Continent*> subgraph;
    vector <Territory*> allTerritories;

public:
    Map();
    Map(vector <Continent*> subgraph);
    vector <Continent*> getSubgraph();
    vector <Territory*> getAllTerritories();
    void setAllTerritories(vector<Territory*> t);
    void setSubgraph(vector<Continent*> sub);
    bool validate();
};