#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int x, y;
    vector<pair<int, int>> coor(3);

    for (size_t i = 0; i < 3; i++)
    {
        cin >> coor[i].first >> coor[i].second;
    }

    if (coor[0].first == coor[1].first)
        x = coor[2].first;
    else if (coor[0].first == coor[2].first)
        x = coor[1].first;
    else
        x = coor[0].first;

    if (coor[0].second == coor[1].second)
        y = coor[2].second;
    else if (coor[0].second == coor[2].second)
        y = coor[1].second;
    else
        y = coor[0].second;
    
    cout << x << " " << y << endl;

    return 0;
}