# include <iostream>
using namespace std;

const int n = 4;
void matrix_chain(int a[] ,int n)
{
	int res[n][n] = {0};
	int p[n][n] = {0};
	for(int i=0; i<n;i++)
	{
		res[i][i] = 0;
	}
	for(int l=1; l<n; l++)
	{
		for(int i=0; i<n-l; i++)
		{
			int j=l+i;
			res[i][j] = 10000;
			for(int k=i; k<j ;k++)
			{
				int temp = res[i][k] + res[k+1][j] + a[i]*a[k+1]*a[j+1];
				if(temp < res[i][j])
				{
					res[i][j] = temp;
					p[i][j] = k+1;
				}
			}
		}
	}
	for(int i=0; i< n ;i++)
	{
		for(int j=0; j< n ;j++)
		{
			cout << res[i][j] <<  " ";
		}
		cout << endl;
	}
	cout << endl;
	for(int i=0; i< n ;i++)
	{
		for(int j=0; j< n ;j++)
		{
			cout << p[i][j] <<  " ";
		}
		cout << endl;
	}
}


int main()
{
	int a[5] = {7,1,5,4,2};
	matrix_chain(a,n); 
}
