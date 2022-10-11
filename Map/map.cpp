#include <iostream>
#include <vector>
#include "map.h"
#include <stack>
#include <fstream>
#include <string>
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
void Continent::setListofTerritories(Territory *t) {
    this->listofTerritories.push_back(t);
}
vector <Territory*> Continent::getListofTerritories(){
    return this->listofTerritories;
}



// ------------------- CONSTRUCTORS ----------------------
//Default constructor
Continent::Continent(){};


Continent::Continent(string *cName,int *bonusValue) {
    this->continentName = cName;
    this->bonusValue = bonusValue;
};

//Copy Constructor
//Continent::Continent(Continent const &continent){
//    this->continentName = continent.continentName;
//    this->bonusValue = continent.bonusValue;
//};



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
vector <Territory*> Territory:: getAdjacentTerritories(){
    return this->adjacentTerritories;
}
void Territory::setTerritoryName(string territoryName){
    *this->territoryName = territoryName;
};
//Why are we passing the reference to continent here???
void Territory::setContinent(Continent *continent){
    this->continent = continent;
};
void Territory::setNoOfArmies(int noOfArmies){
    *this->noOfArmies = noOfArmies;
};
void Territory::setPlayerName(string playerName){
    *this->playerName = playerName;
}
void Territory::setAdjacentTerritories(Territory* aT){
    this->adjacentTerritories.push_back(aT);
}



// --------------------- CONSTRUCTORS -------------------------

