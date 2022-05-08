#include <iostream>
#include "Header.hpp"
using namespace std;

void QuickSort(int* a, int sol, int sag)  // quick sort (Hizli Siralama) algoritmasinin oldugu fonksiyon
{
	int x, y, z;
	if (sag > sol)
	{
		z = a[sag];
		x = sol - 1;
		y = sag;
		while (x < y)
		{
			while (a[++x] < z);
			while (a[--y] > z);
			if (x < y)
			{
				int degisim;
				degisim = a[x];
				a[x] = a[y];
				a[y] = degisim;
			}
		}
		int degisim;
		degisim = a[x];
		a[x] = a[sag];
		a[sag] = degisim;
		QuickSort(a, sol, x - 1);
		QuickSort(a, x + 1, sag);

	}
}

void ShellSort(int* a, int boyut)  // shell sort (Agac Siralama) algoritmasinin oldugu fonksiyon
{
	int ort, b, c, d;
	ort = boyut / 2;
	while (ort > 0)
	{
		for (b = ort; b < boyut; b++)
		{
			c = b - ort;
			while (c>=0)
			{
				d = c + ort;
				if (a[c] < a[d])
				{
					c = -1;
				}
				else
				{
					int degisim;
					degisim = a[c];
					a[c] = a[d];
					a[d] = degisim;
					c = c - ort;
				}
			}
		}
		if (ort == 0)
			break;
		ort = ort / 2;
	}
}

  // asagidaki struct yapisi ve 4 fonksiyon Tree Sort (Agac Siralama) algoritmasina aittir.

typedef struct dugum
{
	int veri;
	dugum* sol,* sag;
};

dugum* yeniDugum(int eleman)
{
	dugum* gecici = (dugum*)malloc(sizeof(dugum));
	gecici->veri = eleman;
	gecici->sol = gecici->sag = NULL;
	return gecici;
}

void siralama(dugum* kokd, int *a, int& i)
{
	if (kokd != NULL)
	{
		siralama(kokd->sol, a, i);
		a[i++] = kokd->veri;
		siralama(kokd->sag, a, i);
	}
}

dugum* ekle(dugum* kontrol, int deger)
{
	if (kontrol == NULL)
	{
		return yeniDugum(deger);
	}
	if (deger < kontrol->veri)
	{ 
		kontrol->sol = ekle(kontrol->sol, deger);
	}
	else if (deger > kontrol->veri)
	{
		kontrol->sag = ekle(kontrol->sag, deger);
	}
	return kontrol;
}

void TreeSort(int *a, int boyut) // tree sort (Agac Siralama) algoritmasinin oldugu fonksiyon
{
	struct dugum* kok = NULL;

	kok = ekle(kok, a[0]);

	for (int i = 1; i < boyut; i++)
	{
		kok = ekle(kok, a[i]);
	}

	int i = 0;
	siralama(kok, a, i);
}