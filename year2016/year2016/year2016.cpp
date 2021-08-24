#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    int n = 0;
    for (int i = 1; i < a; i++)
    {
        n += month[i];
    }
    n += b;
    n %= 7;
    vector<string>day = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
    answer = day[n];
    return answer;
}
int main()
{
    cout << solution(5, 24);
}