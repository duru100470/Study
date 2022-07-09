#include <bits/stdc++.h>

using namespace std;

bool CheckInRange(pair<int, int> coor, tuple<int, int, int> planet)
{
    int _dist = pow(coor.first - get<0>(planet), 2) + pow(coor.second - get<1>(planet), 2);
    if (_dist < pow(get<2>(planet), 2))
        return true;
    else
        return false;
}

int main(int argc, const char **argv)
{
    int T;
    cin >> T;
    vector<int> ret;
    for (int i = 0; i < T; i++)
    {
        vector<pair<int, int>> coor(2);
        cin >> coor[0].first >> coor[0].second >> coor[1].first >> coor[1].second;

        int N, num1 = 0, num2 = 0;
        cin >> N;
        vector<tuple<int, int, int>> planet;
        for (int i = 0; i < N; i++)
        {
            int x, y, r;
            cin >> x >> y >> r;
            planet.push_back(make_tuple(x, y, r));
        }

        for (auto iter : planet)
        {
            bool c1 = CheckInRange(coor[0], iter);
            bool c2 = CheckInRange(coor[1], iter);
            if (c1)
                num1++;
            if (c2)
                num2++;
            if (c1 && c2)
            {
                num1--;
                num2--;
            }
        }

        ret.push_back(num1 + num2);
    }

    for (auto iter : ret)
    {
        cout << iter << endl;
    }

    return 0;
}