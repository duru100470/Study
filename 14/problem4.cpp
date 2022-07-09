#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n)
{
    if (n > m)
    {
        int tmp = m;
        m = n;
        n = tmp;
    }
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

void GetDivisors(int n, vector<int>& div)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n) div.push_back(i);
        else if(n % i== 0)
        {
            div.push_back(i);
            div.push_back(n/i);
        }
    }
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> num;
    vector<int> div;
    for (size_t i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }

    int mod = 0;
    for (int i = 1; i < N; i++)
    {
        mod = gcd(mod, abs(num[i] - num[0]));
    }
    GetDivisors(mod, div);
    sort(div.begin(), div.end());

    for (vector<int>::iterator i = div.begin() + 1; i != div.end(); i++)
    {
        cout << *i << "\n";
    }

    return 0;
}