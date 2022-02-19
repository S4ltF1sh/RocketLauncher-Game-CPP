#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s = "12345";
    s.push_back('1');
    s.pop_back();

    vector<int> a;
    a.push_back(1);

    int r = 0;
    int arr[] = {};

    int row = 60, col = 100;

    long long matrix[row][col];
    long long res[col][row];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            matrix[i][j] = arr[r++];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            res[col - j - 1][i] = matrix[i][j];
    }

    for (int i = col - 1; i >= 0; i--)
    {
        for (int j = 0; j < row; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}