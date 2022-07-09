#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N, M, cnt = 0;
    cin >> N >> M;
    map<int, string> m1;
    map<string, int> m2;
    vector<string> v(M);

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        m1.insert({i+1, str});
        m2.insert({str, i+1});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < M; i++)
    {
        size_t idx;
        int num = stoi('0' + v[i], &idx);
        if (idx <= v[i].length())
        {
            printf("%d\n", m2.find(v[i])->second);
        }
        else
        {
            printf("%s\n", m1.find(num)->second.c_str());
        }
    }

    return 0;
}