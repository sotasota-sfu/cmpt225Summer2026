#include <iostream>
//(a) merge two already sorted lists into a new list
void mergeSort_s(int A[], int B[], int sizeA, int sizeB, int C[])
{
      int i = 0;
      int j = 0;
      int k = 0;

      while (i < sizeA && j < sizeB)
      {
            if (A[i] <= B[j])
            {
                  C[k] = A[i];
                  i++;
            }
            else
            {
                  C[k] = B[j];
                  j++;
            }
            k++;
      }

      while (i < sizeA)
      {
            C[k] = A[i];
            i++;
            k++;
      }
      while (j < sizeB)
      {
            C[k] = B[j];
            j++;
            k++;
      }
}

//(b) merge sort
void mergeSort_u(int A[], int low, int high)
{
      if (low >= high)
            return;

      int mid = (low + high) / 2;

      mergeSort_u(A, low, mid);
      mergeSort_u(A, mid + 1, high);

      merge(A, low, mid, high);
}

void merge(int A[], int low, int mid, int high)
{
      int n = high - low + 1;
      int *temp = new int[n];

      int i = low;
      int j = mid + 1;
      int k = 0;

      while (i < mid && j < high)
      {
            if (A[i] < A[j])
            {
                  temp[k] = A[i];
                  i++;
            }
            else
            {
                  temp[k] = A[j];
                  j++;
            }
            k++;
      }
      while (i <= mid)
      {
            temp[k] = A[i];
            i++;
            k++;
      }

      while (j <= high)
      {
            temp[k] = A[j];
            j++;
            k++;
      }

      for (int x = 0; x < n; x++)
      {
            A[low + x] = temp[x];
      }

      delete[] temp;
}