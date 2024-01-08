#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int oper[4] = {0};
vector<int> ret, v;

bool IsValidTransition(int op)
{
    int cnt = 0;
    for (auto iter : v)
    {
        if (iter == op)
            cnt++;
    }

    if (cnt < oper[op])
        return true;
    else
        return false;
}

void DFS(int depth)
{
    if (depth == num.size() - 1)
    {
        int result = num[0];
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 0)
                result += num[i + 1];
            else if (v[i] == 1)
                result -= num[i + 1];
            else if (v[i] == 2)
                result *= num[i + 1];
            else if (v[i] == 3)
                result /= num[i + 1];
        }
        ret.push_back(result);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (IsValidTransition(i))
            {
                v.push_back(i);
                DFS(depth + 1);
            }
        }
    }
    v.pop_back();
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }

    DFS(0);
    sort(ret.begin(), ret.end());
    cout << *(ret.end() - 1) << "\n"
         << *(ret.begin())
         << "\n";

    return 0;
}