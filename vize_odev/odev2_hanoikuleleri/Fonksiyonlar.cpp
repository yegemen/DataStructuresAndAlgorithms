#include <iostream>
using namespace std;

void HanoiKulesi(int n, char baslangic_noktasi, char orta_nokta, char bitis_noktasi)
{
	if (n==1)
	{
		cout << "Disk 1 kaynak: " << baslangic_noktasi << " , bitis: " << bitis_noktasi << " 'ye tasindi." << endl;
		return;
	}
	HanoiKulesi(n - 1, baslangic_noktasi, bitis_noktasi, orta_nokta);
	cout << "Disk " << n << " kaynak: " << baslangic_noktasi << " , bitis: " << bitis_noktasi << " 'ye tasindi." << endl;
	HanoiKulesi(n - 1, orta_nokta, baslangic_noktasi, bitis_noktasi);
}