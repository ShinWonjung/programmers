#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.length(); i++)
    {
        int cnt = 0;
        string new_s = "";
        string str = s.substr(0, i);
        string temp;
        for (int j = i; j < s.length(); j += i)
        {
            temp = s.substr(j, i);
            if (str == temp)
            {
                cnt++;
            }
            else
            {
                if (cnt) new_s += to_string(++cnt);
                new_s += str;
                cnt = 0;
                str = temp;
            }
        }
        if (cnt) new_s += to_string(++cnt);
        new_s += str;
        cnt = 0;
        str = temp;

        if (new_s.length() < answer)
            answer = new_s.length();
    }
    return answer;
}
int main()
{
    solution("aabbaccc");
}