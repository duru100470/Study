#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(9, vector<int>(9, 0));
vector<int> num;
vector<pair<int, int>> coor;
bool isFinished = false;

bool IsValidTransition(int level, int n)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][coor[level].second] == n)
            return false;
        if (board[coor[level].first][i] == n)
            return false;
        if (board[(coor[level].first / 3) * 3 + i / 3][(coor[level].second / 3) * 3 + i % 3] == n)
            return false;
    }
    return true;
}

void DFS(int depth)
{
    if (coor.size() == depth)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
        isFinished = true;
        return;
    }

    for (int i = 1; i < 10; i++)
    {
        if (isFinished) return;
        if (IsValidTransition(depth, i))
        {
            board[coor[depth].first][coor[depth].second] = i;
            DFS(depth + 1);
            board[coor[depth].first][coor[depth].second] = 0;
        }
    }
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                coor.push_back(make_pair(i, j));
        }

    DFS(0);

    return 0;
}