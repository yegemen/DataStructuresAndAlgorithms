#include <iostream>
#include "Header.hpp"
using namespace std;

int main()
{
	int disk;
	cout << "\n ** Hanoi Kuleleri ** \n" << " Disk Sayisi Girin: ";
	cin >> disk;
	if (disk < 1)
	{
		cout << " gecerli deger girin ! \n";
	}
	else
	{
		HanoiKulesi(disk, 'A', 'B', 'C');
	}

	int a;
	cin >> a;   // debug dan calistirinca programin kapanmamasi icin.
}

