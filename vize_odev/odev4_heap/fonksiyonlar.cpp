#include <iostream>
using namespace std;

void HeapeCevir(int dizi[], int diziuzunluk, int baslangic)
{
	int enBuyuk = baslangic;
	int solCocuk = baslangic * 2 + 1;
	int sagCocuk = baslangic * 2 + 2;
	int gecici = 0;

	//sol cocuk, sag cocuk ve baslangictan hangisi en buyuk onu buluyoruz. 
	if (solCocuk < diziuzunluk && dizi[enBuyuk] < dizi[solCocuk])
	{
		enBuyuk = solCocuk;
	}
	if (sagCocuk < diziuzunluk && dizi[enBuyuk] < dizi[sagCocuk])
	{
		enBuyuk = sagCocuk;
	}
	// buraya geldigimizde en büyük hangisi ise onun indeksi elimizde oluyor. 

	// en buyuk olanla baslangici degistiriyoruz 
	gecici = dizi[baslangic];
	dizi[baslangic] = dizi[enBuyuk];
	dizi[enBuyuk] = gecici;

	// eger en buyuk baslangic deðilse alttaki agac bozuldugu icin onu tekrar duzenliyoruz.
	if (enBuyuk != baslangic)
	{
		HeapeCevir(dizi, 5, enBuyuk);
	}

}

void diziyiYazdir(int dizi[])
{
	for (int i = 0; i < 5; ++i)
		cout << dizi[i] << " ";
		cout << endl;
}