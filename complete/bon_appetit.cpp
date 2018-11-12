#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/**
 * @brief: Splits the bill, with the exception of one item, and compares
 *              the price actually charged vs what should be charged.
 * @params: bill: Integers representing the cost of each item.
 *             k: Index of the item not eaten.
 *             b: Money contributed toward bill.
 * @runtime:    O(N)
 */
void bonAppetit(vector<int> bill, int k, int b)
{
    int running_bill = 0;
    for (auto item : bill) 
    {
        running_bill += item;
    }

    running_bill -= bill[k];

    int half = running_bill / 2;

    if (half == b) 
    {
        cout << "Bon Appetit" << endl;
    }
    else
    {
        cout << b - half << endl;
    }
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split(rtrim(nk_temp));

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string bill_temp_temp;
    getline(cin, bill_temp_temp);

    vector<string> bill_temp = split(rtrim(bill_temp_temp));

    vector<int> bill(n);

    for (int i = 0; i < n; i++)
    {
        int bill_item = stoi(bill_temp[i]);

        bill[i] = bill_item;
    }

    string b_temp;
    getline(cin, b_temp);

    int b = stoi(ltrim(rtrim(b_temp)));

    bonAppetit(bill, k, b);

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
