#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    if (number.length() == k + 1)
    {
        char max = 0;
        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] > max)
                max = number[i];
        }
        string s = "";
        s += max;
        return s;
    }
    char max = 0;
    int midx = 0;
    int len = number.length() - k;
    int limit = number.length() - len + 1;
    
    for (int i = 0; i < limit; i++)
    {
        if (number[i] > max)
        {
            max = number[i];
            midx = i;
        }
    }
    string answer = "";
    answer += max;
    max = 0;
    int range = midx + 1;
    while (1)
    {
        for (int i = range; i <= limit; i++)
        {
            if (number[i] > max)
            {
                max = number[i];
                midx = i;
            }
        }
        if (midx == limit)
        {
            answer += number.substr(limit, len);
            break;
        }
        else
        {
            answer += max;
            range = midx + 1;
            limit++;
            max = 0;
        }
        if (answer.length() == len) break;
    }

    return answer;
}
int main()
{
   cout<< solution("7777", 1);
}