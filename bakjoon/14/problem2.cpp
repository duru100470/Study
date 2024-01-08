#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int cnt;
    cin >> cnt;
    vector<int> num(cnt);
    for (size_t i = 0; i < cnt; i++)
        cin >> num[i];
    if (num.size() == 1)
        cout << pow(num[0], 2);
    else
        cout << *max_element(num.begin(), num.end()) * *min_element(num.begin(), num.end());
    cout << endl;
    return 0;
}