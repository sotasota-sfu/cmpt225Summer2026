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
            cout << p->data << " ";
            p = p->next;
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

void clear_loop(){
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

void clear_rec(){
      clear_helper(head);
      head = nullptr;
}

void clear_helper(Node* p){
      if(p = nullptr)
            return;

      clear_helper(p->next);
      delete p;
}

int size_loop(){
      Node* p = head;
      int count = 0;
      while(p != nullptr){
            count++;
            p = p->next;
      }
      return count;
}

int size_rec(){
      return size_helper(head);
}
int size_helper(Node* p){
      if(p = nullptr)
            return 0;
      return 1  + size_helper(p->next);
}

bool contains_loop(const string &value){
      Node* p = head;
      while(p != nullptr){
            if(p->data == value)
                  return true;
            p = p->next;
      }
      return false;
}

bool contains_rec(const string &value)
{
      return contains_helper(head, value);
}
bool contains_helper(Node* p, const string &value){
      if(p == nullptr)
            return false;
      if(p->data == value)
            return true;
      return contains_helper(p->next, value);
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