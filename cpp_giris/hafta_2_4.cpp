#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int i,j,k;
	
	char karakterB[5][5]={
				{'*','*','*','*',' '},
				{'*',' ',' ',' ','*'},
				{'*','*','*','*',' '},
				{'*',' ',' ',' ','*'},
				{'*','*','*','*',' '},
				};
	char karakterM[5][7]={
				{'*','*',' ',' ',' ','*','*'},
				{'*',' ','*','*','*',' ','*'},
				{'*',' ','*','*','*',' ','*'},
				{'*',' ',' ','*',' ',' ','*'},
				{'*',' ',' ',' ',' ',' ','*'},
				};
				
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			
				cout << karakterB[i][j];
				//printf("%c",karakterB[i][j]);
				// std::cout << ifade;
			
			cout << "\t";
			//printf("\t");
				
			for(k=0;k<7;k++)
			
				cout << karakterM[i][k];
				//printf("%c",karakterM[i][k]);

			cout << endl;
			//printf("\n");
		}
				
	return 0;
}
