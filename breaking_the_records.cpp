// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> breakingRecords(vector<int> scores)
{
    unsigned int lowest_score = 0, 
            highest_score = 0, 
            lowest_broken = 0, 
            highest_broken = 0;
    bool first_time = true;

    for (auto score : scores)
    {

        if (first_time)
        {
            highest_score = score;
            lowest_score = score;
            first_time = false;
        }
        else
        {
            if (score > highest_score)
            {
                highest_score = score;
                highest_broken++;
            }
            if (score < lowest_score)
            {
                lowest_score = score;
                lowest_broken++;
            }
        }
    }

    vector<int> times_broken;

    times_broken.push_back(highest_broken);
    times_broken.push_back(lowest_broken);
    
    return times_broken;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(n);

    for (int i = 0; i < n; i++)
    {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);

    for (int i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
