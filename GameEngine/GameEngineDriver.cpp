#include "GameEngineDriver.h"
#include "GameEngine.h"
#include <iostream>
using namespace std;

void testGameStates() {
    cout << "Start of game" << endl << endl;
    GameEngine* g = new GameEngine();
    cout << *g << endl;


    while (*(g->getState()) < 8) {
        cout << "Enter command: " << endl;
        string input;
        cin >> input;
        g->gameFlow(input);
        cout << *g << endl;
    }

    cout << "End of game" << endl;

}

void testMainGameLoop() {
    GameEngine *game = new GameEngine();
    //create players
    Player* ali = new Player(new std::string("Ali"));
    Player* adriana = new Player(new std::string("Adriana"));
    Player* diego = new Player(new std::string("Diego"));
    //create a map?
    Map* map = new Map();
    Continent* continent1 = new Continent(new string ("North America"),new int (12));
    Continent* continent2 = new Continent(new string ("Greenland"),new int (8));
    map->setSubgraph(continent1);
    map->setSubgraph(continent2);
    //Creating vector of all the territories
    Territory *t1 = new Territory(new string("USA"),continent1);
    Territory *t2 = new Territory(new string("Greenland"),continent2);
    Territory *t3 = new Territory(new string("Mexico"),continent1);
    Territory *t4 = new Territory(new string("Canada"),continent1);
    vector<Territory*> territories = {t1,t2,t3,t4};
    for(int i =0; i<territories.size(); i++){
        map->setAllTerritories(territories[i]);
    }
    //give them a certain number of territories
    ali->setTerritories({t1,t2});
    adriana->setTerritories({t3});
    diego->setTerritories({t4});
    //calculate their number of reinforcements
    cout << "We have three players:" << *ali->getName() << ", " << *adriana->getName() << ", and " << *diego->getName() << endl;
    cout << *ali->getName() << " has: " << ali->getTerritories().size() << " territories" << endl;
    cout << *adriana->getName() << " has: " << adriana->getTerritories().size() << " territories" << endl;
    cout << *diego->getName() << " has: " << diego->getTerritories().size() << " territories" << endl;

    cout<< "We will now calculate their number of reinforcements that they get:" << endl;
    game->reinforcementPhase({ali, adriana, diego}, map);
    cout << *ali->getName() << " has: " << *ali->getReinforcements() << " reinforcements" << endl;
    cout << *adriana->getName() << " has: " << *adriana->getReinforcements()<< " reinforcements" << endl;
    cout << *diego->getName() << " has: " << *diego->getReinforcements() << " reinforcements" << endl;
    //display them
    //display that you can't call anything other than deploy while there are reinforcements still
    //display that the advance orders can be issued to either attack or defend, based on the toAttack() and toDefend() lists
    //display that a player can play cards to issue orders
    //display that a player with no territories is to be removed from the game
    //display that the game ends when someone controls all territories
}
