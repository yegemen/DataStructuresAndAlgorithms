#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//formül= %(bitis degeri-baslangic degeri+1)+baslangic degeri

int main()
{
	srand(time(NULL)); //srand(time(0));
	int dizi[10];
	int i, toplamc = 0, toplamt = 0, ortcift = 0, orttek = 0, sayact = 0, sayacc = 0;
	for (i = 0; i < 10; i++)
	{
		dizi[i] = rand() % 71 + 20; // 20 + rand() %71; 20 ile 90 arasý

		if (dizi[i] % 2 == 0)
		{
			sayacc += 1;
			toplamc += dizi[i];
		}
		else
		{
			sayact += 1;
			toplamt += dizi[i];
		}
	}
	cout << "sayilar= " << endl << endl;
	for (i = 0; i < 10; i++)
	{
		cout << dizi[i] << endl;
	}

	orttek = toplamt / sayact;
	ortcift = toplamc / sayacc;

	cout << endl << "Cift sayilarin ortalamasi=" << ortcift << endl;
	cout << "Tek sayilarin ortalamasi=" << orttek << endl << endl;
}