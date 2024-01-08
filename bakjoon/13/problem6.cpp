#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int T;
    cin >> T;
    vector<int> ret(T);

    for (size_t i = 0; i < T; i++)
    {
        int x1, x2, y1, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        float _dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        if (_dist == 0)
        {
            if (r1 == r2)
                ret[i] = -1;
            else
                ret[i] = 0;
        }
        else if (_dist > (float)(r1 + r2))
        {
            ret[i] = 0;
        }
        else if (_dist == (float)(r1 + r2))
        {
            ret[i] = 1;
        }
        else
        {
            if (_dist + r1 < r2 || _dist + r2 < r1)
                ret[i] = 0;
            else if (_dist + r1 == (float)r2 || _dist + r2 == (float)r1)
                ret[i] = 1;
            else
                ret[i] = 2;
        }
    }

    for (auto iter : ret){
        cout << iter << endl;
    }

    return 0;
}