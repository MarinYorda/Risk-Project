#include <iostream>
#include <vector>
#include "map.h"
#include <stack>
#include <fstream>
using namespace std;


// --------------- OVERLOADING INSERTION STREAM OPERATORS ---------------

ostream &operator<<(ostream &output, Continent &obj){
    output << obj.getContinentName() << endl;
    return output;
}

ostream &operator<<(ostream &output, Territory &obj){
    output << obj.getTerritoryName() << " belongs to Continent: " << obj.getContinent()->getContinentName() << endl;
    return output;
}
ostream &operator<<(ostream &output, Map &obj)
{
    output << "The Map has " << obj.getSubgraph().size() << " continents." << endl;
    return output;
}


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
//Default constructor
Continent::Continent(){};


Continent::Continent(string continentName, int bonusValue) {
    continentName = continentName;
    bonusValue = bonusValue;
};

//Copy Constructor
Continent::Continent(Continent &continent){
    this->continentName = continent.continentName;
    this->bonusValue = continent.bonusValue;
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
Continent *Territory::getContinent(){
    return this->continent;
};
int Territory::getNoOfArmies(){
    return *this->noOfArmies;
};
string Territory::getPlayerName(){
    return *this->playerName;
}
void Territory::setTerritoryName(string territoryName){
    *this->territoryName = territoryName;
};
void Territory::setContinent(Continent &continent){
    *this->continent = continent;
};
void Territory::setNoOfArmies(int noOfArmies){
    *this->noOfArmies = noOfArmies;
};
void Territory::setPlayerName(string playerName){
    *this->playerName = playerName;
}



// --------------------- CONSTRUCTORS -------------------------

// Default Constructor
Territory::Territory(){};

Territory::Territory(string territoryName, Continent *continent){
    *this->territoryName = territoryName;
    this->continent = continent;
    *this->noOfArmies = 0;
    //create a list of adjacent countries of the territory stored in a vector of points
};

// Copy Constructor
Territory::Territory(Territory &territory){
    this->territoryName = territory.territoryName;
    this->noOfArmies= territory.noOfArmies;
    this->continent = territory.continent;
    this->playerName = territory.playerName;
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

// ------------------------ MAP CLASS -------------------------
// ------------------- GETTERS AND SETTERS -------------------
vector <Continent*> Map::getSubgraph (){
    return this->subgraph;
};
vector <Territory*> Map::getAllTerritories(){
    return this->allTerritories;
}
void Map::setAllTerritories(vector<Territory *> t) {
    this->allTerritories = t;
}
void Map::setSubgraph(vector<Continent*> sub){
    this->subgraph = sub;
}

// ----------------- Constructors ----------------
Map::Map(){};
Map::Map(vector<Continent*> subgraph){
    this->subgraph = subgraph;
};



// ------------------------- MAP LOADER CLASS ------------------------



vector<string> stripLine(string line) {
    vector<string> result;
    string word = "";
    for (unsigned i = 0; i < line.length(); ++i) {
        if (i == line.length() - 1) {
            result.push_back(word);
        }
        if (line.at(i) == ',') {
            result.push_back(word);
            word = "";
        } else {
            word = word + line.at(i);
        }
    }
    return result;
}


/*I tried to change this method a bit cuz it showed a bunch of errors on Clion. I hope it works cuz i wasted a lot of time
 * This method is gonna create a territory and ad
I'm unda the wata pls help me*/


//Return a territory instead of void
//Add an if statement for when the territory found is true, to add a continent  to the territory which was already created

void MapLoader::addTerritory(string tName, string cName){
    vector<Continent*> continents = this->listOfContinents();
    vector<Territory*> f = realMap->getAllTerritories();
    bool territoryFound = false;
    for(int i = 0; i < f.size();i++){
        if(f[i]->getTerritoryName() == tName){
            territoryFound = true;
        }
    }
    if(territoryFound == false) {
        int pos = 0;
        for (int i = 0; i < continents.size(); i++) {
            if (continents[i]->getContinentName() == cName) {
                pos = i;
            }
        }
        Continent *continent = continents[pos];
        Territory *territory = new Territory(tName, continent);

        //Adding the territory to the all territories vector
        realMap->getAllTerritories().push_back(territory);
    }

}
/*This method is gonna create a map after reading the .map files provided by the user
using io streams and return a pointer to the map object*/
Map* MapLoader::loadMap(){
    cout<<"Enter the name of the .map file you would like to open: "<<endl;
    string fileName;
    cin>> fileName;
    realMap = new Map();
    string extension = fileName.substr((fileName.length())-4,fileName.length());
    if(extension!=".map"){
        cout<<"The file you entered is not of the .map format, you may try again!";
        // by returning a null map pointer, we can reject all non .map files
        return realMap;
    }
    // Open the file
    ifstream file(fileName);
    string lineText;
    bool atContinents = false;
    bool atTerritories = false;
    // loop through until we find [CONTINENTS] keyword
    while(!file.eof() && !atContinents){
        getline(file,lineText);
        if(lineText == "[CONTINENTS]"){
            atContinents = true;
        };

    };

    if(file.eof() && !atContinents){
        cout << "End of File reached. No continents found, invalid map!" <<endl;
    };

    if(atContinents){
        vector <Continent*> continents;

        while (lineText != " "){ //I dont know if this will work or no -abdur
            getline(file,lineText);
            string delimiter = "=";
            string continentName = lineText.substr(0, lineText.find(delimiter));
            string bonusValue = lineText.substr(lineText.find(delimiter), lineText.length());
            int bonusValueInt = stoi(bonusValue);
            Continent* c = new Continent(continentName,bonusValueInt);
            continents.push_back(c);
        }
        realMap->setSubgraph(continents);
    }

    // next is territories
    /*I dont know what im doing with my life but here i am trying to read the file to find
    territories keyword and if i find that i made a function called stripline which will split the string
    line into a vector of strings so that i can use it as an array and create territories and continents*/
    while(file.eof() && !atTerritories){
        getline(file,lineText);
        if(lineText == "[TERRITORIES]"){
            atTerritories = true;
        };
    };

    if(file.eof() && !atTerritories){
        cout << "End of File reached. No Territories found, invalid map!";
    };

    if(atTerritories){
        vector <Territory*> territories;
        while (lineText != " "){ // I dont know when to stop ill ask someone
            getline(file,lineText);
            vector<string> currentLine = stripLine(lineText);
            string countryName = currentLine[0];
            string continentName = currentLine[3];

            addTerritory(countryName, continentName);
            //Add a loop for the adjacent territories.
        }

    }




};

vector<Continent*> MapLoader:: listOfContinents(){

};