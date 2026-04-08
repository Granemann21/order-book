#ifndef ORDER_HPP
#define ORDER_HPP
#include <string>


class Order {

private:
    int id;
    char type; 
    float price;
    int timestamp;

public:

    Order(int id, char type, float price, int timestamp);
    Order() : id(0), type(' '), price(0.0), timestamp(0) {}
    ~Order();

    int getId();
    char getType();
    float getPrice();
    int getTimestamp();
};

#endif