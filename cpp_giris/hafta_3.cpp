

#include <iostream>
using namespace std;
void matris_yazdir(int[][4], int);
void matris_yazdir(char dizi[][4], int satir_sayisi);

int main()
{
	int tmatris[3][4] = { {10,15,20,25}, {30,35,40,45}, {50,55,60,65} };
	char chmatris[2][4] = { 'A','n','k','a','r','A','0','6' };
	matris_yazdir(tmatris, 3);
	matris_yazdir(chmatris, 2);
	getchar();
	return 0;
}

void matris_yazdir(int dizi[][4], int satir_sayisi)
{
	int i, j;
	for (i = 0; i < satir_sayisi; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << dizi[i][j] << " ";
		}
		cout << endl;
	}
}
void matris_yazdir(char dizi[][4], int satir_sayisi)
{
	int i, j;
	for (i = 0; i < satir_sayisi; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << dizi[i][j] << " ";
		}
		cout << endl;
	}
}


