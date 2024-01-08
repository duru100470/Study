#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N, M;
    cin >> N;
    map<int, int> m;
    for (size_t i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        map<int, int>::iterator iter = m.find(num);
        if (iter != m.end())
            (iter->second)++;
        else
            m.insert({num, 1});
    }

    cin >> M;
    vector<int> v2(M);
    for (size_t i = 0; i < M; i++)
    {
        scanf("%d", &(v2[i]));
    }

    for (auto iter : v2)
    {
        map<int, int>::iterator it = m.find(iter);
        if (it == m.end())
            printf("0 ");
        else
            printf("%d ", it->second);
    }

    return 0;
}