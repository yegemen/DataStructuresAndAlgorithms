#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//formül= %(bitis degeri-baslangic degeri+1)+baslangic degeri

int main()
{
	srand(time(NULL));
	int dizi[10];
	int i,toplamc=0,toplamt=0,ortcift=0,orttek=0,sayact=0,sayacc=0;
	for (i = 0; i < 10; i++)
	{
		dizi[i] = rand() % 71 + 20;
	}
	for (i = 0; i < 10; i++)
	{
		if (dizi[i] % 2 == 0)
		{
			sayacc += 1;
			toplamc += dizi[i];
		}
		if (dizi[i] % 2 == 1)
		{
			sayact += 1;
			toplamt += dizi[i];
		}
	}

	orttek = toplamt / sayact;
	ortcift = toplamc / sayacc;

	cout << "Cift sayilarin ortalamasi=" << ortcift << endl;
	cout << "Tek sayilarin ortalamasi=" << orttek;
}