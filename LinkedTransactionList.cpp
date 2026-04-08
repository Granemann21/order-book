#include "LinkedTransactionList.hpp"

TransactionNode::TransactionNode(Transaction* transaction) {
    this->transaction = transaction;
    this->next = nullptr;
}

TransactionNode::~TransactionNode() {
    if (this->transaction != nullptr) {
        delete this->transaction;
    }
}

TransactionNode* TransactionNode::getNext() {
    return this->next;
}

void TransactionNode::setNext(TransactionNode* next) {
    this->next = next;
}

Transaction* TransactionNode::getTransaction() {
    return this->transaction;
}


LinkedTransactionList::LinkedTransactionList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

LinkedTransactionList::~LinkedTransactionList() {
    TransactionNode* current = this->head;
    while (current != nullptr) {
        TransactionNode* next_node = current->getNext();
        delete current; 
        current = next_node;
    }
}

bool LinkedTransactionList::isEmpty(){
    if (this->getSize() == 0) {return true;}
    else {return false;}
}

TransactionNode* LinkedTransactionList::getHead() {
    return this->head;
}

int LinkedTransactionList::getSize() {
    return this->size;
}

void LinkedTransactionList::addTransaction(int buy_id, int sell_id, float price) {
    Transaction* new_trans = new Transaction(buy_id, sell_id, price);
    TransactionNode* new_node = new TransactionNode(new_trans);

    if (this->size == 0) {
        this->head = new_node;
        this->tail = new_node;
    } else {
        this->tail->setNext(new_node);
        this->tail = new_node;
    }
    this->size++;
}