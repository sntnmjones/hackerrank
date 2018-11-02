#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for (int i = 1; i <= n; i++)
    {
        int no_of_spaces = n - i;
        for (int j = 0; j < no_of_spaces; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "#";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
