#include <iostream>
#include "Header.hpp"
using namespace std;

int main()
{
	int a;
	cout << "\n Kac Adet Rakam Gireceksiniz: ";
	cin >> a;

	int* dizi;  // diziyi pointer olarak tanimladim, dinamik olarak artirabilmek icin
	dizi = (int*)malloc(sizeof(int) * a);  // kullanicinin istedigi kadar int tipinde yer actim
	
	// malloc ile pointer da yer acinca uc uca eklendigi icin dizi gibi davranir.

	int m;
	for (m = 0; m < a; m++)  // burda diziye kullanicinin sectigi kadar deger girilecek.
	{
		cout << " " << m + 1 << ". Sayiyi girin: = ";
		cin >> dizi[m];
	}

	int secim;
	cout << "\n\n Hangi Algoritma ile Siralansin? \n Quick Sort - 1 \n Shell Sort - 2 \n Tree Sort - 3 \n Seciminiz: ";
	cin >> secim;
	switch (secim)
	{
	case 1:
		QuickSort(dizi-1, 0, a); //diziyi fonksiyona gonderiyorum, fonksiyonda siralandiktan sonra asagidaki dongude yazdiriyorum
		cout << "\n\n Quick Sort ile Siralanan Dizi: \n\n";
		for (int p = 0; p < a; p++)
		{
			cout << p + 1 << ". Deger= " << dizi[p] << endl;
		}
		break;
	case 2:
		ShellSort(dizi, a); //diziyi fonksiyona gonderiyorum, fonksiyonda siralandiktan sonra asagidaki dongude yazdiriyorum
		cout << "\n\n Shell Sort ile Siralanan Dizi: \n\n";
		for (int p = 0; p < a; p++)
		{
			cout << p + 1 << ". Deger= " << dizi[p] << endl;
		}
		break;
	case 3:
		TreeSort(dizi, a);
		cout << "\n\n Tree Sort ile Siralanan Dizi: \n\n";
		for (int p = 0; p < a; p++)
		{
			cout << p + 1 << ". Deger= " << dizi[p] << endl;
		}
		break;
	case 4:
		break;
	default: cout << "\n\n Gecersiz Secim";
		break;
	}
	cin >> a; //program kapanmamasi icin
}


