#include "OrderBook.hpp"
#include "Order.hpp"

OrderBook::OrderBook(){}

// YET TO IMPLEMENT
OrderBook::~OrderBook(){}

bool OrderBook::submit(Order* order){
    if (order == nullptr) {return false;}
    // IMPLEMENTAR A VERIFICAÇÃO SE A ORDEM PODE SER EXECUTADA OU NÃO 
    //
    //
    //
    //
    //
    //


    // Eu sei que esse if é criminoso pro SOLID mas não tem solução simples se eu quiser respeitar o tipo ser um char
    if (order->getType() == 'B') {
        this->buyOrders.addOrder(order);
    }
    if (order->getType() == 'S') {
        this->sellOrders.addOrder(order);
    }


}

Order* OrderBook::getBuyOrders(int* n) {
    
    if (n == nullptr) {return nullptr;}
    if (this->buyOrders.isEmpty()) {return nullptr;}
    int total = this->buyOrders.getSize();

    *n = total;
    
    Order* buy_orders_copy = new Order[total];
    OrderNode* current = this->buyOrders.getHead();

    for (int i = 0; i < total; i++){
        buy_orders_copy[i] = *(current->getOrder());
        current = current->getNext();
    }

    return buy_orders_copy;
}

Order* OrderBook::getSellOrders(int* n) {

    if (n == nullptr) {return nullptr;}
    if (this->sellOrders.isEmpty()) {return nullptr;}
    int total = this->sellOrders.getSize();

    *n = total;
    
    Order* sell_orders_copy = new Order[total];
    OrderNode* current = this->sellOrders.getHead();

    for (int i = 0; i < total; i++){
        sell_orders_copy[i] = *(current->getOrder());
        current = current->getNext();
    }

    return sell_orders_copy;
}

Transaction* OrderBook::getTransactions(int* n) {

    if (n == nullptr) {return nullptr;}
    if (this->transactions.isEmpty()) {return nullptr;}
    int total = this->transactions.getSize();

    *n = total;
    
    Transaction* transactions_copy = new Transaction[total];
    TransactionNode* current = this->transactions.getHead();
    for (int i = 0; i < total; i++){
        transactions_copy[i] = *(current->getTransaction());
        current = current->getNext();
    }

    return transactions_copy;
}

