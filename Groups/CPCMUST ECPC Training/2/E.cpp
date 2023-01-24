#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        unsigned int n,m;
        cin >> n >> m;
        int chessBoard[n][m];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> chessBoard[i][j];
            }
        }
        int largest = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int currSum = 0;
                int currI = i, currJ = j;
                while (currI >= 0 && currI < n && currJ >= 0 && currJ < m)
                {
                    currSum += chessBoard[currI][currJ];
                    currI--;
                    currJ--;
                }
                currI = i, currJ = j;
                while (currI >= 0 && currI < n && currJ >= 0 && currJ < m)
                {
                    currSum += chessBoard[currI][currJ];
                    currI++;
                    currJ--;
                }
                currI = i, currJ = j;
                while (currI >= 0 && currI < n && currJ >= 0 && currJ < m)
                {
                    currSum += chessBoard[currI][currJ];
                    currI--;
                    currJ++;
                }
                currI = i, currJ = j;
                while (currI >= 0 && currI < n && currJ >= 0 && currJ < m)
                {
                    currSum += chessBoard[currI][currJ];
                    currI++;
                    currJ++;
                }
                currSum -= chessBoard[i][j]*3;
                largest = max(largest, currSum);
            }
        }
        cout << largest << endl;
    }
}