#include <iostream>
using namespace std;

typedef struct dugum    // agac yapisi
{
	int deger;
	struct dugum* sag;
	struct dugum* sol;
	int yukseklik;
};

int yukseklik(dugum* dugum);
int kiyaslama(int a, int b);
dugum* yenidugum(int giris);
dugum* sagBolge(dugum* y);
dugum* solBolge(dugum* x);
int dengeKontrol(dugum* kontroldugum);
dugum* ekle(dugum* kok, int giris);
void Yazdir(dugum* kok);

int main()
{
	dugum* kok1 = NULL;

	kok1 = ekle(kok1, 60);
	kok1 = ekle(kok1, 45);
	kok1 = ekle(kok1, 30);
	kok1 = ekle(kok1, 90);
	kok1 = ekle(kok1, 120);

	Yazdir(kok1);

	cout << endl;
	cout << endl;

	int a;
	cin >> a;  // debug dosyasinda otomatik kapanmasin diye.
}


int yukseklik(dugum* dugum)   // bu fonksiyon ile dugum yuksekligini return ediyoruz.
{
	if (dugum == NULL)
	{
		return 0;
	}
	return dugum->yukseklik;
}

int kiyaslama(int a, int b)   // gonderdigimiz 2 sayidan hangisi daha buyukse onu dondurur.
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}

}

dugum* yenidugum(int giris)   // dugum olusturup donduruyorum.
{
	dugum* dugumyeni = (dugum*)malloc(sizeof(dugum));
	dugumyeni->deger = giris;
	dugumyeni->sol = NULL;
	dugumyeni->sag = NULL;

	dugumyeni->yukseklik = 1;  //  yeni dugumlerin yuksekliklerini 1 yapiyorum.

	return dugumyeni;
}

dugum* sagBolge(dugum* y)
{
	dugum* x = y->sol;
	dugum* a2 = x->sag;

	x->sag = y;
	y->sol = a2;

	y->yukseklik = kiyaslama(yukseklik(y->sol), yukseklik(y->sag)) + 1;
	x->yukseklik = kiyaslama(yukseklik(x->sol), yukseklik(x->sag)) + 1;

	return x;
}

dugum* solBolge(dugum* x)
{
	dugum* y = x->sag;
	dugum* a2 = y->sol;

	y->sol = x;
	x->sag = a2;

	y->yukseklik = kiyaslama(yukseklik(y->sol), yukseklik(y->sag)) + 1;
	x->yukseklik = kiyaslama(yukseklik(x->sol), yukseklik(x->sag)) + 1;

	return y;
}

int dengeKontrol(dugum* kontroldugum)  // denge durumunu kontrol edip döndürüyorum.
{
	if (kontroldugum == NULL)
	{
		return 0;
	}
	else
	{
		return yukseklik(kontroldugum->sol) - yukseklik(kontroldugum->sag);
	}

}

dugum* ekle(dugum* kok, int giris)   //AVL agacina dugum ekliyorum.
{
	if (kok == NULL)
	{
		return yenidugum(giris);
	}
	if (giris < kok->deger)
	{
		kok->sol = ekle(kok->sol, giris);
	}
	else if (giris > kok->deger)
	{
		kok->sag = ekle(kok->sag, giris);
	}
	else
	{
		return kok;
	}

	kok->yukseklik = kiyaslama(yukseklik(kok->sol), yukseklik(kok->sag)) + 1;

	int denge = dengeKontrol(kok);

	if (denge > 1 && giris < kok->sol->deger)
	{
		return sagBolge(kok);
	}

	if (denge < -1 && giris > kok->sag->deger)
	{
		return solBolge(kok);
	}

	if (denge > 1 && giris > kok->sol->deger)
	{
		kok->sol = solBolge(kok->sol);
		return sagBolge(kok);
	}

	if (denge < -1 && giris < kok->sag->deger)
	{
		kok->sag = sagBolge(kok->sag);
		return solBolge(kok);
	}

	return kok;
}

void Yazdir(dugum* kok)
{
	if (kok != NULL)
	{
		cout << " " << kok->deger << " ";
		Yazdir(kok->sol);
		Yazdir(kok->sag);
	}
}
