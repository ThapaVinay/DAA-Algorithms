# include <iostream>
# include <math.h>
using namespace std;
static int count = 0;
const int n = 5;
void print(int arr[n][n])
{
	for(int i=0; i< n;i++)
    {
    	for(int j=0; j< n; j++)
    	{
    		cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check(int r , int c, int p[])
{
    for(int i=0; i<r ;i++)
    {
    	if(p[i] == c || (abs(r-i) == abs(c - p[i])))  
    	{
    		return 0;
		}
	}
	return 1;
}

void revert(int arr[n][n],int r)
{
	for(int i=0; i< n;i++)
    {
    	arr[r][i] = 0;
	}
}

void n_queen(int arr[n][n], int r, int size, int p[])
{
	if(r == size)
	{
		print(arr);
		return;
	}
	for(int i=0 ;i<size;i++)
	{
		if(check(r,i,p))
		{
			//cout << r << i << endl; 
			revert(arr, r);
			arr[r][i] = 1;
			p[r] = i;
			n_queen(arr, r+1, size, p);
		}
	}
	count ++;
}

int main()
{
    int arr[n][n] = {0};
    int arr1[n];
    n_queen(arr, 0, n,arr1); 
    cout << count;
}




//00 01 02 03 04
//10 11 12 13 14
//20 21 22 23 24
//30 31 32 33 34 
//40 41 42 43 44
