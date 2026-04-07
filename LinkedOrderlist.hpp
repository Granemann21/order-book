#ifndef LINKED_ORDER_LIST_HPP
#define LINKED_ORDER_LIST_HPP
#include "Order.hpp"

class OrderNode{

    Order* order;
    OrderNode* next;

public:

    OrderNode(Order* order);
    ~OrderNode();

    OrderNode* getNext();
    void setNext(OrderNode* next);
    Order* getOrder();
};

class LinkedOrderList{

    OrderNode* head;
    OrderNode* tail;
    int size;

public:

    LinkedOrderList();
    ~LinkedOrderList();

    OrderNode* getHead();
    void setHead(OrderNode* order_node);
    OrderNode* getTail();
    void setTail(OrderNode* order_node);

    void addOrder(Order* order);
    bool removeOrder(int order_id);
    int getSize();
};


#endif