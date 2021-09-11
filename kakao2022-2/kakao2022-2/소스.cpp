#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    string s = "";
    while (n >= k)
    {
        s = to_string(n % k) + s;
        n /= k;
    }
    s = to_string(n) + s;

    vector<long long>v;
    string num = "";
    long long max = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0')
            num += s[i];
        else if (!num.empty())
        {
            v.push_back(stol(num));
            if (stol(num) > max) max = stol(num);
            num = "";
        }
    }
    if (!num.empty())
    {
        v.push_back(stol(num));
        if (stol(num) > max) max = stol(num);
    }

    int answer = 0;
    for (int i = 0; i < v.size(); i++)
    {
        bool b = true;
        if (v[i] < 2) continue;
        for (int j = 2; j <= sqrt(v[i]); j++)
        {
            if (v[i] % j == 0)
            {
                b = false;
                break;
            }
        }
        if (b) answer++;
    }

    return answer;
}