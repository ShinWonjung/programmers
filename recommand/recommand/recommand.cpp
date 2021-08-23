#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(pair<string, int>p1, pair<string, int>p2)
{
    if (p1.second != p2.second)
        return p1.second > p2.second;
    else return p1.first < p2.first;
}
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector<pair<string,int>> result;
    for (int i = 0; i < table.size(); i++)
    {
        vector<string> score;
        istringstream ss(table[i]);
        string stringBuffer;
        int size = languages.size();
        int r = 0;
        int gop = 6;
        while (getline(ss, stringBuffer, ' '))
        {
            score.push_back(stringBuffer);
            for (int i = 0; i < languages.size(); i++)
            {
                if (stringBuffer == languages[i])
                {
                    r += preference[i] * gop;
                    size--;
                    break;
                }
            }
            if (size == 0)break;
            gop--;
        }
        result.push_back(make_pair(score.front(), r));
    }
    sort(result.begin(), result.end(), compare);
    string answer = result.front().first;
    return answer;
}
int main()
{
    vector<string>t = { "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
        "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" };
    vector<string>l = { "JAVA", "JAVASCRIPT" };
    vector<int>p = { 7,5 };
    cout << solution(t, l, p);
    return 0;
}
