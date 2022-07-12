#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

bool IsValidTransition(vector<pair<int, int>>& coor, pair<int, int> next)
{
    bool isValid = true;
    for (auto iter : coor)
    {
        if (iter.second == next.second)
        {
            isValid = false;
            break;
        }
        else if (abs(iter.first - next.first) == abs(iter.second - next.second))
        {
            isValid = false;
            break;
        }
    }
    return isValid;
}

void DFS(int goal, int depth, vector<pair<int, int>>& coor)
{
    if (goal == depth)
    {
        cnt++;
        coor.pop_back();
        return;
    }

    for (int i = 0; i < goal; i++)
    {
        pair<int, int> curCoor = make_pair(depth, i);
        if (IsValidTransition(coor, curCoor))
        {
            coor.push_back(curCoor);
            DFS(goal, depth + 1, coor);
        }
    }

    coor.pop_back();
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> coor;
    DFS(n, 0, coor);
    cout << cnt << "\n";
    return 0;
}