#include <bits/stdc++.h>

using namespace std;

int GetPrimeFactor(int num, int factor, int depth)
{
    if (num < pow(factor, depth)) return 0;
    return num / pow(factor, depth) + GetPrimeFactor(num, factor, depth + 1);
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, x5 = 0, x2 = 0;
    cin >> N >> M;
    if (M > N / 2)
        M = N - M;

    x5 += GetPrimeFactor(N, 5, 1);
    x5 -= GetPrimeFactor(N-M, 5, 1);
    x5 -= GetPrimeFactor(M, 5, 1);
    x2 += GetPrimeFactor(N, 2, 1);
    x2 -= GetPrimeFactor(N-M, 2, 1);
    x2 -= GetPrimeFactor(M, 2, 1);
    cout << min(x2, x5) << "\n";

    return 0;
}