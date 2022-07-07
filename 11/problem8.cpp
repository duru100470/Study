#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
    return p1.first < p2.first;
}

int main(int argc, const char **argv)
{
    int N;
    cin >> N;
    vector<pair<int, string>> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        printf("%d %s\n", v[i].first, v[i].second.c_str());
    }
    return 0;
}