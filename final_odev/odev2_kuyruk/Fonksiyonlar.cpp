#include <iostream>
#include "Header.hpp"
using namespace std;

typedef struct dugum
{
	int veri;
	dugum* sonraki;
};

// asagidaki dugum degiskenini global olarak tanimladim !

dugum* EnBas = NULL;

void elemanekle(int deger)   // eleman eklemek icin yazdigim fonksiyon
{
	/* degerleri bagli listede sona ekliyorum, silerken de en bastan silmeye basliyacam, bu sekilde kuyruk yapisina ilk giren ilk cikmis olacak.*/

	dugum* ilerle = (dugum*)malloc(sizeof(dugum));   // dugumlerde ilerlemek icin

	if (EnBas == NULL)   // en bastaki eleman bos ise
	{
		EnBas = (dugum*)malloc(sizeof(dugum));
		EnBas->veri = deger;
		EnBas->sonraki = NULL;
		return;
	}

	ilerle = EnBas;

	while (ilerle->sonraki != NULL)  // en son elemana kadar ilerliyorum.
	{
		ilerle = ilerle->sonraki;
	}

	dugum* eklenecek = (dugum*)malloc(sizeof(dugum));
	eklenecek->veri = deger;
	ilerle->sonraki = eklenecek;  // degeri en sona ekledim.
	eklenecek->sonraki = NULL;
}

void elemansilme()   // eleman silmek icin yazdigim fonksiyon
{
	/* simdi en bastan eleman sileceðim ve kuyruga ilk giren ilk cikmis olacak.*/

	if (EnBas == NULL)  // kuyruk bos ise uyari versin
	{
		cout << "\n Kuyruk Bos !!";
		return;
	}

	dugum* gecici = (dugum*)malloc(sizeof(dugum));
	gecici = EnBas;  // bastaki elemani gecici pointer a atadim, kuyrugun basini degistirip free yapicam.
	int a = gecici->veri;
	EnBas = EnBas->sonraki;   // kuyrugun basini bastan bir sonraki eleman yaptim.
	free(gecici);   // elemani free yaptim.

	cout << endl << "Bastaki " << a << " Elemani Silindi." << endl;
}

void elemanyazdir()    // elemanlari yazdirmak icin yazdigim fonksiyon.
{
	dugum* ilerle = (dugum*)malloc(sizeof(dugum));
	ilerle = EnBas;  // kuyrukta ilerlemek icin

	while (ilerle != NULL)
	{
		cout << " " << ilerle->veri << " - ";
		ilerle = ilerle->sonraki;
	}
}