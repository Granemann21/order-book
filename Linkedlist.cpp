#include "Linkedlist.hpp"

// OrderNode
OrderNode::OrderNode(Order* order){
    this->order = order;
    this->next = nullptr;
}

OrderNode::~OrderNode(){}

OrderNode* OrderNode::getNext(){
    return this->next;
}

void OrderNode::setNext(OrderNode* next){
    this->next = next;
}

Order* OrderNode::getOrder(){
    return this->order;
}

// LinkedList
LinkedOrderList::LinkedOrderList(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

OrderNode* LinkedOrderList::getHead(){
    return this->head;
}
void LinkedOrderList::setHead(OrderNode* order_node){
    this->head = order_node;
}
OrderNode* LinkedOrderList::getTail(){
    return this->tail;
}
void LinkedOrderList::setTail(OrderNode* order_node){
    this->tail = order_node;
}



LinkedOrderList::~LinkedOrderList(){}

void LinkedOrderList::addOrder(Order* order){
    
    OrderNode* order_node = new OrderNode(order);

    // Se o tamanho for zero então o head e o tail são o mesmo e não tem nenhuma order no tail
    if (size == 0) {
        this->setHead(order_node);
        this->setTail(order_node);
        this->size+=1;
    }

    else {
        this->tail->setNext(order_node);
        this->setTail(order_node);
        this->size += 1;
    }

};

bool LinkedOrderList::removeOrder(int order_id){
    bool found = false;
    int i = 0;
    // Uma variável para guardar a ordem da iteração atual e outra pra guardar a anterior 
    OrderNode* temp = this->getHead();
    OrderNode* prev = this->getHead();
    while (found == false){
        if (temp->getOrder()->getId() == order_id){
            found = true;
            break;
        }
        prev = temp;
        temp = prev->getNext();
        i++;
        if (i == this->size){
            return false;
        }
    }
    prev->setNext(temp->getNext());
    delete temp;
    temp = nullptr;
    return true;
}