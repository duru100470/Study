#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    vector<int> value;

    value.push_back(x);
    value.push_back(y);
    value.push_back(w - x);
    value.push_back(h - y);

    cout << *min_element(value.begin(), value.end()) << endl;

    return 0;
}