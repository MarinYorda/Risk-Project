#include "Orders.h"
#include "OrdersDriver.h"
#include <iostream>
#include <vector>
using namespace std;


void testOrdersLists() {
//    create OrdersLists list
    OrdersLists* list = new OrdersLists();

//    create an Order of each subclass
    Deploy* deploy = new Deploy();
    Advance* advance = new Advance();
    Bomb* bomb = new Bomb();
    Blockade* blockade = new Blockade();
    Airlift* airlift = new Airlift();
    Order* negotiate = new Negotiate();

//    add each created Order
    list->add(deploy);
    list->add(advance);
    list->add(bomb);
    list->add(blockade);
    list->add(airlift);
    list->add(negotiate);

//    move Order negotiate to first position
    list->move("NEGOTIATE", 1);

//    remove Order deploy
    list->remove("DEPLOY");

//    create OrdersLists anotherList
    OrdersLists* anotherList = new OrdersLists(list);
    Order* anotherDeploy = new Deploy();

//    move Order advance to third position
    anotherList->move("ADVANCE", 3);

//    add anotherDeploy to anotherList
    anotherList->add(anotherDeploy);

//    execute list and anotherList
    list->execute();
    anotherList->execute();
};