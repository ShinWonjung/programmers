#include <iostream>

using namespace std;
void temp(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int solution(int n, int a, int b)
{
    if (a > b) temp(a, b);
    int answer = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (a % 2 == 1 && b % 2 == 0 && b - a == 1) break;
        if (a % 2 == 1) a++;
        if (b % 2 == 1) b++;
        a /= 2;
        b /= 2;
        answer++;
    }
    return answer;
}