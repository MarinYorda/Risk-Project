#include "Orders.h"
#include <iostream>
#include <vector>
using namespace std;



//    ### ORDER
Order::Order() {
//    set data member orderName as blank by default
    this->setOrderName(new string(""));
//    set data member orderEffect as blank by default
    this->setOrderEffect(new string(""));
//    set data member executable as false by default
    this->setExecutable(new bool(false));
};

Order::Order(string* orderName) {
//    set data member orderName as value passed into constructor
    this->setOrderName(orderName);
//    set data member orderEffect as blank by default
    this->setOrderEffect(new string(""));
//    set data member executable as false by default
    this->setExecutable(new bool(false));
};

Order::Order(Order* order) {
//    set data member orderName as orderName of object passed into constructor
    this->setOrderName(new string(order->getOrderName()));
//    set data member orderEffect as orderEffect of object passed into constructor
    this->setOrderEffect(new string(order->getOrderEffect()));
//    set data member executable as executable of object passed into constructor
    this->setExecutable(new bool(order->getExecutable()));
};

Order::~Order() {
//    delete class data members
    delete this->orderName;
    delete this->orderEffect;
    delete this->executable;
};

void Order::setOrderName(string* orderName) {
//    set data member orderName as value passed into setter
    this->orderName = orderName;
};

string Order::getOrderName() {
//    get data member orderName
    return *this->orderName;
};

void Order::setOrderEffect(string* orderEffect) {
//    set data member orderEffect as value passed into setter
    this->orderEffect = orderEffect;
};

string Order::getOrderEffect() {
//    get data member orderEffect
    return *this->orderEffect;
};

void Order::setExecutable(bool* exec) {
//    set data member executable as value passed into setter
    this->executable = exec;
};

bool* Order::getExecutable() {
//    get data member executable
    return this->executable;
};

bool* Order::validate() {
//    TO DO
//    validation returns true in the meantime
//    return new bool(true);
};

void Order::execute() {};

Order* Order::createSubtype(string s) {
//    create string str
    string* str = new string(s);
//    compare str to each subtype name and return an object of the subtype
    if(str->compare("DEPLOY") == 0) {
        return new Deploy();
    } else if(str->compare("ADVANCE") == 0) {
        return new Advance();
    } else if(str->compare("BOMB") == 0) {
        return new Bomb();
    } else if(str->compare("BLOCKADE") == 0) {
        return new Blockade();
    } else if(str->compare("AIRLIFT") == 0) {
        return new Airlift();
    } else {
        return new Negotiate();
    }
}



//    ### DEPLOY
Deploy::Deploy() : Order(new string("DEPLOY")) {
//    call parent constructor using order type "Deploy"
};

Deploy::~Deploy() {

};

bool* Deploy::validate() {
//    validation returns true in the meantime
    return new bool(true);
};

void Deploy::execute() {
//    if statement to verify if the order was valid
    if(*this->validate()) {
//        calling setters to influence friend operator
        bool* n = this->validate();
        this->setExecutable(n);
        this->setOrderEffect(new string("A certain number of troops are deployed to some specified territory."));
    }
};



//    ### ADVANCE
Advance::Advance() : Order(new string("ADVANCE")) {
//    call parent constructor using order type "Advance"
};

Advance::~Advance() {};

bool* Advance::validate() {
//    validation returns true in the meantime
    return new bool(true);
};

void Advance::execute() {
//    if statement to verify if the order was valid
    if(*this->validate()) {
//        calling setters to influence friend operator
        bool* n = this->validate();
        this->setExecutable(n);
        this->setOrderEffect(new string("A certain number of troops advanced towards some specified territory."));
    }
};



//    ### BOMB
Bomb::Bomb() : Order(new string("BOMB")) {
//    call parent constructor using order type "bomb"
};

Bomb::~Bomb() {};

bool* Bomb::validate() {
//    validation returns true in the meantime
    return new bool(true);
};

void Bomb::execute() {
//    if statement to verify if the order was valid
    if(*this->validate()){
//        calling setters to influence friend operator
        bool* n = this->validate();
        this->setExecutable(n);
        this->setOrderEffect(new string("Some specified territory was bombed."));
    }
};



//    ### BLOCKADE
Blockade::Blockade() : Order(new string("BLOCKADE")) {
//    call parent constructor using order type "blockade"
};

