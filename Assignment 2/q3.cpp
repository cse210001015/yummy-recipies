#include <bits/stdc++.h>
using namespace std;

int tile_number = 0;

void fill(int x1, int y1, int x2, int y2, int x3, int y3, vector<vector<int>> &board)
{
    tile_number++;
    board[x1][y1] = tile_number;
    board[x2][y2] = tile_number;
    board[x3][y3] = tile_number;
}

void func(int n, int r, int c, vector<vector<int>> &board)
{

    int missing_cell_row, missing_cell_col;

    if (n == 2)
    {
        tile_number++;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[r + i][c + j] == 0)
                {
                    board[r + i][c + j] = tile_number;
                }
            }
        }
        return;
    }
    else
    {
        for (int i = r; i < r + n; i++)
        {
            for (int j = c; j < c + n; j++)
            {
                if (board[i][j] != 0)
                        missing_cell_row = i,
                        missing_cell_col = j;
            }
        }
    }
    if (missing_cell_row < r + n / 2 && missing_cell_col < c + n / 2)
    {
        fill(r + n / 2, c + (n / 2) - 1, r + n / 2, c + n / 2, r + n / 2 - 1, c + n / 2, board);
    }

    else
         if (missing_cell_row >= r + n / 2 && missing_cell_col < c + n / 2)
        {
            fill(r + (n / 2) - 1, c + (n / 2), r + (n / 2), c + n / 2, r + (n / 2) - 1, c + (n / 2) - 1, board);
        }

    else  if (missing_cell_row < r + n / 2 && missing_cell_col >= c + n / 2)
    {
        fill(r + n / 2, c + (n / 2) - 1, r + n / 2, c + n / 2, r + n / 2 - 1, c + n / 2 - 1, board);
    }

    else  if (missing_cell_row >= r + n / 2 && missing_cell_col >= c + n / 2)
    {
        fill(r + (n / 2) - 1, c + (n / 2), r + (n / 2), c + (n / 2) - 1, r + (n / 2) - 1, c + (n / 2) - 1, board);
    }

    func(n / 2, r, c + n / 2, board);
    func(n / 2, r, c, board);
    func(n / 2, r + n / 2, c, board);
    func(n / 2, r + n / 2, c + n / 2, board);

    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin >> n;
    vector<vector<int>> board ;
    for(int i=0;i<n;i++){
    	vector<int> t;
    	for(int j=0;j<n;j++){
    		int x;
    		cin >> x;
    		t.push_back(x);
		}
		board.push_back(t);
	}
    
    func(n, 0, 0, board);
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
