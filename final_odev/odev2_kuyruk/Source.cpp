#include <iostream>
#include "Header.hpp"
using namespace std;

int main()
{
	int x, y;
	while (true)
	{
		cout << "\n\n Kuyruga Eleman Eklemek icin - 1 \n Kuyruktan Eleman Cikarmak icin - 2 \n Kuyrugu Yazdirmak icin - 3 \n Seciminiz: ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "\n Eklenecek Eleman: ";
			cin >> y;
			elemanekle(y);
			cout << endl;
			elemanyazdir();
			break;
		case 2:
			elemansilme();
			cout << endl;
			elemanyazdir();
			break;
		case 3:
			cout << endl << "* Kuyruk Basi *";
			elemanyazdir();
			cout << "* Kuyruk Sonu *";
			break;
		default:
			break;
		}
	}
}
