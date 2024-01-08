#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int sum = 0; int cur = i;

        while (cur > 9)
        {
            sum += cur % 10;
            cur /= 10;
        }
        sum += cur + i;
        if (sum == N) 
        {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << '0' << endl;

    return 0;
}