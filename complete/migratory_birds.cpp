// https://www.hackerrank.com/challenges/migratory-birds/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/**
 * @brief:  Given an array of occurrences of 5 differenct bird types,
 *          we are tasked with returning the bird number with the most occurrences.
 * @params: An array of birds numbered 1 - 5.
 * @runtime:    O(N log N)
 */
int migratoryBirds(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    vector<int> birds;
    for (int i = 0; i < 5; i++)
    {
        birds.push_back(0);
    }

    for (auto a : arr)
    {
        switch (a)
        {
        case 1:
            birds[0]++;
            break;
        case 2:
            birds[1]++;
            break;
        case 3:
            birds[2]++;
            break;
        case 4:
            birds[3]++;
            break;
        case 5:
            birds[4]++;
            break;
        }
    }
    int num_of_birds = 0, bird = 0;

    for (unsigned int i = 0; i < birds.size(); i++)
    {
        if (birds[i] > num_of_birds)
        {
            num_of_birds = birds[i];
            bird = i;
        }
    }

    return bird + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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
