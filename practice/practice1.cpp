// Implement insertion sort on an array of strings:

#include <iostream>
using namespace std;

void insertion_sort(string arr[], int n){
      for(int i = 1; i < n; i++){
            string cur = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > cur){
                  arr[j + 1] = arr[j];
                  j--;
            }
            arr[j + 1] = cur;
      }
}

void printArray(string A[], int size)
{
      for (int i = 0; i < size; i++)
      {
            cout << A[i] << " ";
      }
      cout << endl;
}

int main(){
      string A[] = {"h", "bia", "hjai", "a"};
      int size = 4;

      cout << "Before: ";
      printArray(A, size);

      insertion_sort(A, size);

      cout << "After: ";
      printArray(A, size);
}