#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int M, N;
    cin >> M >> N;

    char board[M][N];
    for (int i = 0; i < M; i++)
    {
        cin >> board[i];
    }

    int min = 64;
    for (int i = 0; i <= M-8; i++)
    {
        for (int j = 0; j <= N-8; j++)
        {
            // Get Minimum Change
            int startB = 0; int startW = 0;
            for (int x = i; x < i+8; x++)
            {
                for (int y = j; y < j+8; y++)
                {
                    if (x%2 == y%2){
                        if (board[x][y] == 'B')
                            startW++;
                        else
                            startB++;
                    }
                    else{
                        if (board[x][y] == 'B')
                            startB++;
                        else
                            startW++;
                    }
                }
            }

            if (startB > startW) startB = startW;
            if (min > startB) min = startB;
        }
    }
    cout << min << endl;
    
    return 0;
}