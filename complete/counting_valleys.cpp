// https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

/**
 *  @brief:     Keeps track of how many times a position goes below '0'.
 *  @param:     int n : Number of steps in hike.
 *              string s : String of 'U' or 'D'.
 *  @runtime:   O(N)
 */
int countingValleys(int n, string s)
{
    int current_elev = 0, previous_elev = 0, num_of_valleys = 0;
    bool in_valley = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'U')
        {
            previous_elev = current_elev;
            current_elev++;
        }
        else
        {
            previous_elev = current_elev;
            current_elev--;
            
            if (previous_elev == 0 && current_elev == -1)
            {
                num_of_valleys++;
            }
        }
    }

    return num_of_valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
