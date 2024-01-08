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

string GetFraction(int x, int y)
{
    int div = gcd(x, y);
    return to_string( x / div ) + "/" + to_string( y / div );
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    vector<int> gear;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        gear.push_back(input);
    }

    for (int i = 1; i < N; i++)
    {
        cout << GetFraction(gear[0], gear[i]) << "\n";
    }
    
    return 0;
}