#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N;
    cin >> N;

    int height[N];
    int weight[N];
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d %d", weight + i, height + i);
    }

    for (int i = 0; i < N; i++)
    {
        int rank = 0;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (weight[i] < weight[j] && height[i] < height[j])
            {
                rank++;
            }
        }
        cout << (rank + 1) << " ";
    }
    cout << endl;
    return 0;
}