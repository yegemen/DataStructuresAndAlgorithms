#include <iostream>
using namespace std;

typedef struct dugum
{
	int veri;
	dugum* sonraki;
	dugum* onceki;
};

//asagidaki pointer lari global olarak olusturdum !!

dugum* kok = NULL; // baslangic dugumunu olusturup null a esitledim.
dugum* gecici = NULL; // lazim olacagi zaman kullanmak icin gecici dugumu olusturup null a esitledim.
dugum* ilerle = NULL; //dugumler uzerinde ilerlemek icin olusturdum. 


void CYDBL_basaelemanekle(int sayi)
{
	dugum* basaekle = (dugum*)malloc(sizeof(dugum));   // basa eklenecek veri icin yeni dugum olusturdum.
	basaekle->veri = sayi;   // basa eklenecek veriyi bu dugume atadim.

	if (kok == NULL)   // eger liste bos ise ilk elemani olustursun.
	{
		kok = basaekle;
		kok->sonraki = kok;
		kok->onceki = kok;   // onceki ve sonraki degerlerini kendini gosterecek sekilde ayarladim.
		return;
	}

	basaekle->sonraki = kok;   // olusturdugum dugumun sonraki dugumunu bastaki dugume atadim
	kok->onceki = basaekle;   // kok dugumunu degistirdim, basa ekledigim elemani yeni kok yaptim.
	ilerle = kok;   // while dongusu ile son elemana kadar gitmek icin.

	while (ilerle->sonraki != kok)   // son elemana kadar gittim.
	{
		ilerle = ilerle->sonraki;
	}

	ilerle->sonraki = basaekle;   //son elemana gelince sonraki adresini kok dugumunu gostermesi icin.
	basaekle->onceki = ilerle;   // kok dugumunun onceki adresi son elemani gostermesi icin.
	kok = basaekle;   // kok dugumunun en bastaki dugumu gostermesi icin yeni olusturdugum dugumu atadim
}

void CYDBL_sonaelemanekle(int sayi)
{
	dugum* ekle = (dugum*)malloc(sizeof(dugum)); // ayri bir dugum olusturup sayiyi orada tutuyorum ve daha sonra kok e atiyorum.
	ekle->veri = sayi;

	if (kok == NULL) // eger ilk dugum bos ise sayiyi oraya atayacak.
	{
		kok = ekle;
		ekle->onceki = ekle;   // eklenen baska dugum olmadigi icin onceki dugum adresi kendini gosterecek.
	}
	else
	{
		ilerle = kok;  // dugumler uzerinde dolasmak icin ilerle dugumune atadim, kok dugumunu kaybetmemek icin.
		while (ilerle->sonraki != kok)
		{
			ilerle = ilerle->sonraki;
		}
		ilerle->sonraki = NULL;   // sonraki dugum ilk dugumu gosteriyordu, null yaptim,
		ilerle->sonraki = (dugum*)malloc(sizeof(dugum));   // burda da tekrar eleman eklemek icin yer actim.
		ilerle->sonraki = ekle;   // elemani sona ekledim.
	}
	ekle->sonraki = kok;   // sonraki dugumu ilk dugumun adresine esitledim.
	ekle->onceki = ilerle;   // yeni eklenen elemanin onceki isaretcisini bir onceki dugumun adresine esitledim.
	kok->onceki = ekle;   // ilk dugumun onceki adresini son dugumun adresine esitledim.
}

void CYDBL_siralielemanekle(int sayi)
{
	dugum* ekle = (dugum*)malloc(sizeof(dugum)); // ayri bir dugum olusturup sayiyi orada tutuyorum.
	ekle->veri = sayi;

	if (kok == NULL)   // eger ilk dugum bos ise sayiyi oraya atayacak.
	{
		kok = ekle;
		ekle->sonraki = kok;   // ilk dugumun sonraki adresi kendini gosterecek.
		ekle->onceki = kok;   // ilk dugumun onceki adresi kendini gosterecek.
		return;
	}

	if (kok->veri > sayi)   // eger eklenecek veri ilk degerden kucuk ise kok degisir. daha onceden gecici diye global dugum olusturmustum.
	{
		gecici = (dugum*)malloc(sizeof(dugum));
		gecici->veri = sayi;
		gecici->sonraki = kok;   // gecici dugumu basa geldi.
		kok->onceki = gecici;   // kok un onceki adresi gecici yi gostersin.
		ilerle = gecici;
		while (ilerle->sonraki != kok)   // son dugume kadar gidiyorum.
		{
			ilerle = ilerle->sonraki;
		}
		ilerle->sonraki = gecici;   // son dugumun sonraki adresi ilk dugumun adresini gostersin.
		gecici->onceki = ilerle;   // ilk dugumun onceki adresi son dugumu gostersin.
		kok = gecici;   // gecici yi kok pointer ýna atadim.
		return;
	}

	ilerle = kok;  // dugumler uzerinde dolasmak icin ilerle dugumune atadim, kok dugumunu kaybetmemek icin.

	if (ilerle->sonraki != kok && ilerle->sonraki->veri < sayi)
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

void CYDBL_bastanelemansilme()
{
	if (kok == NULL)
	{
		cout << " \n liste bos ! \n";
		return;
	}

	gecici = (dugum*)malloc(sizeof(dugum));   // ikinci dugumu buraya atayacagim.
	gecici = kok->sonraki;   // ikinci dugumu yeni dugume atadim.
	ilerle = gecici;

	while (ilerle->sonraki != kok)   // son dugume kadar gittim.
	{
		ilerle = ilerle->sonraki;
	}

	ilerle->sonraki = gecici;   // son dugumun sonraki adresini ilk dugume attim.
	gecici->onceki = ilerle;    // ilk dugumun onceki adresini son dugume attim.
	free(kok);   // bastaki dugumu sildim.
	kok = gecici;   // artik ilk dugum burasi.

}

void CYDBL_sondanelemansilme()
{
	if (kok != NULL)
	{
		ilerle = kok;
		while (ilerle->sonraki != kok)
		{
			ilerle = ilerle->sonraki;
		}
		ilerle->onceki->sonraki = kok;   // sondan bir onceki elemanin sonraki adresini kok un adresine esitledim.
		kok->onceki = ilerle->onceki;    // kok un onceki adresini sondan bir onceki elemanin adresine esitledim.
		free(ilerle);   // son elemani sildim.
	}
	else
	{
		cout << "liste bos.";
	}
}

void CYDBL_belirlielemansilme(int sayi)
{
	if (kok->veri == sayi)
	{
		CYDBL_bastanelemansilme();   // eger kullanici bastaki elemani girerse bastanelemansilme() fonksiyonunu cagirdim.
		return;
	}
	ilerle = kok;
	while (ilerle->sonraki != kok && ilerle->sonraki->veri != sayi)
	{
		ilerle = ilerle->sonraki;
	}
	if (ilerle->sonraki == kok)
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
	cout << endl << 1 << ". Deger= " << ilerle->veri << endl;   // ilk dugumu manuel yazdim. donguye girmeyecegi icin.
	ilerle = ilerle->sonraki;   // dongude sorun olmasin diye sonraki dugume goturdum.
	while (ilerle != kok)   // eger son dugum ilk dugumu gosteriyor ise donguden cikacaktir.
	{

		cout << " " << i << ". Deger= " << ilerle->veri << endl;   // burda degerler yazdiriliyor.
		ilerle = ilerle->sonraki;
		i++;
	}
	cout << "\n Bagli listede sona gelindi! \n";
}