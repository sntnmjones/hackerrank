#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s)
{
    string hour = "", minute = "", second = "", ampm = "";
    unsigned int colon_counter = 0;

    /* Put time into appropriate containers. */
    for (auto letter : s)
    {
        if (letter == ':')
        {
            colon_counter++;
            continue;
        }

        switch (colon_counter)
        {
        case 0:
            hour += letter;
            break;
        case 1:
            minute += letter;
            break;
        case 2:
            second += letter;
            break;
        }
    }

    /* Get AM/PM off the second string. */
    for (int i = 2; i < second.size(); i++)
    {
        ampm += second[i];
    }
    for (int i = 0; i < 2; i++)
    {
        second.pop_back();
    }

    /* Take string of hours, and if needed convert to int and add 12. */
    if (ampm == "PM" && hour != "12")
    {
        unsigned int hr = stoi(hour);
        hr += 12;
        hour = to_string(hr);
    }

    /* If 12AM, change hour to 00. */
    if (hour == "12" && ampm == "AM")
    {
        hour = "00";
    }

    /* Format answer to return. */
    return hour + ":" + minute + ":" + second;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
