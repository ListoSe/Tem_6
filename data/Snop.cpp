#include "Snop.h"

Shop::Shop()
{
    prodAm = 0;
    a = NULL;
}

Shop::~Shop()
{
    if (a != NULL) delete[]a;
}

void Shop::addProduct(Product p)
{
    prodAm++;
    Product* tmp = new Product[prodAm];
    for (int i = 0; i < prodAm - 1; i++)
    {
        tmp[i] = a[i];
    }
    if (a != NULL) delete[]a;
    tmp[prodAm - 1] = p;
    a = tmp;
}

float Shop::delProduct()
{
    int exp = 0;
    float sum = 0;
    for (int i = 0; i < prodAm; i++)
    {
        if (a[i].isExpired())
        {
            exp++;
            sum += a[i].getPrice();
        }
    }
    if (exp == 0)
    {
        return 0;
    }
    else
    {
        Product* tmp = new Product[prodAm - exp];
        for (int i = 0, j = 0; i < prodAm; i++)
        {
            if (!a[i].isExpired())
            {
                tmp[j++] = a[i];
            }
        }
        if (a != NULL) delete[]a;
        a = tmp;
        prodAm -= exp;
        return sum;
    }
}

void Shop::showInfo()
{
    cout << "\t SHOP INFO\n";
    cout << "Totla products: " << prodAm << endl;
    cout << "=====================================\n";
    for (int i = 0; i < prodAm; i++)
    {
        cout << i + 1 << ") " << a[i];
    }
    cout << "==========================================\n";
}
