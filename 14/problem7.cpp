#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r;
    vector<vector<int>> arr(r + 1, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        arr[0][i] = 1;
    for (int i = 0; i < r; i++)
        arr[i + 1][i] = 1;
    for (int i = 1; i < r + 1; i++)
    {
        for (int j = 0 + i; j < n; j++)
        {
            arr[i][j] = (arr[i][j-1] + arr[i-1][j-1]) % 10007;
        }
    }

    cout << arr[r][n-1] << "\n";

    return 0;
}