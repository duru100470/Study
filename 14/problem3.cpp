#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int main(int argc, const char **argv)
{
    vector<int> ret;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int m, n;
        cin >> m >> n;
        if (n > m)
        {
            int tmp = m;
            m = n;
            n = tmp;
        }
        ret.push_back((m * n) / gcd(m, n));
    }
    for (auto iter : ret)
        cout << iter << endl;

    return 0;
}