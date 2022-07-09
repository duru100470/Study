#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int num, max_size, sum = 0;
    vector<int> len(6), s(6);
    cin >> num;
    for (int i = 0; i < 6; i++)
    {
        int tmp;
        cin >> tmp >> len[i];
    }

    for (int i = 0; i < 5; i++)
    {
        s[i] = len[i] * len[i+1];
    }
    s[5] = len[5] * len[0];

    max_size = *max_element(s.begin(), s.end());
    for (auto iter : s)
    {
        sum += iter;
    }
    sum -= max_size * 2;

    cout << sum * num<< endl;
    return 0;
}