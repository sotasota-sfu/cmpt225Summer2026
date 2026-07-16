#include <iostream>
using namespace std;

// (a) partition
int partitionFirst(int A[], int low, int high)
{
      int pivot = A[low];

      int i = low + 1;
      int j = high;

      while( i <= j)
      {
            while(i <= high && A[i] <= pivot)
                  i++;
            
            while(j > low && A[j] > pivot)
                  j--;

            if(i < j)
                  swap(A[i], A[j]);
      }
      return j;
}

// (b) quick sort
void quickSort(int A[], int low, int high)
{
      if(low >= high)
            return;
      
      int p = partitionFirst(A, low, high);

      quickSort(A, low, p - 1);
      quickSort(A, p + 1, high);
}

int partitionLast(int A[], int low, int high)
{
      int pivot = A[high];

      int i = low - 1;

      for(int j = low; j < high; j++)
      {
            if(A[j] <= pivot)
            {
                  i++;
                  swap(A[i], A[j]);
            }
      }
      swap(A[i + 1], A[high]);
      return i + 1;
}