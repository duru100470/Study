#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N, M, num1 = 0, num2 = 0;
    cin >> N >> M;
    set<int> s1;
    set<int> s2;

    for (size_t i = 0; i < N; i++)
    {
        int str;
        cin >> str;
        s1.insert(str);
    }

    for (size_t i = 0; i < M; i++)
    {
        int str;
        cin >> str;
        s2.insert(str);
    }

    for (auto iter : s1)
    {
        if (s2.find(iter) == s2.end())
            num1++;
    }

    for (auto iter : s2)
    {
        if (s1.find(iter) == s1.end())
            num2++;
    }

    cout << num1 + num2 << endl;
    return 0;
}
