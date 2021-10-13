#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            answer += " ";
        else
        {
            answer += toupper(s[i]);
            i++;
            while (s[i] != ' ' && i < s.length())
            {
                answer += tolower(s[i]);
                i++;
            }
            if (i == s.length() - 1)
            {
                if (s[i] == ' ')
                    answer += ' ';
                break;
            }
            i--;
        }
    }
    return answer;
}