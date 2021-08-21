#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    for (int j = 0; j < scores[0].size(); j++)
    {
        vector<int>v;
        double result = 0;
        bool b = true;
        for (int i = 0; i < scores.size(); i++)
        {
            if (i != j && scores[j][j] == scores[i][j]) b = false;
            v.push_back(scores[i][j]);
            result += scores[i][j];
        }
        if (b == true)
        {
            int su = v[j];
            sort(v.begin(), v.end());
            if (su == v[0] || su == v[v.size() - 1])
            {
                result -= su;
                result /= v.size() - 1;
            }
            else
                result /= v.size();
        }
        else
            result /= v.size();

        if (result >= 90)
            answer += 'A';
        else if (result >= 80)
            answer += 'B';
        else if (result >= 70)
            answer += 'C';
        else if (result >= 50)
            answer += 'D';
        else
            answer += 'F';
    }
        return answer;
}
int main()
{
    vector<vector<int>> scores = { {70, 49, 90},{68, 50, 38},{73, 31, 100} };
    cout << solution(scores);
    return 0;
}