Blockade::~Blockade() {};

bool* Blockade::validate() {
//    validation returns true in the meantime
    return new bool(true);
};

void Blockade::execute() {
//    if statement to verify if the order was valid
    if(*this->validate()){
//        calling setters to influence friend operator
        bool* n = this->validate();
        this->setExecutable(n);
        this->setOrderEffect(new string("A certain number of troops blockaded some specified territory."));
    }
};



//    ### AIRLIFT
Airlift::Airlift() : Order(new string("AIRLIFT")) {
//    call parent constructor using order type "airlift"
};

Airlift::~Airlift() {};

bool* Airlift::validate() {
//    validation returns true in the meantime
    return new bool(true);
};

void Airlift::execute() {
//    if statement to verify if the order was valid
    if(*this->validate()){
//        calling setters to influence friend operator
        bool* n = this->validate();
        this->setExecutable(n);
        this->setOrderEffect(new string("An airlift was sent to some specified territory."));
    }
};



//    ### NEGOTIATE
Negotiate::Negotiate() : Order(new string("NEGOTIATE")) {
//    call parent constructor using order type "negotiate
};

Negotiate::~Negotiate() {};

bool* Negotiate::validate() {
//    validation returns true in the meantime
    return new bool(true);
};

void Negotiate::execute() {
//    if statement to verify if the order was valid
    if(*this->validate()){
//        calling setters to influence friend operator
        bool* n = this->validate();
        this->setExecutable(n);
        this->setOrderEffect(new string("A negotiation was set in place with some specified territory."));
    }
};



//    ### ORDERSLISTS
OrdersLists::OrdersLists() {};

OrdersLists::~OrdersLists() {
//    delete class data members
    delete &this->orders;
};

// TO DO: figure out if this works
OrdersLists::OrdersLists(OrdersLists* list) {
//    call the OrdersLists getter and push each Order into orders by calling the copy constructor
    for(Order* o : list->getOrders()) {
        this->orders.push_back(Order::createSubtype(o->getOrderName()));
    }
};

vector<Order*> OrdersLists::getOrders()  {
//    get data member orders
    return this->orders;
};

int OrdersLists::getListSize() {
    return orders.size();
}

void OrdersLists::add(Order* order) {
//    push order to list
    this->orders.push_back(order);
};

void OrdersLists::remove(string order) {
//    counter to use in erase function
    int i = 0;
//    validate each Order of orders
    for(Order* o : this->orders) {
//        if the name of the element matches the string passed through, remove that element from the list
        if(o->getOrderName().compare(order) == 0) {
            this->orders.erase(this->orders.begin() + i);
            return;
        }
//        else, increment counter
        i++;
    }
};

void OrdersLists::move(string order, int position) {
//    create pointer to use for manipulation
    Order* orderPointer;
//    find the Order to move by comparing each orderName to order and set orderPointer if found
    for(Order* o : this->orders) {
        if(o->getOrderName().compare(order) == 0) {
            orderPointer = Order::createSubtype(o->getOrderName());
            break;
        }
    }
//    if it exists, remove the order from the list since it will have two occurrences then insert it at position (one-based index)
    if(!orderPointer->getOrderName().empty()) {
        this->remove(order);
        this->orders.insert(this->orders.begin() + position - 1, orderPointer);
    }
};

void OrdersLists::execute() {
//    print header
    cout << "======= ORDERS NOW EXECUTING =======" << endl << endl;
//    call execute on and print each Order of orders
    for(Order* o : this->orders) {
        o->execute();
        cout << *o;
    }
//    print footer
    cout << "===== ORDERS FINISHED EXECUTING =====" << endl << endl << endl << endl << endl;
}



//    ### FREE FUNCTIONS
ostream & operator << (ostream &out, Order &o) {
//    cout statement for executable orders
    if(*o.executable) {
        out << "ORDER " << o.getOrderName() << " EXECUTED SUCCESSFULLY" << endl << "Effect: " << o.getOrderEffect()
            << endl << endl;
    }
//    cout statement for non-executable orders
    else {
        out << "ORDER " << o.getOrderName() << " EXECUTED UNSUCCESSFULLY" << endl << endl;
    }
//    return statement
    return out;
};