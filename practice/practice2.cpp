#include <iostream>
#include<cstdlib>
using namespace std;

void print_board(char board[3][3])
{
      // ...
      for (int i = 0; i < 3; i++)
      {
            for (int j = 0; j < 3; j++)
            {
                  cout << board[i][j] << " ";
            }
            cout << endl;
      }
}

int main(){
      char board[3][3]{
            {'X', '.', 'O'},
            {'O', 'X', 'X'},
            {'.', '.', 'O'}
      };

      print_board(board);
}