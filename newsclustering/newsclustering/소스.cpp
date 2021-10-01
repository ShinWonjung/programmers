#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str1.length(); i++)
        if (str1[i] >= 'a' && str1[i] <= 'z')
            str1[i] -= 32;

    for (int i = 0; i < str2.length(); i++)
        if (str2[i] >= 'a' && str2[i] <= 'z')
            str2[i] -= 32;

    vector<string>vec1;
    vector<string>vec2;
    for (int i = 0; i < str1.length() - 1; i++)
    {
        if (str1[i] >= 'A' && str1[i] <= 'Z' && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
        {
            string s = ""; s += str1[i]; s += str1[i + 1];
            vec1.push_back(s);
        }
    }
    for (int i = 0; i < str2.length() - 1; i++)
    {
        if (str2[i] >= 'A' && str2[i] <= 'Z' && str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
        {
            string s = ""; s += str2[i]; s += str2[i + 1];
            vec2.push_back(s);
        }
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    if (vec1.empty() && vec2.empty())
    {
        return 65536;
    }
    else if (vec1.empty())
    {
        double su = 0.0 / vec2.size();
        su *= 65536;
        answer = su;
        return answer;
    }
    else if (vec2.empty())
    {
        double su = 0.0 / vec1.size();
        su *= 65536;
        answer = su;
        return answer;
    }

    vector<pair<string, int>>p1;
    p1.push_back(make_pair(vec1[0], 1));
    for (int i = 1; i < vec1.size(); i++)
    {
        if (vec1[i] == p1.back().first)
            p1.back().second++;
        else
            p1.push_back(make_pair(vec1[i], 1));
    }
    p1.push_back(make_pair(vec2[0], 1));
    for (int i = 1; i < vec2.size(); i++)
    {
        if (vec2[i] == p1.back().first)
            p1.back().second++;
        else
            p1.push_back(make_pair(vec2[i], 1));
    }
    sort(p1.begin(), p1.end());
    p1.push_back(make_pair("", 0));

    int gyu = 0;
    int hap = 0;

    for (int i = 0; i < p1.size() - 1; i++)
    {
        if (p1[i].first == p1[i + 1].first)
        {
            gyu += p1[i].second < p1[i + 1].second ? p1[i].second : p1[i + 1].second;
            hap += p1[i].second > p1[i + 1].second ? p1[i].second : p1[i + 1].second;
            i++;
        }
        else
        {
            hap += p1[i].second;
        }
    }

    double su = (double)gyu / hap;
    su *= 65536;
    answer = su;

    return answer;
}
int main()
{
    solution("E=M*C^2", "e=m*c^2");
}