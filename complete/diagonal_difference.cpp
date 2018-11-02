#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr)
{
    int row_size = arr.size();
    int col_size = arr[0].size();
    int pri_diag = 0;
    int sec_diag = 0;

    /* Calculate primary diagonal. */
    for (int row = 0; row < row_size; row++)
    {
        for (int col = 0; col < col_size; col++)
        {
            if (row == col)
            {
                pri_diag += arr[row][col];
            }
        }
    }

    /* Calculate secondary diagonal. */
    for (int row = 0; row < row_size; row++)
    {
        for (int col = col_size - 1; col >= 0; col--)
        {
            if (row + col == (row_size - 1))
            {
                sec_diag += arr[row][col];
            }
        }
    }    

    /* Absolute difference. */
    return abs(pri_diag - sec_diag);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(n);

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
