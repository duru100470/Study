#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

int main(int argc, const char **argv)
{
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}