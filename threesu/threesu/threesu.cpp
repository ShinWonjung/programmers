#include <string>
#include <cmath>
#include <iostream>

using namespace std;

string three(int n)
{
    string result = "";
    while (n >= 3)
    {
        result += (n % 3) + '0';
        n /= 3;
    }
    result += n + '0';
    while (result.front() == '0')
        result.erase(result.begin());
    return result;
}
int ten(string s)
{
    int result = 0;
    int i = 0;
    while (!s.empty())
    {
        result += (s.back() - '0') * pow(3, i);
        s.pop_back();
        i++;
    }
    return result;
}
int solution(int n) {
    int answer = ten(three(n));
    return answer;
}
int main()
{
    cout << solution(45);
    return 0;
}