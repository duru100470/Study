#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N;
    cin >> N;

    int cnt = 0;
    int num = 0;
    while (cnt < N)
    {
        string tmp = to_string(num);

        if (tmp.find("666") != string::npos){
            cnt++;
        }
        num++;
    }
    
    cout << (num-1) << endl;
    return 0;
}