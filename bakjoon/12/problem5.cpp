#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N, M;
    cin >> N >> M;
    set<string> s1;
    set<string> s2;

    for (size_t i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        s1.insert(str);
    }

    for (size_t i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        if (s1.find(str) != s1.end())
            s2.insert(str);
    }

    cout << s2.size() << endl;
    for (auto iter : s2)
    {
        printf("%s\n", iter.c_str());
    }

    return 0;
}