#include "OrderBook.hpp"

OrderBook::OrderBook(){}

// YET TO IMPLEMENT
OrderBook::~OrderBook(){}

bool OrderBook::submit(Order* order){

    // Eu sei que esse if é criminoso pro SOLID mas não tem solução simples se eu quiser respeitar o tipo ser um char
    if (order->getType() == 'B') {}
    if (order->getType() == 'S') {}


}

Order* OrderBook::getBuyOrders(int* n) {}
Order* OrderBook::getSellOrders(int* n) {}
Transaction* OrderBook::getTransactions(int* n) {}