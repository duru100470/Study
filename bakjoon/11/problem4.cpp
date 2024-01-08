#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int cnt;
    cin >> cnt;

    int arr[cnt];
    for (size_t i = 0; i < cnt; i++)
    {
        scanf("%d", arr + i);
    }

    sort(arr, arr + cnt);

    int sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        sum += arr[i];
    }

    double mean = round(sum/(double)cnt);
    if (mean == -0) mean = 0;

    cout << mean << endl;

    printf("%d\n", arr[cnt / 2]);

    int freq[8001] = {0};
    for (int i = 0; i < cnt; i++)
    {
        freq[arr[i] + 4000]++;
    }
    int max = 0;
    int mode;
    for (int i = 0; i < 8001; i++)
    {
        if (max < freq[i])
        {
            max = freq[i];
            mode = i - 4000;
        }
    }

    for (int i = 0; i < 8001; i++)
    {
        if (freq[i] == max && i - 4000 != mode){
            mode = i - 4000;
            break;
        }
    }
    printf("%d\n", mode);

    printf("%d\n", arr[cnt - 1] - arr[0]);

    return 0;
}