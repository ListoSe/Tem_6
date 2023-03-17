#include "Date.h"
#include <string>
using namespace std;
class Product {
    string title;
    float price;
    Date date;
    int daysSave;

public:
    Product();
    Product(string title, float price, Date date, int daysSave);

    void setTitle(string title);
    string getTitle()const;
    void setPrice(float price);
    float getPrice()const;
    int getDaysSave()const;

    bool isExpired()const;

    friend ostream& operator << (ostream& out, const Product& obj);
    friend istream& operator >> (istream& in, Product& obj);
};

