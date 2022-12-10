//in this code 100 is taken as the infinity value...

# include <iostream>
# include <algorithm>
using namespace std;
void print(int a[5][5])
{
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5 ;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int * floyd_warshall(int a[5][5] , int n)
{
	int *b[5][5];
	int p[5][5];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j< n ; j++)
		{
			b[i][j] = &a[i][j];
			if(*b[i][j] != 100 && *b[i][j] != 0)
			{
				p[i][j] = i+1;
			}else{
				p[i][j] = 0;
			}
		}
	}
	
	for(int k=0; k<n ;k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n ;j++)
			{
				if(i == j || i == k || j == k)
				{
					continue;
				}
				a[i][j] = min(*b[i][j], (*b[i][k] + *b[k][j]));
				if(a[i][j] == (*b[i][k] + *b[k][j]))
				{
					p[i][j] = k+1;
				}
			}
		}
	}
	print(a);
	print(p);
}
int main()
{
	int a[5][5] = {{0,3,8,100,-4}, {100,0, 100, 1,7}, {100, 4, 0, -5, 100}, {2, 100, 100, 0, 100}, {100, 100, 100, 6,0}};
	floyd_warshall(a,5);
}
