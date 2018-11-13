#include <bits/stdc++.h>

using namespace std;

/**
 *  @brief:     Determines how many pages need to be turned to get to desired
 *                      page.
 *  @params:    n: Number of pages in the book.
 *              p: Page number desired.
 *  @runtime:   O(1)
 */
int pageCount(int n, int p)
{
    if (n >= p)
    {
        int dist_from_front = p - 0;
        int dist_from_back = n - p;

        if (dist_from_front <= dist_from_back)
        {
            if (p == 1)
            {
                return 0;
            }
            else
            {
                return p / 2;
            }
        }
        else
        {
            if (n == p)
            {
                return 0;
            }
            else if (n % 2 == 0)
            {
                if (dist_from_back == 1)
                {
                    return 1;
                }
                else if (p % 2 == 0)
                {
                    return (n - p) / 2;
                }
                else 
                {
                    return dist_from_back / 2 + 1;
                }
            }
            else
            {
                return dist_from_back / 2;
            }
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
