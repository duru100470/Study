#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    string S;
    set<string> v;
    cin >> S;

    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 0; j < S.length(); j++)
        {
            string tmp = S.substr(i, j+1);
            v.insert(tmp);
        }
    }

    cout << v.size() << endl;
    return 0;
}
