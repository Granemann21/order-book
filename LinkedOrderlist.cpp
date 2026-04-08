#include "LinkedOrderlist.hpp"

// OrderNode
OrderNode::OrderNode(Order* order){
    this->order = order;
    this->next = nullptr;
}

OrderNode::~OrderNode(){
    if (this->order != nullptr) {
        delete this->order;
    }
}

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

bool LinkedOrderList::isEmpty(){
    if (this->getSize() == 0) {return true;}
    else {return false;}
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

LinkedOrderList::~LinkedOrderList(){
    OrderNode* current = this->head;
    while (current != nullptr) {
        OrderNode* next_node = current->getNext();
        
        delete current;
        
        current = next_node;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

void LinkedOrderList::addOrder(Order* order){

    // Se alguem passar um ponteiro nulo em vez de um order
    if (order == nullptr) return;

    Order* order_copy = new Order(
        order->getId(), 
        order->getType(), 
        order->getPrice(), 
        order->getTimestamp()
    );

    OrderNode* order_node = new OrderNode(order_copy);

    // Se o tamanho for zero então o head e o tail são o mesmo e não tem nenhuma order no tail
    if (size == 0) {
        this->setHead(order_node);
        this->setTail(order_node);
    }

    else {
        this->tail->setNext(order_node);
        this->setTail(order_node);
    }
    this->size++;
};


bool LinkedOrderList::removeOrder(int order_id){
    if (this->isEmpty()) {return false;} // Se a lista tiver vazia 

    // Uma variável para guardar a ordem da iteração atual e outra pra guardar a anterior 
    OrderNode* temp = this->getHead();
    OrderNode* prev = nullptr;

    while (temp != nullptr && temp->getOrder()->getId() != order_id){
        prev = temp;
        temp = temp->getNext();
    }

    // se saiu do loop e o temp é nullptr, quer dizer que passou por todos os elementos e não encontrou o resultado
    if (temp == nullptr) return false;


    if (prev == nullptr){
        // Nesse caso o elemento a ser removido é o head
        this->setHead(temp->getNext());
    }
    else {
        prev->setNext(temp->getNext());
    }

    if (temp == this->getTail()){
        this->setTail(prev);
    }

    delete temp;
    this->size--;

    return true;
}

int LinkedOrderList::getSize() {
    return this->size;
}