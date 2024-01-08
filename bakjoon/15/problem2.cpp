#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void dfs(int num, int depth, int goal)
{
    if (depth == goal)
    {
        for (auto iter : arr)
            cout << iter << " ";
        cout << "\n";
        arr.pop_back();
        return;
    }

    for (int i = 1; i <= num; i++)
        if (find(arr.begin(), arr.end(), i) == arr.end())
        {
            if (depth > 0 && *(arr.end() - 1) > i) continue;
            arr.push_back(i);
            dfs(num, depth + 1, goal);
        }

    arr.pop_back();
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    dfs(n, 0, m);

    return 0;
}