#include "Date.h"
#include "Product.h"
#include "Snop.h"

int main()
{
	/*Date a;
	Date b(2007, 2, 13);
	a.showDate();
	b.showDate();

	cout << "a == b " << ((a==b)? "true":"false") << endl;
	cout << "a != b " << ((a != b) ? "true" : "false") << endl;
	cout << "a > b " << ((a > b) ? "true" : "false") << endl;
	cout << "a < b " << ((a < b) ? "true" : "false") << endl;
	cout << "a >= b " << ((a >= b) ? "true" : "false") << endl;
	cout << "a <= b " << ((a <= b) ? "true" : "false") << endl;

	a.showDate();
	cout << "+12 days =";
	a += 12;
	a.showDate();

	cout << "\n +2 month =";
	a += 3.f;
	a.showDate();

	cout << "\n +7 years =";
	a += 7L;
	a.showDate();

	cout << "---------------------------------------------" << endl;
	cout << "+5 days =";
	Date a1 = a + 5;
	a.showDate();
	a1.showDate();
	cout << endl;

	cout << "-5 days =";
	Date a2 = a - 5;
	a.showDate();
	a2.showDate();
	cout << endl;

	cout << "+2 month =";
	Date a3 = a + 2.f;
	a.showDate();
	a3.showDate();
	cout << endl;

	cout << "22 month =";
	Date a4 = a - 2.f;
	a.showDate();
	a4.showDate();
	cout << endl;
	*/
	/*Date d;
	cout << "print date of birth: ";
	cin >> d;

	cout << "=======================================\n";
	cout << "your birthday: " << d << endl;
	cout << "=======================================\n";
	cout << d + 5 << " " << 5 + d << "\n";
	cout << d - 7 << " " << 7 - d << "\n";
	cout << "=======================================\n";
	cout << d << endl;
	Date d1 = d--;
	cout << d1 << " " << d << endl;
	Date d2 = --d;
	cout << d2 << " " << d << endl;
	Date d3 = d++;
	cout << d3 << " " << d << endl;
	Date d4 = ++d;
	cout << d4 << " " << d << endl;
	*/
	/*Product a;
	Product b("Milk", 27.5, Date(2022, 10, 1), 30);
	Product c("Kefir", 30.2, Date(2022, 8, 15), 10);
	cin >> a;
	cout << "---------------------------------------------------------------" << endl;
	cout << a << endl << b << endl << c << endl;
	*/
	Shop a;
	a.addProduct(Product("Milk", 27.50, Date(2022, 10, 1), 30));
	a.addProduct(Product("Kefir", 30.20, Date(2022, 8, 15), 10));
	a.addProduct(Product("Cooks", 20.20, Date(2022, 10, 1), 80));



	a.showInfo();
	cout << "---------------------------------------" << endl;
	cout << a.delProduct() << endl;
	cout << "---------------------------------------" << endl;
	a.showInfo();
}