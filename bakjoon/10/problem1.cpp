#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int N, M;
    cin >> N >> M;

    int numbers[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    int max = 0;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            for (size_t k = j + 1; k < N; k++)
            {
                int sum = (numbers[i] + numbers[j] + numbers[k]);

                if (max < sum && sum <= M)
                {
                    max = sum;
                }
            }
        }
    }

    cout << max << endl;
    return 0;
}