// Default Constructor
Territory::Territory(){};
Territory::Territory(string territoryName){
    *this->territoryName = territoryName;
}

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
void Map::setAllTerritories(Territory* t) {
    this->allTerritories.push_back(t);
}
void Map::setSubgraph(Continent *sub){
    this->subgraph.push_back(sub);
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
    for (unsigned i = 0; i < line.length(); i++) {
        if (i == line.length()-1) {
            word=word +line.at(i);
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


//Add an if statement for when the territory found is true, to add a continent to the territory which was already created

Territory* MapLoader::addTerritory(string tName, string cName){
    vector<Continent*> continents = realMap->getSubgraph();
    vector<Territory*> f = realMap->getAllTerritories();
    bool territoryFound = false;
    //Continent *continent;
    int found = 0;
    for(int i = 0; i < f.size();i++){
        if(f[i]->getTerritoryName() == tName){
            territoryFound = true;
            found = i;
        };
    }
    if(territoryFound== false && cName == "adjacent"){
        Territory* adjacent = new Territory();
        //add to list of all territories
        realMap->setAllTerritories(adjacent);
        return adjacent;
    }
    if(territoryFound == false) {
        int pos = 0;
        for (int i = 0; i < continents.size(); i++) {
            if (continents[i]->getContinentName() == cName) {
                pos = i;
            }
        }
        //continent = continents[pos];
        Territory* territory = new Territory(tName, continents[pos]);

        //Adding the territory to the all territories vector
        realMap->setAllTerritories(territory);
        continents[pos]->setListofTerritories(territory);
        return territory;
    }
    if(territoryFound == true){
        if(f[found]->getContinent() == nullptr){
            int pos = 0;
            for (int i = 0; i < continents.size(); i++) {
                if (continents[i]->getContinentName() == cName) {
                    pos = i;
                }
            }
            f[found]->setContinent(continents[pos]);
            continents[pos]->setListofTerritories(f[found]);
        }
        return f[found];
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
        //loop in driver to ensure we re-prompt user for the file name
    }
    // Open the file
    ifstream file;
    file.open("C:\\Users\\Nauar Rekmani\\Desktop\\Concordia\\Risk Project\\Risk-Project\\Map\\Asia.map");
    //ifstream file("./Risk-Project/Asia.map");
    //file.open;dd

    if(file.fail()){
        cout<<"file "<<fileName<<" is open";
    }
    string lineText;
    bool atContinents = false;
    bool atTerritories = false;
    // loop through until we find [CONTINENTS] keyword
    while(!file.eof() && !atContinents){
        getline(file,lineText);
        if(lineText == "[Continents]"){
            atContinents = true;
        };

    };
// -----------------
    if(file.eof() && !atContinents){
        cout << "End of File reached. No continents found, invalid map!" <<endl;
        return realMap;
    };

    if(atContinents){
        getline(file,lineText);
        while (!lineText.empty()){
            string delimiter = "=";
            string *continentName = new string (lineText.substr(0, lineText.find(delimiter)));
            int *bonusValue = new  int (stoi(lineText.substr(lineText.find(delimiter)+1, lineText.length())));
            Continent continent(continentName,bonusValue);
            realMap->setSubgraph(&continent);
            continentName = nullptr;
            bonusValue = nullptr;
            getline(file,lineText);
        }
    }

   // ------------------------- STARTING TO READ THE TERRITORIES ------------------------
    while(!file.eof() && !atTerritories){
        getline(file,lineText);
        if(lineText == "[Territories]"){
            atTerritories = true;
        };
    };

    if(file.eof() && !atTerritories){
        cout << "End of File reached. No Territories found, invalid map!";
        return realMap;
    };

    if(atTerritories){
        while (!file.eof()) {
            getline(file, lineText);
            if (lineText != " ") {
                vector<string> currentLine = stripLine(lineText);
                string countryName = currentLine[0];
                string continentName = currentLine[3];
                Territory *t = new Territory;
                t = (addTerritory(countryName, continentName));
                for (int i = 4; i < currentLine.size(); i++) {
                    Territory *a = addTerritory(currentLine[i], "adjacent");
                    t->setAdjacentTerritories(a);
                }
            }
        }
    }
};

bool Map::alreadyVisited(Territory* t, vector <Territory*> placesVisited) {
    for (Territory* territory: placesVisited) {
        if(territory->getTerritoryName() == t->getTerritoryName()) {
            return true;
        }
    }

    return false;
}

void Map::validateConnectedMap(Territory *current, vector <Territory*> placesVisited) {

    if (!alreadyVisited(current, placesVisited)) {
        placesVisited.push_back(current);
    }

    for (Territory *neighbor: current->getAdjacentTerritories()) {
        validateConnectedMap (neighbor, placesVisited);
    }

}
bool Map::validate(Map m) {
    bool oneToOne = false;
//    int found = -1;
//    for(int i=0; i<m.getSubgraph().size();i++) {
//        string territoryName = m.getAllTerritories()[i]->getTerritoryName();
//        string continentName = m.getAllTerritories()[i]->getContinent()->getContinentName();
//        for(int j=0; j<m.getSubgraph().size();j++) {
//            for (int k = 0; k < m.getSubgraph()[j]->getListofTerritories().size(); k++) {
//                if (m.getSubgraph()[j]->getListofTerritories()[k]->getTerritoryName() == territoryName) {
//                    found++;
//                }
//            }
//        }
//    }
//
//    if(found == 0){
//        return true;
//    }
//    return false;


    vector <Territory*> placesVisited;
    validateConnectedMap(m.getAllTerritories()[0], placesVisited);
    if (placesVisited.size() != m.getAllTerritories().size()) {
        return false;
    }
    //TODO: check territories are unique before checking they're all connected



   // Going over the list of all the territories and inside the second for lopp checking all the territories left inside the loop
    for(int i = 0; i<m.getAllTerritories().size();i++){
        string territoryName = m.getAllTerritories()[i]->getTerritoryName();
        for(int j=i+1; j<m.getAllTerritories().size();j++){
            if(territoryName == m.getAllTerritories()[j]->getTerritoryName()){
                oneToOne = false;
            }
        }
    }
    oneToOne = true;


    int connectedSubgraphs = m.getSubgraph().size();
    vector<string> continents;
    for(int i = 0; i<m.getAllTerritories().size();i++){

    }

    //start at 0, go through adj, if not same continent,
    //set this one to be the search territory, and check its adj for a continent different from first and second



    // go through each territory, holding the continent name and territory name.
    // Then go through each continent checking to see that the territory name doesn't show up unless the continent names match


    //get continent.get territtory




    //1.the map is a connected graph
    //2.continents are connected subgraphs
    //3.each country belongs to one and only one continent (compare the continent name listed on the territory with the continents, list of territories)
}

