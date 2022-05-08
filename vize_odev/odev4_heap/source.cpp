#include <iostream>
#include "Header.hpp"
using namespace std;

int main()
{
	int elemanlar[5] = { 60, 45, 30, 90, 120 };

	int baslangic = (5 / 2) - 1;  // heap yapmaya nerden baslayacagimizi belirliyoruz. belirlerken de cocugu olan en nodeu seciyoruz. 

	for (int i = baslangic; i >= 0; i--)
	{
		HeapeCevir(elemanlar, 5, i);
	}
	diziyiYazdir(elemanlar);

	int a;
	cin >> a;   // debug klasorunden acinca kapanmamasi icin.
}

