#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char **argv)
{
    int cnt;
    cin >> cnt;

    int num_cnt[10000] = {0};
    int num;
    for (size_t i = 0; i < cnt; i++)
    {
        scanf("%d", &num);
        num_cnt[num-1]++;
    }

    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < num_cnt[i]; j++)
        {
            printf("%d\n", i+1);
        }
    }

    return 0;
}