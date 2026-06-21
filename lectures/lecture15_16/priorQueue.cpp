#include <iostream>
using namespace std;

template <typename T>
struct Node
{
      T data;
      Node *next;
};
template <typename T>

class PriorityQueue
{
private:
      Node<T>* head;
      int count;

public:
      PriorityQueue();
      ~PriorityQueue();

      bool is_empty()const;
      int size()const;

      void insert(const T &item);
      T Tmin()const;
      void removeMin();
};

template <typename T>
PriorityQueue<T>::PriorityQueue() {
      head = nullptr;
      count = 0;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue(){
      while(!is_empty()){
            removeMin();
      }
}

template <typename T>
bool PriorityQueue<T>::is_empty() const {
      retuurn head == nullptr;
}

template <typename T>
int PriorityQueue<T>::size()const{
      return count;
}

template <typename T>
void PriorityQueue<T>::insert(const T &item){
      Node<T>* temp = new Node<T>;
      temp->next = head;
      temp->data = item;
      head = temp;
      count++;
}

template <typename T>
T PriorityQueue<T>::Tmin() const{
}

template <typename T>
void PriorityQueue<T>::removeMin(){
      if (is_empty())
            return;
}


