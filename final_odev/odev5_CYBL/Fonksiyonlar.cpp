#include <iostream>
#include "Header.hpp"
using namespace std;

typedef struct dugum
{
	int veri;
	dugum* sonraki;
	dugum* onceki;
};

//asagidaki pointer lar global olarak olusturuldu.

dugum* kok = NULL; // baslangic dugumunu olusturup null a esitledim.
dugum* gecici = NULL; // lazim olacagi zaman kullanmak icin gecici dugumu olusturup null a esitledim.
dugum* ilerle = NULL; //dugumler uzerinde ilerlemek icin olusturdum. 

void CYBL_basaelemanekle(int sayi)  // basa eleman eklenilen fonksiyon
{
	dugum* basaekle = (dugum*)malloc(sizeof(dugum));   // basa eklenecek veri icin yer actim.

	if (kok == NULL)   // eger liste bos ise ilk elemani olustursun.
	{
		kok = basaekle;
		kok->sonraki = NULL;
		kok->onceki = NULL; // onceki ve sonraki degerleri null u gostersin.
		basaekle->veri = sayi;   // basa eklenecek veriyi bu dugume atadim.
		return;
	}

	basaekle->veri = sayi;   // basa eklenecek veriyi bu dugume atadim.
	basaekle->sonraki = kok;   // olusturdugum dugumun sonraki dugumunu bastaki dugume atadim
	kok->onceki = basaekle;   // basa ekledigim elemani yeni kok yaptim.

	kok = basaekle;   // kok dugumunun en bastaki dugumu gostermesi icin yeni olusturdugum dugumu atadim
}

void CYBL_sonaelemanekle(int sayi)  // sona eleman eklenilen fonksiyon
{
	dugum* ekle = (dugum*)malloc(sizeof(dugum)); // ayri bir dugum olusturup sayiyi orada tutuyorum ve daha sonra kok e atiyorum.
	ekle->veri = sayi;

	if (kok == NULL) // eger ilk dugum bos ise sayiyi oraya atayacak.
	{
		kok = ekle;
		kok->sonraki = NULL;
		kok->onceki = NULL;   // onceki ve sonraki degerler null olsun.
	}
	else
	{
		ilerle = kok;  // dugumler uzerinde dolasmak icin ilerle dugumune atadim, kok dugumunu kaybetmemek icin.
		while (ilerle->sonraki != NULL)
		{
			ilerle = ilerle->sonraki;
		}
		ilerle->sonraki = (dugum*)malloc(sizeof(dugum));   // burda da tekrar eleman eklemek icin yer actim.
		ilerle->sonraki = ekle;   // elemani sona ekledim.
	}
	ekle->sonraki = NULL;   // sonraki dugumu null a esitledim.
	ekle->onceki = ilerle;   // yeni eklenen elemanin onceki isaretcisini bir onceki dugumun adresine esitledim.
}

void CYBL_siralielemanekle(int sayi)   // sirali eleman eklenilen fonksiyon
{
	dugum* ekle = (dugum*)malloc(sizeof(dugum)); // ayri bir dugum olusturup sayiyi orada tutuyorum.
	ekle->veri = sayi;

	if (kok == NULL)   // eger ilk dugum bos ise sayiyi oraya atayacak.
	{
		kok = ekle;
		ekle->sonraki = NULL;
		ekle->onceki = NULL;   // onceki ve sonraki degerleri null u gostersin.
		return;
	}

	if (kok->veri > sayi)   // eger eklenecek veri ilk degerden kucuk ise kok degisir. daha onceden gecici diye global dugum olusturmustum.
	{
		gecici = (dugum*)malloc(sizeof(dugum));
		gecici->veri = sayi;
		gecici->sonraki = kok;   // gecici dugumu basa geldi.
		kok->onceki = gecici;   // kok un onceki adresi gecici yi gostersin.
		gecici->onceki = NULL;   // ilk dugumun onceki adresi null u gostersin.
		kok = gecici;   // gecici yi kok pointer ýna atadim.
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
	gecici->onceki = ilerle;
	gecici->sonraki->onceki = gecici;  // buralarda araya eleman ekleme islemlerini yaptim.
	gecici->veri = sayi;

}

void CYBL_bastanelemansilme()   // bastan eleman silinen fonksiyon
{
	if (kok == NULL)
	{
		cout << " \n liste bos ! \n";
		return;
	}

	gecici = (dugum*)malloc(sizeof(dugum));   // ikinci dugumu buraya atayacagim.
	gecici = kok->sonraki;   // ikinci dugumu yeni dugume atadim.
	gecici->onceki = NULL;   // onceki degeri null u gostersin
	free(kok);   // bastaki dugumu sildim.
	kok = gecici;   // artik ilk dugum burasi.

}

void CYBL_sondanelemansilme()   // sondan eleman silinen fonksiyon
{
	if (kok != NULL)
	{
		ilerle = kok;
		while (ilerle->sonraki != NULL)
		{
			ilerle = ilerle->sonraki;
		}
		ilerle->onceki->sonraki = NULL;   // sondan bir onceki elemanin sonraki adresini null a esitledim.
		free(ilerle);   // son elemani sildim.
	}
	else
	{
		cout << "liste bos.";
	}
}

void CYBL_belirlielemansilme(int sayi)   // belirli eleman silinen fonksiyon
{
	if (kok->veri == sayi)
	{
		CYBL_bastanelemansilme();   // eger kullanici bastaki elemani girerse bastanelemansilme() fonksiyonunu cagirdim.
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
	ilerle->sonraki->sonraki->onceki = ilerle;
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
	int i = 2;
	ilerle = kok;
	cout << endl << " " << 1 << ". Deger= " << ilerle->veri << endl;   // donguye girmeyecegi icin ilk dugumu manuel yazdim.
	ilerle = ilerle->sonraki;   // dongude sorun olmasin diye sonraki dugume goturdum.
	while (ilerle != NULL)   // eger son dugum null u gosteriyor ise donguden cikacaktir.
	{

		cout << " " << i << ". Deger= " << ilerle->veri << endl;   // burda degerler yazdiriliyor.
		ilerle = ilerle->sonraki;
		i++;
	}
}
