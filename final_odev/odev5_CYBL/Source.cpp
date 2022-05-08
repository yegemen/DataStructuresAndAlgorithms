#include <iostream>
#include "Header.hpp"
using namespace std;

int main()
{
	int a;
	while (1)
	{
		cout << "\n Basa Eleman Eklemek icin: 1 \n Sona Eleman Eklemek icin: 2 \n Sirali Eleman Eklemek icin: 3 \n Bastan Eleman Silmek icin: 4 \n Sondan Eleman Silmek icin: 5 \n Belirli Eleman Silmek icin: 6 \n Eleman Verileri Yazdirmak icin: 7 \n\n Seciminiz: ";
		cin >> a;
		switch (a)
		{
		case 1:
			int a;
			cout << "\n Basa Eklenecek Eleman: ";
			cin >> a;
			CYBL_basaelemanekle(a);
			yazdir();
			cout << "\n Ekleme Basarili. \n";
			break;
		case 2:
			int b;
			cout << "\n Sona Eklenecek Eleman: ";
			cin >> b;
			CYBL_sonaelemanekle(b);
			yazdir();
			cout << "\n Ekleme Basarili. \n";
			break;
		case 3:
			int c;
			cout << "\n Sirali Eklenecek Eleman: ";
			cin >> c;
			CYBL_siralielemanekle(c);
			yazdir();
			cout << "\n Ekleme Basarili. \n";
			break;
		case 4:
			CYBL_bastanelemansilme();
			yazdir();
			cout << "\n Silme Basarili. \n";
			break;
		case 5:
			CYBL_sondanelemansilme();
			yazdir();
			cout << "\n Silme Basarili. \n";
			break;
		case 6:
			int d;
			cout << "\n Silinecek Eleman : ";
			cin >> d;
			CYBL_belirlielemansilme(d);
			yazdir();
			cout << "\n Silme Basarili. \n";
			break;
		case 7:
			yazdir();
			break;
		}
	}
}
