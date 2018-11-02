// https://www.hackerrank.com/challenges/grading/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the gradingStudents function below.
 */
vector<int> gradingStudents(vector<int> grades)
{
    vector<int> new_grades = grades;

    for (unsigned int i = 0; i < new_grades.size(); i++)
    {
        if (new_grades[i] > 37)
        {
            if ((new_grades[i] % 5) >= 3)
            {

                new_grades[i] += (5 - (new_grades[i] % 5));
            }
        }
    }

    return new_grades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> grades(n);

    for (int grades_itr = 0; grades_itr < n; grades_itr++)
    {
        int grades_item;
        cin >> grades_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        grades[grades_itr] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int result_itr = 0; result_itr < result.size(); result_itr++)
    {
        fout << result[result_itr];

        if (result_itr != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
