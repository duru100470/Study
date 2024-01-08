#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    vector<pair<int, int>> v;
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        v.push_back(make_pair(a, b));
    }

    for (auto iter : v)
    {
        if (iter.first > iter.second)
        {
            if (iter.first % iter.second == 0)
                cout << "multiple\n";
            else
                cout << "neither\n";
        }
        else if (iter.first < iter.second)
        {
            if (iter.second % iter.first == 0)
                cout << "factor\n";
            else
                cout << "neither\n";
        }
        else
            cout << "neither\n";
    }
    
    return 0;
}