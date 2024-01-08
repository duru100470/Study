#include <bits/stdc++.h>

using namespace std;

vector<int>::iterator bsearch(vector<int>& data, int size, int value)
{
    int low = 0;
    int high = size -1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data[mid] > value)
            high = mid -1;
        else if (data[mid] < value)
            low = mid + 1;
        else
            return data.begin() + mid;
    }
    return data.end();
}

int main(int argc, const char** argv) {
    int N, M;
    cin >> N;
    vector<int> v1(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());

    cin >> M;
    vector<int> v2(M);
    for (size_t i = 0; i < M; i++)
    {
        cin >> v2[i];
    }

    for (auto iter : v2)
    {
        if (bsearch(v1, v1.size(), iter) == v1.end())
            printf("0 ");
        else
            printf("1 ");
    }

    return 0;
}