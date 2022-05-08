

#include <iostream>
using namespace std;

int us(int, int);

int main()
{
	int t, u;
	std::cout << "Taban giriniz: ";
	cin >> t;
	cout << "us giriniz: ";
	cin >> u;
	cout << "sonuc= " << us(t, u) << endl;
}

int us(int a, int b)
{
	if (a == 0)
	{
		return 0;
	}
	if (a == 1 || b == 0)
	{
		return 1;
	}
	return a * us(a,b - 1);
}



/*fonksiyonun içi

if(x==0) return(1);
if(x>0&&y==0) return(1);
if(x>0&&y==1) return(x);
if(x>0&&y>1) return(us(x,(y-1))*x),

*/

