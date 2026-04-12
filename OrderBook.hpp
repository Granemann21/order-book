#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP
#include "Order.hpp"
#include "Transaction.hpp"
#include "LinkedOrderlist.hpp"
#include "LinkedTransactionList.hpp"

class OrderBook {

private:
LinkedOrderList buyOrders;
LinkedOrderList sellOrders;
LinkedTransactionList transactions;

public:

    OrderBook();
    ~OrderBook();

    bool submit(Order order);
    bool cancel(int id);

    Order* getBuyOrders(int* n);
    Order* getSellOrders(int* n);
    Transaction* getTransactions(int* n);

    void printBuyOrders();
    void printSellOrders();
    void printTransactions();

};

#endif