#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool canPlace(int row, int col, int value, vector < vector <int> > board) {
  for(int i = 0; i < 9; i++)
  {
    if(board[i][col] == value ) return false;
    if(board[row][i] == value ) return false;
  }

  int startRow = (row / 3) * 3;
  int startCol = (col / 3) * 3;

  int endRow = (row / 3) * 3 + 3;
  int endCol = (col / 3) * 3 + 3;

  for(int i = startRow; i < endRow; i++)
    for(int j = startCol; j < endCol; j++)
      if(board[i][j] == value)
        return false;

  return true;
}

void print_solution(vector < vector <int> > board, int num_solved, int nextRow, int nextCol) {
  if(num_solved == 81)
  {
    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
        cout << board[i][j] << " ";
      cout << endl;
    }

    exit(1);
  }

  if(board[nextRow][nextCol] != 0)
  {
    if(nextCol == 8)
      print_solution(board, num_solved + 1, nextRow + 1, 0);
    else
      print_solution(board, num_solved + 1, nextRow, nextCol + 1);
  }

  for(int k = 1; k <= 9; k++)
  {
    if( canPlace(nextRow, nextCol, k, board) )
    {
      vector < vector <int> > board_new = board;
      board_new[nextRow][nextCol] = k;

      if(nextCol == 8)
        print_solution(board_new, num_solved + 1, nextRow + 1, 0);
      else
        print_solution(board_new, num_solved + 1, nextRow, nextCol + 1);
    }
  }
}

int main()
{
  vector <int> board_t(9);
  vector < vector <int> > board(9, board_t);

  int num_solved = 0;

  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      cin >> board[i][j];

  print_solution(board, 0, 0, 0);

  return 0;
}
