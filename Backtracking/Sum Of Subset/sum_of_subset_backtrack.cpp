# include <iostream>
using namespace std;

static int count = 0;
void sosp(int * arr, int m, int size, int weight, int total,int k, int *arr1)
{
	count++;
    if(weight == m)
    {
        cout << endl;
        for(int i =0; i< size; i++)
        {
            total += arr1[i];
            cout << arr1[i] << " "; 
            arr1[i] = 1;
        }
        return;
    }
    if(weight + arr[k] > m || k == size)
    {
        return;
    }
    arr1[k] = 1;
    sosp(arr, m, size, weight+arr[k], total - arr[k], k+1, arr1);
    arr1[k] = 0;
    sosp(arr, m, size, weight, total - arr[k], k+1,arr1);
    
    
}

int main()
{
    int arr[] = {2,3,5,6,8,10};
    int m = 10;
    int size = 6;
    int total = 0;
    for(int i =0; i< size; i++)
    {
        total += arr[i];
        cout << arr[i] << " "; 
    }
    cout << endl;
    int weight = 0;
    int arr1[6] = {0};
    sosp(arr,m,size,weight,total,0,arr1);
    cout << count;
}
