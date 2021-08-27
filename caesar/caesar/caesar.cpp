#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[i] + n > 'Z')
                s[i] = 'A' + (s[i] + n - 'Z') - 1;
            else
                s[i] += n;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[i] + n > 'z')
                s[i] = 'a' + (s[i] + n - 'z') - 1;
            else
                s[i] += n;
        }
    }
    return s;
}