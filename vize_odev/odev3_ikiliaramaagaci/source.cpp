#include <iostream>
using namespace std;

typedef struct dugum
{
	int veri;
	dugum* sag;
	dugum* sol;
};

dugum* kok = NULL;   // dugumu global olarak olusturuyorum.

dugum* yeni(int giris);

void sira(dugum* kok);

dugum* ekle(dugum* dugum, int giris);

dugum* ara(int deger);

void enkucukdugum(dugum* enkdugum);

void enbuyukdugum(dugum* enbdugum);


int main()
{
	int sec;
	int a;

	while (1)
	{
		cout << " \n sayi eklemek icin: 1 \n";
		cout << " yazdirmak icin: 2 \n";
		cout << " sayi aramak: 3 \n";
		cout << " en kucuk eleman icin: 4 \n";
		cout << " en buyuk eleman icin: 5 \n";
		cout << " seciminiz: ";
		cin >> sec;

		switch (sec)
		{
		case 1:
			cout << "\n girmek istediginiz sayi: ";
			cin >> a;
			ekle(kok, a);
			break;
		case 2:
			sira(kok);
			break;
		case 3:
			cout << "\naranacak sayi: ";
			cin >> a;
			ara(a);
			break;
		case 4:
			enkucukdugum(kok);
			break;
		case 5:
			enbuyukdugum(kok);
			break;
		}
	}

}


dugum* yeni(int giris)
{
	dugum* gecici = (dugum*)malloc(sizeof(dugum));
	gecici->veri = giris;   // gecici olusturduguma attim giris degerini.
	gecici->sag = NULL;   // her eklenen sag ve sol agaclar bos olacagi icin.
	gecici->sol = NULL;

	if (kok == NULL)
	{
		kok = gecici;
	}
	return gecici;
}

void sira(dugum* kok)
{
	if (kok != NULL)    // kok bos ise calismasin.
	{
		sira(kok->sol);
		cout << kok->veri << " ";
		sira(kok->sag);
	}
}

dugum* ekle(dugum* dugum, int giris)
{
	if (dugum == NULL)
	{
		return yeni(giris);
	}
	if (giris < dugum->veri)
	{
		dugum->sol = ekle(dugum->sol, giris);
	}
	else if (giris > dugum->veri)
	{
		dugum->sag = ekle(dugum->sag, giris);
	}
	return dugum;
}

dugum* ara(int deger)   // arama islemlerini agac uzerinde dolasip yazdirarak yapiyorum.
{
	dugum* ilerle;
	ilerle = kok;   // kok u kaybetmemek icin farklý pointer uzerinden kok uzerinde ilerliyorum.
	while (ilerle->veri != deger)   // aranan degere esit olmadigi surece dongu devam etsin 
	{
		if (ilerle != NULL)   // bos olmamali.
		{
			cout << " " << ilerle->veri;
			if (deger < ilerle->veri)
			{
				ilerle = ilerle->sol;   // eger aranan deger kokden kucukse sol agaca gitsin.
			}
			else
			{
				ilerle = ilerle->sag;   // aranan deger kokden buyukse sag agaca gitsin.
			}

		}
		if (ilerle == NULL)   // bulunamayinca buraya
		{
			cout << "sayi agacta bulunamadi !";
			return NULL;
		}
	}
	cout << " " << ilerle->veri;
	return ilerle;
}

void enkucukdugum(dugum* enkdugum)
{
	dugum* ilerle = enkdugum;

	if (ilerle == NULL)   // veri yoksa buraya girer.
	{
		cout << "kok bos.";
		return;
	}

	while (ilerle->sol != NULL)
	{
		ilerle = ilerle->sol;   // en kucuk elemani bulmasi icin
	}

	cout << ilerle->veri;
}

void enbuyukdugum(dugum* enbdugum)
{
	dugum* ilerle = enbdugum;

	if (ilerle == NULL)
	{
		cout << "kok bos.";
		return;
	}

	while (ilerle->sag != NULL)
	{
		ilerle = ilerle->sag;   // en buyuk elemani bulmasi icin
	}

	cout << ilerle->veri;
}


