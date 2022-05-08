//pointer uyg1
#include <iostream>
using namespace std;

int main()
{
	int ilkdeger, ikincideger;
	int* po;

	po = &ilkdeger;
	*po = 10;
	cout << "ilk degerim: " << *po << endl;

	po = &ikincideger;
	*po = 20;
	cout << "ikinci degerim: " << *po << endl;
}