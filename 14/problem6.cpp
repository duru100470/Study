#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r, a = 1, b = 1;
    cin >> n >> r;

    for (int i = 0; i < r; i++)
    {
        a *= n - i;
        b *= i + 1;
    }

    cout << a / b << "\n";
    
    return 0;
}