#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// bool hasRowX(vector<vector<char>>& board, int row, int col, int all_row, int all_col)
	// {
	// 	bool left = false, right = false;
	// 	for (int i = col - 1; i >= 0; --i)
	// 	{
	// 		//if (board[row][i] == 'X') 
	// 		if (hasRowX(board, row, i, all_row, all_col) &&
	// 			hasColX(board, row, i, all_row, all_col))
	// 		{
	// 			left = true;
	// 			break;
	// 		}
	// 	}

	// 	for (int i = col + 1; i < all_col; ++i)
	// 	{
	// 		//if (board[row][i] == 'X') 
	// 		if (hasRowX(board, row, i, all_row, all_col) &&
	// 			hasColX(board, row, i, all_row, all_col))
	// 		{
	// 			right = true;
	// 			break;
	// 		}
	// 	}

	// 	if (left && right) return true;
	// 	else return false;
	// }

	// bool hasColX(vector<vector<char>>& board, int row, int col, int all_row, int all_col)
	// {
	// 	bool up = false, down = false;
	// 	for (int i = row - 1; i >= 0; --i)
	// 	{
	// 		//if (board[i][col] == 'X') 
	// 		if (hasRowX(board, i, col, all_row, all_col) &&
	// 			hasColX(board, i, col, all_row, all_col))
	// 		{
	// 			up = true;
	// 			break;
	// 		}
	// 	}

	// 	for (int i = row + 1; i < all_row; ++i)
	// 	{
	// 		if (hasRowX(board, i, col, all_row, all_col) &&
	// 			hasColX(board, i, col, all_row, all_col))
	// 		{
	// 			down = true;
	// 			break;
	// 		}
	// 	}

	// 	if (up && down) return true;
	// 	else return false;
	// }

    // void solve1(vector<vector<char>>& board) {
	// 	//if (nullptr == board) return;
    //     int row = board.size();
	// 	if (row < 3) return;
	// 	int col = board[0].size();
	// 	if (col < 3 ) return;

	// 	for ( int i = 1; i < row - 1; ++i)
	// 	{
	// 		for ( int j = 1; j < col - 1; ++j)
	// 		{
	// 			if (board[i][j] == 'O' && hasRowX(board, i, j, row, col) && hasColX(board, i, j, row, col))
	// 			{
	// 				board[i][j] = 'X';
	// 			}
	// 		}
	// 	}
    // }

	// void realBuildOBoard(vector<vector<char>>& board, vector<vector<char>>& oBoard, int row, int col, int all_row, int all_col)
	// {
	// 	if (row < 0 || col < 0 || row >= all_row || col >= all_col || oBoard[row][col] != '0' || board[row][col] == 'X')
	// 		return;

	// 	oBoard[row][col] = '1';
	// 	realBuildOBoard(board, oBoard, row + 1, col, all_row, all_col);
	// 	realBuildOBoard(board, oBoard, row - 1, col, all_row, all_col);
	// 	realBuildOBoard(board, oBoard, row, col - 1, all_row, all_col);
	// 	realBuildOBoard(board, oBoard, row, col + 1, all_row, all_col);
	// }

	// void buildOBoard(vector<vector<char>>& board, vector<vector<char>>& oBoard)
	// {
	// 	int row = board.size();
	// 	int col = board[0].size();

	// 	//四个角不用管
	// 	//第一列和最后一列
	// 	for ( int i = 1; i < row - 1; ++i)
	// 	{
	// 		int j = 0;
	// 		realBuildOBoard(board, oBoard, i, j, row, col);
	// 		j = col - 1;
	// 		realBuildOBoard(board, oBoard, i, j, row, col);
	// 	}

	// 	// 第一行和最后一行
	// 	for ( int i = 1; i < col - 1; ++i)
	// 	{
	// 		int j = 0;
	// 		realBuildOBoard(board, oBoard, j, i, row, col);
	// 		j = row - 1;
	// 		realBuildOBoard(board, oBoard, j, i, row, col);
	// 	}

	// }

	// void solve(vector<vector<char>>& board) {
	// 	//if (nullptr == board) return;
    //     int row = board.size();
	// 	if (row < 3) return;
	// 	int col = board[0].size();
	// 	if (col < 3 ) return;

	// 	vector<vector<char>> oBoard;
	// 	for(int i = 0; i < row; ++i)
	// 	{
	// 		vector<char> tmp(col, '0');
	// 		oBoard.push_back(tmp);
	// 	}

	// 	buildOBoard(board, oBoard);

	// 	for (auto i : oBoard)
	// 	{
	// 		for (auto j : i)
	// 			cout << j << " ";
	// 		cout << endl;
	// 	}

	// 	for ( int i = 1; i < row - 1; ++i)
	// 	{
	// 		for ( int j = 1; j < col - 1; ++j)
	// 		{
	// 			if (board[i][j] == 'O' && oBoard[i][j] != '1')
	// 			{
	// 				board[i][j] = 'X';
	// 			}
	// 		}
	// 	}
    // }

	void readMarkNoNeedO(vector<vector<char>>& board, int row, int col, int all_row, int all_col)
	{
		if (row < 0 || col < 0 || row >= all_row || col >= all_col || board[row][col] != 'O')
			return;

		board[row][col] = 'N';
		readMarkNoNeedO(board, row + 1, col, all_row, all_col);
		readMarkNoNeedO(board, row - 1, col, all_row, all_col);
		readMarkNoNeedO(board, row, col + 1, all_row, all_col);
		readMarkNoNeedO(board, row, col - 1, all_row, all_col);
	}


	void markNoNeedO(vector<vector<char>>& board)
	{
		int row = board.size();
		int col = board[0].size();

		//四个角不用管
		//第一列和最后一列
		for ( int i = 1; i < row - 1; ++i)
		{
			int j = 0;
			readMarkNoNeedO(board, i, j, row, col);
			j = col - 1;
			readMarkNoNeedO(board, i, j, row, col);
		}

		// 第一行和最后一行
		for ( int i = 1; i < col - 1; ++i)
		{
			int j = 0;
			readMarkNoNeedO(board, j, i, row, col);
			j = row - 1;
			readMarkNoNeedO(board, j, i, row, col);
		}

	}

	void solve(vector<vector<char>>& board) {
		//if (nullptr == board) return;
        int row = board.size();
		if (row < 3) return;
		int col = board[0].size();
		if (col < 3 ) return;

		markNoNeedO(board);

		for ( int i = 0; i < row; ++i)
		{
			for ( int j = 0; j < col; ++j)
			{
				if (board[i][j] == 'N')
				{
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
			}
		}
    }
};

int main()
{
	Solution S;

	vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
									{'X', 'O', 'O', 'X'},
									{'X', 'X', 'O', 'X'},
									{'X', 'O', 'X', 'X'}};

	S.solve(board);

	for (auto i : board)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}
