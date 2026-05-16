#include <iostream>
using namespace std;

struct Node
{
      string data;
      Node *next;
};

Node *head = nullptr;

bool is_empty_list(){
      return head == nullptr;
}

void print(){
      Node *p = head;
      while(p != nullptr){
            cout << head->data << " ";
            head = head->next;
      }
      cout << endl;
}

void push_front(const string &value){
      Node* p = new Node;
      p->data = value;
      p->next = head;
      head = p;
}

void remove_front(){
      if (is_empty_list())
            return;
      Node* p = new Node;
      p = head;
      head = head->next;
      delete p;
}

void clear(){
      Node *p = head;
      while (p != nullptr)
      {
            Node* temp = p;
            p = p->next;
            delete temp;
      }
      head = nullptr;

      //もう一個のやり方はこれ、こっちの方が各コードも少ないし見やすい気がする
      // while(!is_empty_list()){
      //       remove_front();
      // }
}

int size(){
      Node* p = head;
      int count = 0;
      while(p != nullptr){
            count++;
            p = p->next;
      }
      return count;
}

bool contains(const string &value){
      Node* p = head;
      while(p != nullptr){
            if(p->data == value)
                  return true;
            p = p->next;
      }
      return false;
}

Node *last_node(){
      if(is_empty_list)
            return nullptr;
      
      Node* p = head;
      while(p->next != nullptr){
            p = p->next;
      }
      return p;
}

void push_back(const string &value){
      Node* p = new Node;
      p->data = value;
      p->next = nullptr;

      if (is_empty_list()){
            head = p;
            return;
      }

      Node* last = last_node();
      last->next = p;
}

void remove_back(){
      if(is_empty_list())
            return;
      
      if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
      }

      Node* p = head;
      while(p->next != nullptr){
            p = p->next;
      }
      delete p->next;
      p->next = nullptr;
}

int main(){

}