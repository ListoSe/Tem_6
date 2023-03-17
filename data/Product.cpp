#include "Product.h"

Product::Product()
{
    title = "No name";
    price = 0;
    date = Date();
    daysSave = 0;
}

Product::Product(string title, float price, Date date, int daysSave)
{
    this->title = title;
    this->price = price;
    this->date = date;
    this->daysSave = daysSave;
}

void Product::setTitle(string title)
{
    if (title.size() != 0)
    {
        this->title = title;
    }
}

string Product::getTitle() const
{
    return title;
}

void Product::setPrice(float price)
{
    if (price > 0)
    {
        this->price = price;
    }
}

float Product::getPrice() const
{
    return price;
}

int Product::getDaysSave() const
{
    return daysSave;
}

bool Product::isExpired() const
{
    if (date + daysSave <= Date())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& out, const Product& obj)
{
    out << "Title: " << obj.title << endl;
    out << "Price: " << obj.price << endl;
    out << "Manufacturer date: " << obj.date << endl;
    out << "Term of save: " << obj.daysSave << endl;
    out << "Finish date: " << obj.daysSave + obj.date << endl;
    if (obj.isExpired())
    {
        cout << "EXPIRED PRODUCT!!!" << endl;
    }
    return out;
}

istream& operator>>(istream& in, Product& obj)
{
    cout << "Input title: ";
    getline(in, obj.title);
    cout << "\nInput price: ";
    in >> obj.price;
    cout << "\nInput manufacturer date: ";
    in >> obj.date;
    cout << "\nInput term of save: ";
    in >> obj.daysSave;
    return in;
}
