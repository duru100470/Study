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

    int arr[cnt];
    for (size_t i = 0; i < cnt; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + cnt);

    for (int i = 0; i < cnt; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}