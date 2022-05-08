#include <iostream>
using namespace std;

void bubble_sort(int dizi[], int n)
{
	int a, b, gecici;
	for (a = 0; a < n; a++)   // dizi boyutu kadar icerdeki donguye girecek ve buyuk elemanlari sona tasiyacak.
	{
		for (b = 0; b < (n - 1); b++)
		{
			if (dizi[b] > dizi[b + 1])   // dizideki buyuk elemanlari sona tasiyoruz
			{
				gecici = dizi[b];
				dizi[b] = dizi[b + 1];
				dizi[b + 1] = gecici;
			}
		}
	}  // dizinin basindan sonuna kadar her eleman isleme tabi tutuldu.

	for (a = 0; a < n; a++)   // siralamadan sonra yazdirma islemini yapiyorum.
	{
		cout << (a + 1) << ". Eleman= " << dizi[a] << endl;
	}
}

void selection_sort(int dizi[], int n)
{
	int a, b, gecici;
	for (a = 0; a < (n - 1); a++)
	{
		for (b = a + 1; b < n; b++)
		{
			if (dizi[a] > dizi[b])   // karsilastirma yapip yer degisikligi yapiliyor.
			{
				gecici = dizi[a];
				dizi[a] = dizi[b];
				dizi[b] = gecici;
			}
		}
	}

	for (a = 0; a < n; a++)   // siralamadan sonra yazdirma islemini yapiyorum.
	{
		cout << (a + 1) << ". Eleman= " << dizi[a] << endl;
	}
}

void insertion_sort(int dizi[], int n)
{
	int a, b, gecici;
	for (a = 1; a < n; a++)
	{
		gecici = dizi[a];
		b = a;
		while ((gecici < dizi[b - 1]) && (b > 0))
		{
			dizi[b] = dizi[b - 1];
			b--;
		}
		dizi[b] = gecici;
	}
	for (a = 0; a < n; a++)   // siralamadan sonra yazdirma islemini yapiyorum.
	{
		cout << (a + 1) << ". Eleman= " << dizi[a] << endl;
	}
}

void birles(int alts, int ort, int usts, int dizi[])
{
	int i, ass, usb, g;
	ass = ort;
	usb = ort + 1;
	while ((alts <= ass) & (usb <= usts))
	{
		if (dizi[alts] < dizi[usb])
		{
			alts++;
		}
		else
		{
			g = dizi[usb];
			for (i = (usb - 1); i >= alts; i--)
			{
				dizi[i + 1] = dizi[i];
			}
			dizi[alts] = g;
			alts++;
			ass++;
			usb++;
		}
	}
}

void bol(int alt, int ust, int dizi[])
{
	int ort, alts, usts;
	if (alt < ust)
	{
		alts = alt;
		usts = ust;
		ort = (alts + usts) / 2;
		bol(alts, ort, dizi);
		bol(ort + 1, usts, dizi);
		birles(alts, ort, usts, dizi);
	}
}

void yaz(int dizi[],int n)
{
	int a;
	for (a = 0; a < n; a++) 
	{
		cout << (a + 1) << ". Eleman= " << dizi[a] << endl;
	}
}

