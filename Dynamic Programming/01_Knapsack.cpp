# include <iostream>
using namespace std;
const int n = 5;

void knapsack(int p[], int v[], int W)
{
	int c[n][W+1];
	for(int w=0; w<W+1 ;w++)
	{
		c[0][w] = 0;
	}
	for(int i=1; i<n;i++)
	{
		c[i][0] = 0;
		for(int w =1; w<W+1 ;w++)
		{
			if(v[i] <= w)
			{
				if((p[i] + c[i-1][w-v[i]]) >= c[i-1][w])    // check for previous elements with the corresponding weight we can add
				{
					c[i][w] = (p[i] + c[i-1][w-v[i]]);
				}
				else{
					c[i][w] = c[i-1][w];
				}
			}
			else{
				c[i][w] = c[i-1][w];
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<W+1 ;j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int res[n-1] = {0};
	int i = n-1, j = W;  // the last element will have the largest value and will start from there
	while(i>0 && j>0)
	{
		if(c[i][j] == c[i-1][j])
		{
			res[i-1] = 0;
			i--;
		}else{
			res[i-1] = 1;
			j = j - v[i];
			i--;
		}
	}
	for(int i=0; i<n-1 ;i++)
	{
		cout << res[i] << " ";
	}
}
int main()
{
    int p[n] = {0,1,2,5,6};
    int w[n] = {0,2,3,4,5};
    int W = 8;
    knapsack(p,w,W);
}
