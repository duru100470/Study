#include <bits/stdc++.h>

using namespace std;

bool cmp(string s1, string s2)
{
    if (s1.length() == s2.length())
        return s1 < s2;
    else
        return s1.length() < s2.length();
}

int main(int argc, const char **argv)
{
    int N;
    cin >> N;
    vector<string> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);
    list<string> l(v.begin(), v.end());
    l.unique();

    for (list<string>::iterator iter = l.begin(); iter != l.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}