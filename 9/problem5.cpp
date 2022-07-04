#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int rest(int a, int b)
{
    return 6 - a - b;
}

void hanoi(int from, int to, int height)
{
    if (height == 1)
    {
        v.push_back({from, to});
    }
    else
    {
        hanoi(from, rest(from, to), height - 1);
        v.push_back({from, to});
        hanoi(rest(from, to), to, height - 1);
    }
}

int main(int argc, const char **argv)
{
    int input;
    cin >> input;
    cout << (1<<input)-1 << endl;
    hanoi(1, 3, input);
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    
    return 0;
}