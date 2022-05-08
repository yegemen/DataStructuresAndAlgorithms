#include <iostream>
#include "Header.hpp"
using namespace std;

int main()
{
	int elemanlar[9] = { 7, 3, 5, 8, 2, 9, 4, 15, 6 };
	int secim;

	cout << "\n ** Siralama Algoritmalari ** \n 1- Insertion Sort (araya sokma siralamasi),\n 2- Selection Sort (secmeli siralama),\n 3- Bubble Sort (kabarcik siralama),\n 4- Merge Sort (Birlesmeli siralama),\n Seciminiz: ";
	cin >> secim;
	cout << endl;
	switch (secim)
	{
	case 1:
		insertion_sort(elemanlar, 9);
		cout << "\n insertion_sort ile siralandi ! \n";
		break;
	case 2:
		selection_sort(elemanlar, 9);
		cout << "\n selection_sort ile siralandi ! \n";
		break;
	case 3:
		bubble_sort(elemanlar, 9);
		cout << "\n bubble_sort ile siralandi ! \n";
		break;
	case 4:
		bol(0, 8, elemanlar);
		yaz(elemanlar, 9);
		cout << "\n merge_sort ile siralandi ! \n";
		break;
	default:
		cout << "\ngecerli deger girmediniz. \n";
		break;
	}

	int a;
	cin >> a;
}

