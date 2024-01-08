#include <bits/stdc++.h>

using namespace std;

void star(int x, int y, int num){
    if (num == 3){
        if (x == 1 && y == 1) cout << " ";
        else cout << "*";
        return;
    }else{
        int _x, _y;
        _x = x/(num/3);
        _y = y/(num/3);
        if (_x == 1 && _y == 1){
            cout << " ";
        }else{
            star(x%(num/3), y%(num/3), num/3);
        }
    }
}

void print_star(int num){
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            star(i, j, num);
        }
        cout << endl;
    }
}

int main(int argc, const char** argv) {
    int input;
    cin >> input;
    print_star(input);
    return 0;
}  