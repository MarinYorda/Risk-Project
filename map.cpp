#include <iostream>
#include <vector>
#include "map.h"
#include <stack>
using namespace std;


// --------------- OVERLOADING INSERTION STREAM OPERATORS ---------------

    ostream &operator<<(ostream &output, Continent &obj){
        output << obj.getContinentName() << endl;
        return output;
    }

    ostream &operator<<(ostream &output, Territory &obj){
        output << obj.getTerritoryName() << " which belongs to" << obj.getContinent()->getContinentName() << endl;
        return output;
    }
// ostream &operator<<(ostream &output, Map &obj)
// {
//     output << "The Map has " << obj.getV().size() << " vertices and contains "
//            << obj.getListOfContinents().size() << " continents." << endl;
//     return output;
// }


    // ------------------- CONTINENT CLASS --------------------------
    // ------------------ GETTERS AND SETTERS ----------------------

    string Continent::getContinentName(){
        return *this->continentName;
    }; 
    int Continent::getBonusValue(){
        return *this->bonusValue;
    };
    void Continent::setContinentName(string continentName){
        *this->continentName = continentName;
    };
    void Continent :: setBonusValue(int bonusValue){
        *this->bonusValue = bonusValue;
    };



    // ------------------- CONSTRUCTORS ----------------------

    Continent::Continent(){};
    
    Continent::Continent(string continentName, int bonusValue) {
        continentName = continentName; 
        bonusValue = bonusValue; 
    };
    
    Continent::Continent(Continent &continent){
        continentName = continent.continentName;
    };
    
  

    // ---------------- OVERLOADING ASSIGNMENT OPERATORS -----------------

    Continent &Continent::operator=(const Continent &t)
    {
        if (this != &t)
        {
            continentName = t.continentName;
        }
        return *this;
    }

    
        
    // --------------------- TERRITORY CLASS --------------------------
    // -------------------- GETTERS AND SETTERS ----------------------
    string Territory::getTerritoryName(){
        return *this->territoryName;
    };
    Continent Territory::getContinent(){
        return *this->continent;
    };
    int Territory::getNoOfArmies(){
        return *this->noOfArmies;
    };
    void Territory::setTerritoryName(string territoryName){
        *this->territoryName = territoryName;
    };
    void Territory::setContinent(Continent &continent){
        *this->continent = continent;
    };
    void Territory::setNoOfArmies(int noOfArmies){
        *this->noOfArmies = noOfArmies;
    };



    // --------------------- CONSTRUCTORS -------------------------

    Territory::Territory(){};
    Territory::Territory(string territoryName, Continent continent){
        
    }
    Territory::Territory(string territoryName, Continent continent,int noOfArmies, vector <Territory*> adjacent){
        territoryName = territoryName;
        continent = continent;
        noOfArmies = noOfArmies;
        //create a list of adjacent countries of the territory stored in a vector of points 
    };
    Territory::Territory(Territory &territory){
        territoryName = territory.territoryName;
        noOfArmies= territory.noOfArmies;
        continent = territory.continent;
    };




    // --------------------- OVERLOADING ASSIGNMENT OPERATOR -----------------
    //Confused about pointers so if we have references instead of values i know where to look
    Territory &Territory::operator=(const Territory &t){
        if (this != &t)
        {
            territoryName = t.territoryName;
            noOfArmies = t.noOfArmies;
            continent = t.continent;
        }
        return *this;
    }

class MapLoader{
    Map* loadMap();
};


class Map{
    vector <Continent*> con;
    bool validate();
};


