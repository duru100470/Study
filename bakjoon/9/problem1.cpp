#include <bits/stdc++.h>

using namespace std;

int facto(int num){
    if (num == 0) return 1;
    return num * facto(num-1);
}

int main(int argc, const char** argv) {
    int input;
    cin >> input;
    cout << facto(input) << endl;
    return 0;
}  