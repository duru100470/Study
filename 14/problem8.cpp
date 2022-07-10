#include <bits/stdc++.h>

using namespace std;

int GetCombination(int n, int r)
{
    vector<vector<int>> arr(r + 1, vector<int>(n, 1));

    for (int i = 1; i < r + 1; i++)
        for (int j = 0 + i; j < n; j++)
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
    return arr[r][n - 1];
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << GetCombination(b, a) << "\n";
    }

    return 0;
}