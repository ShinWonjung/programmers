#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    char max = '0';
    int midx = 0;
    int len = number.length() - k;
    int range = number.length() - len + 1;
    
    for (int i = 0; i < range; i++)
    {
        if (number[i] > max)
        {
            max = number[i];
            midx = i;
        }
    }
    string answer = "";
    answer += max;
    range = midx + 1;
    
    int idx = number.length() - len + 1;
    while (1)
    {
        if (number[range] > number[idx])
        {
            answer += number[range];
            range++;
            idx++;
        }
        else
            range++;
        if (range == idx) break;
        if (idx == number.length() - 1) break;
    }
    if (answer.length() < len)
        answer += number.substr(idx, len);
    return answer;
}
int main()
{
   cout<< solution("321924", 2);
}