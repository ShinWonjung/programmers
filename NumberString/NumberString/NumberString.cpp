#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int>v;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            v.push_back(s[i] - '0');
        else
        {
            switch (s[i])
            {
            case 'z':
                v.push_back(0);
                i += 3;
                break;
            case 'o':
                v.push_back(1);
                i += 2;
                break;
            case 't':
                if (s[i + 1] == 'w')
                {
                    v.push_back(2);
                    i += 2;
                }
                else
                {
                    v.push_back(3);
                    i += 4;
                }
                break;
            case 'f':
                if (s[i + 1] == 'o')
                    v.push_back(4);
                else
                    v.push_back(5);
                i += 3;
                break;
            case 's':
                if (s[i + 1] == 'i')
                {
                    v.push_back(6);
                    i += 2;
                }
                else
                {
                    v.push_back(7);
                    i += 4;
                }
                break;
            case 'e':
                v.push_back(8);
                i += 4;
                break;
            case 'n':
                v.push_back(9);
                i += 3;
                break;
            }
        }
    }
    int gop = 1;
    while (!v.empty())
    {
        answer += v.back() * gop;
        gop *= 10;
        v.pop_back();
    }

    return answer;
}
int main()
{
    string s;
    cin >> s;
    cout << solution(s);
    return 0;
}