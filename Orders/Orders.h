#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Order {
private:
    string* orderName;
    string* orderEffect;
    bool* executable;

public:
    Order();
    Order(string* orderName);
    Order(Order* order);
    ~Order();
    void setOrderName(string* orderName);
    string getOrderName();
    void setOrderEffect(string* orderEffect);
    string getOrderEffect();
    void setExecutable(bool* executable);
    bool* getExecutable();
    virtual bool* validate();
    virtual void execute();
    static Order* createSubtype(string s);
    friend ostream & operator << (ostream &in, Order &o);
};



class Deploy : public Order {
public:
    Deploy();
    ~Deploy();
    bool* validate();
    void execute();
};



class Advance : public Order {
public:
    Advance();
    ~Advance();
    bool* validate();
    void execute();
};



class Bomb : public Order {
public:
    Bomb();
    ~Bomb();
    bool* validate();
    void execute();
};



class Blockade : public Order {
public:
    Blockade();
    ~Blockade();
    bool* validate();
    void execute();
};



class Airlift : public Order {
public:
    Airlift();
    ~Airlift();
    bool* validate();
    void execute();
};



class Negotiate : public Order {
public:
    Negotiate();
    ~Negotiate();
    bool* validate();
    void execute();
};



class OrdersLists {
private:
    vector<Order*> orders;

public:
    OrdersLists();
    OrdersLists(OrdersLists* list);
    ~OrdersLists();
    vector<Order*> getOrders();
    int getListSize();
    void add(Order* order);
    void remove(string order);
    void move(string order, int position);
    void execute();
};



ostream & operator << (ostream &out, Order &o);

