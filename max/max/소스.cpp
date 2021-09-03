#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2)
{
    if (s1 + s2 < s2 + s1)
        return true;
    else
        return false;
}
bool compare(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                return s1[i] < s2[i];
        }
        return s1 < s2;
    }
    else if (s1.length() < s2.length())
    {
        int i;
        for (i = 0; i < s1.length() - 1; i++)
        {
            if (s1[i] != s2[i])
                return s1[i] < s2[i];
        }
        for (int j = i; j < s2.length(); j++)
        {
            if (s1[i] != s2[j])
                return s1[i] < s2[j];
        }
        return s1 < s2;
    }
    else
    {
        int i;
        for (i = 0; i < s2.length() - 1; i++)
        {
            if (s1[i] != s2[i])
                return s1[i] < s2[i];
        }
        for (int j = i; j < s1.length(); j++)
        {
            if (s1[j] != s2[i])
                return s1[j] < s2[i];
        }
        return s1 < s2;
    }
}

string solution(vector<int> numbers) {
    vector<string>vec;
    for (int i = 0; i < numbers.size(); i++)
        vec.push_back(to_string(numbers[i]));

    sort(vec.begin(), vec.end(), comp);
    string answer = "";
    while (!vec.empty() && vec.back() == "0")
        vec.pop_back();
    if (vec.empty()) return "0";
    for (int i = 0; i < vec.size(); i++)
        answer = vec[i] + answer;
    return answer;
}

int main()
{
    vector<int>v = { 412,41 };
    solution(v);
}