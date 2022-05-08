#include <iostream>
#include "Header.hpp"
using namespace std;

int main()
{
	int x, y;
	while (true) {
		cout << "\n\n Yigita Eleman Eklemek icin - 1 \n Yigittan Eleman Silmek icin - 2 \n Yigiti Yazdirmak icin - 3 \n Secim Yapin: ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "\n Eklenecek Eleman: ";
			cin >> y;
			elemanekle(y);
			elemanyazdir();
			break;
		case 2:
			cout << endl;
			elemansilme();
			cout << endl;
			elemanyazdir();
			break;
		case 3:
			cout << endl << "* En Ust *";
			elemanyazdir();
			cout << endl << "* En Alt *";
			break;
		default:
			cout << "\n Gecersiz Secim !";
			break;
		}
	}
}


