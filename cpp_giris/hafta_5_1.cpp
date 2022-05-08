//pointer uyg2
#include <iostream>
using namespace std;

int main()
{
	int dizi[5];
	int* po;
	po = dizi;
	*po = 10;
	po++;
	*po = 20;
	po++;
	*po = 30;
	po++;
	*po = 40;
	po++;
	*po = 50;
	for (int n = 0; n < 5 ; n++)
	{
		cout << dizi[n] << ", ";
	}
}