#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int itemSearch)
{
   if (end >= start)
   {
        int middle = start + (end - start)/2;

       //if found at mid position
        if (arr[middle] == itemSearch)
             return middle;

       // if item is smaller than mid element, search in left subarray
        if (arr[middle] > itemSearch)
          return binarySearch(arr, start, middle-1, itemSearch);

      //else search in right subarray
        return binarySearch(arr, middle+1, end, itemSearch);
   }

  //if element is not present return -1
    return -1;
}

int main(void)
{
   int array[] = {10, 15, 19, 24, 30};
   int size = sizeof(array)/ sizeof(array[0]);
   int itemSearch = 24;
   int position = binarySearch(array, 0, size-1, itemSearch);

   if(position<0)
     cout<<"Element not present in the array";

   else
      cout<<"Element is present at position "<<position+1;

   return 0;
}
