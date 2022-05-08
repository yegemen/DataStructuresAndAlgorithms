#include <iostream>
#include "Header.hpp"
using namespace std;

typedef struct dugum
{
	int veri;
	dugum* sonraki;
};

// asagidaki pointer ý global olarak olusturdum.

dugum* EnUst = NULL;

void elemanekle(int deger)  // yigitin ustune eleman ekleme bu fonksiyonda.
{
	/* yigita eklenen yeni degerleri bagli listenin surekli en basina ekleyerek yapiyorum, silme islemini de en bastan silerek yapicam, bu yontem ile son giren eleman son cikmis olucak. */

	if (EnUst == NULL)   // ilk dugum bos ise veri buraya eklenecek
	{
		EnUst = (dugum*)malloc(sizeof(dugum));
		EnUst->veri = deger;
		EnUst->sonraki = NULL;
		return;
	}

	dugum* ekle = (dugum*)malloc(sizeof(dugum));
	ekle->veri = deger;   // veriyi atadim.
	ekle->sonraki = EnUst;   // bagli listenin basina eleman ekliyorum.
	EnUst = ekle;   // kok u degistiriyorum
	return;
}

void elemansilme()  // yigitin ustunden eleman silme bu fonksiyonda
{
	/* degerleri bagli listenin en basina eklemistim, simdi de en basindan silme islemi yapicam ve son giren son cikmis olucak. */

	if (EnUst == NULL)   // ilk dugum bos ise yigit bostur.
	{
		cout << "\n Yigit Bos !";
		return;
	}

	dugum* gecici = (dugum*)malloc(sizeof(dugum));   // en bas dugumu gecici de tutup daha sonra free yapicam.
	gecici = EnUst;
	int a = gecici->veri;
	EnUst = EnUst->sonraki;   // bastan bir sonraki dugumu kok yaptim.
	free(gecici);  // gecici ye atadigim koku free yaptim.

	cout << "Ustten "<< a << " Elemani Silindi.";
}

void elemanyazdir()    // yigiti yazdirma bu fonksiyonda
{
	dugum* ilerle = (dugum*)malloc(sizeof(dugum));
	ilerle = EnUst;  // dugumler uzerinde ilerlemek icin
	while (ilerle != NULL)
	{
		cout << "\n" << " " << ilerle->veri;
		ilerle = ilerle->sonraki;
	}
}