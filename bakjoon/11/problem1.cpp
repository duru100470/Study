#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char** argv) {
    int cnt;
    cin >> cnt;

    int arr[cnt];
    for (size_t i = 0; i < cnt; i++)
    {
        cin >> arr[i];
    }

    for (int i = cnt; i > 0; i--)
    {
        for (int j = 0; j < i-1; j++)
        {
            if (arr[j] > arr[j+1]){
                swap(arr + j, arr + j + 1);
            }
        }
    }
    
    for (int i = 0; i < cnt; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}