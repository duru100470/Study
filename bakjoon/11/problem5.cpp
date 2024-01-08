#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N;
    cin >> N;

    list<int> digit;

    while (N > 9)
    {
        int num = N % 10;
        digit.push_back(num);
        N /= 10;
    }
    digit.push_back(N);
    digit.sort();

    while (digit.size() > 0)
    {
        cout << digit.back();
        digit.pop_back();
    }
    cout << endl;

    return 0;
}