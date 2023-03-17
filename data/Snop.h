#pragma once
#include"Product.h"
using namespace std;
class Shop
{
    int prodAm;
    Product* a;
public:
    Shop();
    ~Shop();

    void addProduct(Product p);
    float delProduct();
    void showInfo();
};

