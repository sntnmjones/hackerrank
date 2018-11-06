// https://www.hackerrank.com/challenges/the-birthday-bar/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/**
 * @params: s: The numbers on each square of chocolate.
 *          d: The birthdate. (The sum the pieces should sum)
 *          m: The month of the birthdate. (How many pieces)
 */
int birthday(vector<int> s, int d, int m)
{
    int num_of_ways = -1;
    if (s.size() == 1)
    {
        /* If the element is eq to date. */
        if (s[0] == d && m == 1)
        {
            num_of_ways = 1;
        }
        else
        {
            num_of_ways = 0;
        }
    }
    else
    {
        num_of_ways = 0;
        for (unsigned int i = 0; i <= s.size() - m; i++)
        {
            int sum = 0;
            for (unsigned int j = i; j < (i + m); j++)
            {
                sum += s[j];
            }
            if (sum == d)
            {
                num_of_ways++;
            }
        }
    }

    return num_of_ways;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++)
    {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    string dm_temp;
    getline(cin, dm_temp);

    vector<string> dm = split(rtrim(dm_temp));

    int d = stoi(dm[0]);

    int m = stoi(dm[1]);

    int result = birthday(s, d, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
