

#include <iostream>
using namespace std;

int faktoriyel(int);

int main()
{
	int x;
	cout << "sayi girin: ";
	cin >> x;
	cout << "\ngirilen sayinin faktoriyeli= " << faktoriyel(x) << endl;
}

int faktoriyel(int a)
{
	if (a == 0 || a == 1 || a<=0)
	{
		return 1;
	}
	else
	{
		return a * faktoriyel(a - 1);
	}
}
