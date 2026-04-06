#ifndef LINKED_TRANSACTION_LIST_HPP
#define LINKED_TRANSACTION_LIST_HPP

#include "Transaction.hpp"

class TransactionNode {
private:
    Transaction* transaction;
    TransactionNode* next;

public:
    TransactionNode(Transaction* transaction);
    ~TransactionNode();

    TransactionNode* getNext();
    void setNext(TransactionNode* next);
    Transaction* getTransaction();
};

class LinkedTransactionList {
private:
    TransactionNode* head;
    TransactionNode* tail;
    int size;

public:
    LinkedTransactionList();
    ~LinkedTransactionList();

    TransactionNode* getHead();
    int getSize();

    void addTransaction(int buy_id, int sell_id, float price);
};

#endif