#include <iostream>
#include "map.h"
using namespace std;

//mapDriver
//testLoadMaps which returns a map object

Map* testLoadMaps(){
    MapLoader* loader = new MapLoader;
    Map* m = loader->loadMap();
    while(m->getSubgraph().empty()) {
        cout << "The Map File provided was Invalid. Please try again!" << endl;
        m = loader->loadMap();
    }
    for(int i=0; i<m->getSubgraph().size();i++){
        cout<< m->getSubgraph()[i]->getContinentName()<<" "<<m->getSubgraph()[i]->getBonusValue()<<endl;
    }
    return m;
}


int main(){
    testLoadMaps();
}



//validate that specific map object