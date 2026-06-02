#include <iostream>
using namespace std;

char board[3][3] =
    {
        {'X', '.', '.'},
        {'O', 'O', '.'},
        {'X', '.', 'O'}};

void print_board()
{
      for (int i = 0; i < 3; i++)
      {
            for (int j = 0; j < 3; j++)
            {
                  cout << board[i][j];

                  if (j < 2)
                        cout << " | ";
            }

            if (i < 2)
                  cout << "\n---+---+---\n";
      }
}

int main()
{
      print_board();
      return 0;
}