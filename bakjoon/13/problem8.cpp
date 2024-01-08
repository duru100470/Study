#include <bits/stdc++.h>

using namespace std;

bool CheckInRange(pair<int, int> coor, tuple<int, int, int> circle)
{
    int _dist = pow(coor.first - get<0>(circle), 2) + pow(coor.second - get<1>(circle), 2);
    if (_dist <= pow(get<2>(circle), 2))
        return true;
    else
        return false;
}

int main(int argc, const char **argv)
{
    int W, H, X, Y, P, cnt = 0;
    cin >> W >> H >> X >> Y >> P;
    vector<pair<int, int>> person;

    for (int i = 0; i < P; i++)
    {
        int x, y;
        cin >> x >> y;
        person.push_back(make_pair(x, y));
    }

    for (auto iter : person)
    {
        if (iter.first >= X && iter.first <= X + W && iter.second >= Y && iter.second <= Y + H)
        {
            cnt++;
            continue;
        }
        if (CheckInRange(iter, make_tuple(X, Y + (H / 2), H / 2)))
        {
            cnt++;
            continue;
        }
        if (CheckInRange(iter, make_tuple(X + W, Y + (H / 2), H / 2)))
        {
            cnt++;
            continue;
        }
    }

    cout << cnt << endl;

    return 0;
}