# include <iostream>
using namespace std;

const int n = 10;

void sort(int *a, int*b,int *c)
{
	int i,j,temp,temp1,check;
	for(i =0 ; i<n-1; i++)
	{
		check = 0;
		for(j=0; j<n-i-1;j++)
		{
			if(b[j] > b[j+1])
			{
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
				temp1 = a[j];
				a[j] = a[j+1];
				a[j+1] = temp1;
				check = 1;
				c[j] = c[j+1];
				c[j+1] = temp1;
				check = 1;
			}
		}
		if(check == 0)
		{
			break;
		}
	}	
}

int main()
{
	int a[n] = {1,2,3,4,5,6,7,8,9,10};
	int s[n] = {1,2,3,4,7,8,9,9,11,12};
	int f[n] = {3,5,4,7,10,9,11,13,12,14};
	sort(s,f,a);
	
	int time = 0;
	for(int i=1; i<n ;i++)
	{
		if(s[i] >= time)
		{
			cout << a[i] << " ";
			time = f[i];
		}
	}	
}
