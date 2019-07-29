#include<iostream>
using namespace std;

void binarySearch(int arr[], int start, int end, int itemSearch)
{
   int mid = (start+end)/2;
   while(start <= end){
      if(itemSearch == arr[mid]){
         cout<<itemSearch<<" found at position "<<mid+1<<endl;
         break;
      }
      else if(itemSearch > arr[mid])
         start = mid+1;
      else
         end = mid-1;
      mid = (start+end)/2;
   }
}

int main(void)
{
   int array[20];
   int itemSearch;
   cout<<"Enter 20 elements in array"<<endl;
   for(int i=0; i<20; i++)
      cin>>array[i];
   cout<<"Enter element to search"<<endl;
   cin>>itemSearch;

   binarySearch(array,0,19,itemSearch);

   return 0;
}
