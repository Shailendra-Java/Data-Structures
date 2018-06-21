#include<iostream>
using namespace std;

int main()
{
	int size, arr[50], i, j, temp, min_index;
	cout<<"Enter Array Size : ";
	cin>>size;
	cout<<"Enter Array Elements : ";
	for(i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<"Sorting array using selection sort...\n";
	for(i=0; i<size; i++)
	{
		min_index = i;
		for(j=i+1; j<size; j++)
		{
			if(arr[i]>arr[j])
			{
				min_index = j;
			}
		}
		temp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = temp;
	}
	cout<<"Now the Array after sorting is :\n";
	for(i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
