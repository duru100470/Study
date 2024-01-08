#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
vector<int> v, ret;

int GetDiff()
{
    int sum1 = 0, sum2 = 0;
    vector<int> other;
    for (int i = 0; i < arr.size(); i++)
        if (find(v.begin(), v.end(), i) == v.end())
            other.push_back(i);
    
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            sum1 += arr[v[i]][v[j]];
            sum1 += arr[v[j]][v[i]];
            sum2 += arr[other[i]][other[j]];
            sum2 += arr[other[j]][other[i]];
        }
    }

    return abs(sum1 - sum2);
}

bool IsValidTransition(int num, int level)
{
    if (find(v.begin(), v.end(), num) == v.end())
    {
        if (level > 0)
            if (v[level-1] > num) return false;
        return true;
    }
    else
        return false;
}

void DFS(int depth)
{
    if (depth == arr.size() / 2)
    {
        ret.push_back(GetDiff());
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (IsValidTransition(i, depth))
            {
                v.push_back(i);
                DFS(depth + 1);
            }
        }
    }
    v.pop_back();
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        arr.push_back(vector<int>(N, 0));
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    DFS(0);
    sort(ret.begin(), ret.end());
    cout << *(ret.begin()) << "\n";

    return 0;
}