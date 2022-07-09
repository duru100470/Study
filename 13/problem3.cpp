#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    vector<int> v1, v2, v3;
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        v1.push_back(a);
        v2.push_back(b);
        v3.push_back(c);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i]*v1[i] + v2[i]*v2[i] == v3[i]*v3[i])
            cout << "right\n";
        else if (v2[i]*v2[i] + v3[i]*v3[i] == v1[i]*v1[i])
            cout << "right\n";
        else if (v3[i]*v3[i] + v1[i]*v1[i] == v2[i]*v2[i])
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}