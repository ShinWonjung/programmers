#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            answer += new_id[i] - 'A' + 'a';
        else if (new_id[i] >= 'a' && new_id[i] <= 'z')
            answer += new_id[i];
        else if (new_id[i] == '.')
            answer += new_id[i];
        else if (new_id[i] == '-' || new_id[i] == '_')
            answer += new_id[i];
        else if (new_id[i] >= '0' && new_id[i] <= '9')
            answer += new_id[i];
    }

    string a = answer;
    answer = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
        {
            while (a[i + 1] == '.')
            {
                i++;
                continue;
            }
            answer += a[i];
        }
        else
            answer += a[i];
    }

    if (answer[0] == '.')
        answer.erase(0, 1);
    if (!answer.empty() && answer.back() == '.')
        answer.pop_back();

    if (answer == "")
        answer = "a";

    while (answer.length() > 15)
    {
        answer.pop_back();
    }

    if (!answer.empty() && answer.back() == '.')
        answer.pop_back();

    while (answer.length() < 3)
    {
        answer += answer.back();
    }

    return answer;
}
int main()
{
    string s = "=.=";
    cout<<solution(s);
    return 0;
}