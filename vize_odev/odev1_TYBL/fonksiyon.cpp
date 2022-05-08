#include <iostream>
using namespace std;

typedef struct dugum
{
	int veri;
	dugum* sonraki;
};

//asagidaki pointer lari global olarak olusturdum !!

dugum* kok = NULL; // baslangic dugumunu olusturup null a esitledim.
dugum* gecici = NULL; // lazim olacagi zaman kullanmak icin gecici dugumu olusturup null a esitledim.
dugum* ilerle = NULL; //dugumler uzerinde ilerlemek icin olusturdum. 


void TYBL_basaelemanekle(int sayi)
{
	dugum* basaekle = (dugum*)malloc(sizeof(dugum));   // basa eklenecek veri icin yeni dugum olusturdum.
	basaekle->veri = sayi;   // basa eklenecek veriyi bu dugume atadim.

	if (kok == NULL)   // eger liste bos ise ilk elemani olustursun.
	{
		kok = basaekle;
		kok->sonraki = NULL;
		return;
	}

	basaekle->sonraki = kok;   // olusturdugum dugumun sonraki dugumunu bastaki dugume atadim
	kok = basaekle;   // kok dugumunun en bastaki dugumu gostermesi icin yeni olusturdugum dugumu atadim
}

void TYBL_sonaelemanekle(int sayi)
{
	dugum* ekle = (dugum*)malloc(sizeof(dugum)); // ayri bir dugum olusturup sayiyi orada tutuyorum ve daha sonra kok e atiyorum.
	ekle->veri = sayi;

	if (kok == NULL) // eger ilk dugum bos ise sayiyi oraya atayacak.
	{
		kok = ekle;
	}
	else
	{
		ilerle = kok;  // dugumler uzerinde dolasmak icin ilerle dugumune atadim, kok dugumunu kaybetmemek icin.
		while (ilerle->sonraki != NULL)
		{
			ilerle = ilerle->sonraki;
		}
		ilerle->sonraki = (dugum*)malloc(sizeof(dugum));
		ilerle->sonraki = ekle;   // iki satirda ekleme islemlerini tamamladim.
	}
	ekle->sonraki = NULL;
}

void TYBL_siralielemanekle(int sayi)
{
	dugum* ekle = (dugum*)malloc(sizeof(dugum)); // ayri bir dugum olusturup sayiyi orada tutuyorum.
	ekle->veri = sayi;

	if (kok == NULL)   // eger ilk dugum bos ise sayiyi oraya atayacak.
	{
		kok = ekle;
		ekle->sonraki = NULL;
		return;
	}

	if (kok->veri > sayi)   // eger eklenecek veri ilk degerden kucuk ise kok degisir. daha onceden gecici diye global dugum olusturmustum.
	{
		gecici = (dugum*)malloc(sizeof(dugum));
		gecici->veri = sayi;
		gecici->sonraki = kok; //gecici dugumu basa geldi.
		return;
	}

	ilerle = kok;  // dugumler uzerinde dolasmak icin ilerle dugumune atadim, kok dugumunu kaybetmemek icin.

	if (ilerle->sonraki != NULL && ilerle->sonraki->veri < sayi)
	{
		ilerle = ilerle->sonraki;
	}
	gecici = (dugum*)malloc(sizeof(dugum));
	gecici->sonraki = ilerle->sonraki;
	ilerle->sonraki = gecici;
	gecici->veri = sayi;

}

void TYBL_bastanelemansilme()
{
	gecici = (dugum*)malloc(sizeof(dugum));   // ikinci dugumu buraya atayacagim.
	gecici = kok->sonraki;   // ikinci dugumu yeni dugume atadim.
	free(kok);   // bastaki dugumu sildim.
	kok = gecici;   // artik ilk dugum burasi.
}

void TYBL_sondanelemansilme()
{
	if (kok != NULL)
	{
		ilerle = kok;
		while (ilerle->sonraki != NULL)
		{
			ilerle = ilerle->sonraki;
		}
		gecici = ilerle;
		ilerle = ilerle->sonraki;
		free(gecici);

	}
	else
	{
		cout << "liste bos.";
	}
}

void TYBL_belirlielemansilme(int sayi)
{
	if (kok->veri == sayi)
	{
		TYBL_bastanelemansilme();   // eger kullanici bastaki elemani girerse bastanelemansilme() fonksiyonunu cagirdim.
		return;
	}
	ilerle = kok;
	while (ilerle->sonraki != NULL && ilerle->sonraki->veri != sayi)
	{
		ilerle = ilerle->sonraki;
	}
	if (ilerle->sonraki == NULL)
	{
		cout << "\n girilen eleman bagli listede bulunmamaktadýr";
		return;
	}
	gecici = ilerle->sonraki;
	ilerle->sonraki = ilerle->sonraki->sonraki;
	free(gecici);
	return;
}

void yazdir()
{
	if (kok == NULL)
	{
		cout << "\n liste bos !! \n";
		return;
	}

	int i = 1;
	ilerle = kok;
	while (ilerle != NULL)
	{
		cout << " " << i << ". Deger= " << ilerle->veri << endl;
		ilerle = ilerle->sonraki;
		i++;
	}
}
