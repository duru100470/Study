#include <bits/stdc++.h>

using namespace std;

int bsearch(vector<int> &data, int size, int value)
{
    int l = 0;
    int r = size - 1;
    int m;

    while (l <= r)
    {
        m = (l + r) / 2;
        if (data[m] > value)
            r = m - 1;
        else if (data[m] < value)
            l = m + 1;
        else
            return m;
    }
    return -1;
}

int main(int argc, const char **argv)
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(v[i]));
    }

    vector<int> index(v.begin(), v.end());
    sort(index.begin(), index.end());
    index.erase(unique(index.begin(), index.end()), index.end());

    for (int i = 0; i < n; i++)
    {
        printf("%d ", bsearch(index, index.size(), v[i]));
    }

    return 0;
}