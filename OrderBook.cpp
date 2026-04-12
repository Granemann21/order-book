#include "OrderBook.hpp"
#include "Order.hpp"
#include <iostream>

OrderBook::OrderBook(){}

// YET TO IMPLEMENT
OrderBook::~OrderBook(){}

bool OrderBook::submit(Order order) {

    if (order.getType() == 'B') {
        int n = 0;
        Order* s_orders = this->getSellOrders(&n);
        int best_id = -1;
        float best_price = 0;

        if (s_orders != nullptr) {
            for (int i = 0; i < n; i++) {
                // Se o preço da venda <= preço da compra (match possível)
                if (s_orders[i].getPrice() <= order.getPrice()) {
                    // Queremos o (menor preço)
                    if (best_id == -1 || s_orders[i].getPrice() < best_price) {
                        best_id = s_orders[i].getId();
                        best_price = s_orders[i].getPrice();
                    }
                }
            }
            delete[] s_orders;

            // Se achou alguém, executa o match com o melhor
            if (best_id != -1) {
                this->sellOrders.removeOrder(best_id);
                this->transactions.addTransaction(order.getId(), best_id, best_price);
                return true;
            }
        }
        this->buyOrders.addOrder(&order);
        return false;
    }

    if (order.getType() == 'S') {
        int n = 0;
        Order* b_orders = this->getBuyOrders(&n);
        int best_id = -1;
        float best_price = 0;

        if (b_orders != nullptr) {
            for (int i = 0; i < n; i++) {
                // Se o preço da compra >= preço da venda (match possível)
                if (b_orders[i].getPrice() >= order.getPrice()) {
                    // Queremos a mais cara (maior preço para quem vende)
                    if (best_id == -1 || b_orders[i].getPrice() > best_price) {
                        best_id = b_orders[i].getId();
                        best_price = b_orders[i].getPrice();
                    }
                }
            }
            delete[] b_orders;

            if (best_id != -1) {
                this->buyOrders.removeOrder(best_id);
                this->transactions.addTransaction(best_id, order.getId(), best_price);
                return true;
            }
        }
        this->sellOrders.addOrder(&order);
        return false;
    }
    return false;
}

Order* OrderBook::getBuyOrders(int* n) {

    int total = this->buyOrders.getSize();
    // passa o tamanho da lista pro ponteiro n
    *n = total;
    if (n == nullptr) {return nullptr;}
    if (this->buyOrders.isEmpty()) {return nullptr;}
    
    // cria a cópia da lista encadeada
    Order* buy_orders_copy = new Order[total];
    OrderNode* current = this->buyOrders.getHead();

    // preenche a lista com as orders
    for (int i = 0; i < total; i++){
        buy_orders_copy[i] = *(current->getOrder());
        current = current->getNext();
    }

    return buy_orders_copy;
}

Order* OrderBook::getSellOrders(int* n) {
    
    int total = this->sellOrders.getSize();
    // passa o tamanho da lista pro ponteiro n
    *n = total;

     // verificação 
    if (n == nullptr) {return nullptr;}
    if (this->sellOrders.isEmpty()) {return nullptr;}

    // cria a cópia da lista encadeada
    Order* sell_orders_copy = new Order[total];
    OrderNode* current = this->sellOrders.getHead();

    // preenche a lista com as orders
    for (int i = 0; i < total; i++){
        sell_orders_copy[i] = *(current->getOrder());
        current = current->getNext();
    }

    return sell_orders_copy;
}

Transaction* OrderBook::getTransactions(int* n) {
    // verificação
    if (n == nullptr) {return nullptr;}
    if (this->transactions.isEmpty()) {return nullptr;}

    int total = this->transactions.getSize();
    // passa o tamanho da lista pro ponteiro n
    *n = total;
    
    // cria a cópia da lista encadeada
    Transaction* transactions_copy = new Transaction[total];
    TransactionNode* current = this->transactions.getHead();

    // preenche a lista com as transactions
    for (int i = 0; i < total; i++){
        transactions_copy[i] = *(current->getTransaction());
        current = current->getNext();
    }

    return transactions_copy;
}


bool OrderBook::cancel(int id){

    if (this->buyOrders.removeOrder(id)) return true;
    if (this->sellOrders.removeOrder(id)) return true;

    return false;
}

void OrderBook::printBuyOrders(){
    std::cout << "Buy Orders: " << std::endl;

    // pega a lista de buy orders
    int n = 0;
    Order* b_orders = this->getBuyOrders(&n);
    // se estiver vazio printa (empty)
    if (n == 0){
        std::cout << "(empty)" << std::endl;
        return;
    }

    // faz o print de cada order (a lista já é ordenada por timestamp)
    for (int i = 0; i < n; i++){
        int id = b_orders[i].getId();
        float price = b_orders[i].getPrice();
        int timestamp = b_orders[i].getTimestamp();

        std::cout << "[ " << id << " | " << price << " | " << timestamp << "]" << std::endl;
    }
    delete[] b_orders;
}

void OrderBook::printSellOrders(){
    std::cout << "Sell Orders: " << std::endl;

    // pega a lista de orders
    int n = 0;
    Order* s_orders = this->getSellOrders(&n);
    // se estiver vazio printa (empty)
    if (n == 0){
        std::cout << "(empty)" << std::endl;
        return;
    }

    // faz o print de cada order (a lista já é ordenada por timestamp)
    for (int i = 0; i < n; i++){
        int id = s_orders[i].getId();
        float price = s_orders[i].getPrice();
        int timestamp = s_orders[i].getTimestamp();

        std::cout << "[ " << id << " | " << price << " | " << timestamp << "]" << std::endl;
    }
    delete[] s_orders;
}

void OrderBook::printTransactions(){
    std::cout << "Transactions:" << std::endl;

    // pega a lista de transactions
    int n = 0;
    Transaction* trans = this->getTransactions(&n);
    // se estiver vazio printa (empty)
    if (n == 0){
        std::cout << "(empty)" << std::endl;
        return;
    }

    // faz o print de cada transaction (a lista já é ordenada por timestamp)
    for (int i = 0; i < n; i++){
        int b_id = trans[i].getBuyOrderId();
        int s_id = trans[i].getSellOrderId();
        float price = trans[i].getExecutionPrice();

        std::cout << "[" << b_id << ", " << s_id << ", " << price << "]" << std::endl;

    }
    delete[] trans;
}
