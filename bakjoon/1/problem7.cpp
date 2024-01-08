#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int a, b;
    cin >> a >> b;
    cout << a * (b % 10) << endl;
    cout << a * (b % 100 - b % 10) / 10 << endl;
    cout << a * (b % 1000 - b % 100) / 100 << endl;
    cout << a * b << endl;
    return 0;
}