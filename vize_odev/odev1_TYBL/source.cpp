#include <iostream>
#include "Header.hpp"
using namespace std;

// tek yonlu bagli liste

int main()
{
	int a;
	while (1)
	{
		cout << "\n basa eleman eklemek icin: 1 \n sona eleman eklemek icin: 2 \n sirali eleman eklemek icin: 3 \n bastan eleman silmek icin: 4 \n sondan eleman silmek icin: 5 \n belirli eleman silmek icin: 6 \n eleman verileri yazdirmak icin: 7 \n\n Seciminiz: ";
		cin >> a;
		switch (a)
		{
		case 1:
			int a;
			cout << "\n Basa Eklenecek Eleman: ";
			cin >> a;
			TYBL_basaelemanekle(a);
			yazdir();
			cout << "\n Ekleme Basarili \n";
			break;
		case 2:
			int b;
			cout << "\n Sona Eklenecek Eleman: ";
			cin >> b;
			TYBL_sonaelemanekle(b);
			yazdir();
			cout << "\n Ekleme Basarili \n";
			break;
		case 3:
			int c;
			cout << "\n Sirali Eklenecek Eleman: ";
			cin >> c;
			TYBL_siralielemanekle(c);
			yazdir();
			cout << "\n Ekleme Basarili \n";
			break;
		case 4:
			TYBL_bastanelemansilme();
			yazdir();
			cout << "\n Silme basarili \n";
			break;
		case 5:
			TYBL_sondanelemansilme();
			yazdir();
			cout << "\n Silme basarili \n";
			break;
		case 6:
			int d;
			cout << "\n Silinecek Eleman \n";
			cin >> d;
			TYBL_belirlielemansilme(d);
			yazdir();
			cout << "\n Silme basarili \n";
			break;
		case 7:
			yazdir();
			break;
		}
	}
}

