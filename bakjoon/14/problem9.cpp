#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int cnt, ret = 1;
        cin >> cnt;
        map<string, int> wear;
        for (int i = 0; i<cnt; i++)
        {
            string a, b;
            cin >> a >> b;
            if (wear.find(b) != wear.end())
                wear[b]++;
            else
                wear.insert({b, 1});
        }

        for (auto iter : wear)
        {
            ret *= iter.second + 1;
        }
        cout << ret - 1 << "\n";
    }

    return 0;
}