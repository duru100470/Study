#include <bits/stdc++.h>

using namespace std;

map<int, int> prime;

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    prime.insert({2, 0}); prime.insert({5, 0});
    for (int i = 1; i <= N; i++)
    {
        int num = i;
        while (num % 2 == 0)
        {
            num /= 2;
            prime[2]++;
        }
        while (num % 5 == 0)
        {
            num /= 5;
            prime[5]++;
        }
    }

    cout << min(prime[2], prime[5]) << "\n";

    return 0;
}