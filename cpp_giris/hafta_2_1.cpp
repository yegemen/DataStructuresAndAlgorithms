#include <stdio.h>

int main()
{
	int i,j;
	char yildiz[5][14]={
				{'*','*','*','*',' ',' ',' ','*','*',' ',' ',' ','*','*'},
				{'*',' ',' ',' ','*',' ',' ','*',' ','*','*','*',' ','*'},
				{'*','*','*','*',' ',' ',' ','*',' ','*','*','*',' ','*'},
				{'*',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*'},
				{'*','*','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*'},
				};
	
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<14;j++)
		{
			printf("%c ",yildiz[i][j]);
		}
		printf("\n\n");
	}
}