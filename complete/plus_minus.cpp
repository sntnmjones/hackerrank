// https://www.hackerrank.com/challenges/plus-minus/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {

    int size = 0, pos = 0, neg = 0, zero = 0;

    size = arr.size();

    for (unsigned int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            neg++;
        }
        else if (arr[i] > 0)
        {
            pos++;
        }
        else
        {
            zero++;
        }
    }

    double pos_dbl = 0.0, neg_dbl = 0.0, zero_dbl = 0.0;

    pos_dbl = (double)pos / size;
    neg_dbl = (double)neg /size;
    zero_dbl = (double)zero / size;

    cout.precision(6);
    cout << fixed;
    cout << pos_dbl << endl <<
            neg_dbl << endl <<
            zero_dbl << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
