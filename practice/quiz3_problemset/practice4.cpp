#include <iostream>
using namespace std;

class HeapPriorityQueue
{
private:
      int* T;
      int capacity;
      int n;

public:
      HeapPriorityQueue();
      ~HeapPriorityQueue();

      int size() const;
      bool is_empty()const;
      void insert(const int &e);

      const int& min();
      void remove_min();

private:
      void upHeap(int i)
      {
            while(i > 0){
                  int p = parent(i);

                  if(T[i] < T[p]){
                        swap(i, p);
                        i = p;
                  }
                  else
                        break;
            }
      }

      void downHeap(int i)
      {
            while(left(i) < n)
            {
                  int child = left(i);
                  if(right(i) < n && T[right(i)] < T[left(i)])
                  {
                        child = right(i);
                  }
                  if(T[child] < T[i])
                  {
                        swap(i, child);
                        i = child;
                  }
            }
      }

      int parent(int i) const
      {
            return (i - 1) / 2;
      }

      int left(int i) const
      {
            return 2 * i + 1;
      }

      int right(int i) const
      {
            return 2 * i + 2;
      }

      void swap(int i, int j){
            int temp = T[i];
            T[i] = T[j];
            T[j] = T[i];
      }

      void resize(){
            capacity += 2;
            int* newT = new int[capacity];

            for(int i = 0; i < n; i++){
                  newT[i] = T[i];
            }
            delete[] T;
            T = newT;
      }
};

HeapPriorityQueue::HeapPriorityQueue()
{
      capacity = 10;
      n = 0;
      T = new int [capacity];
}
HeapPriorityQueue::~HeapPriorityQueue()
{
      delete[] T;
}

int HeapPriorityQueue::size() const
{
      return n;
}
bool HeapPriorityQueue::is_empty() const
{
      return n == 0;
}
void HeapPriorityQueue::insert(const int &e)
{
      if(n == capacity)
      {
            resize();
      }
      T[n] = e;
      upHeap(n);
      n++;
}

const int& HeapPriorityQueue::min()
{
      return T[0];
}
void HeapPriorityQueue::remove_min()
{
      if(is_empty()){
            return;
      }
      swap(0, n - 1);
      n--;
      if (!is_empty())
      {
            downHeap(0);
      }
}