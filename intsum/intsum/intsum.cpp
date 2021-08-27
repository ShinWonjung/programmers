#include <string>
#include <vector>

using namespace std;

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
long long solution(int a, int b) {
    if (a == b) return a;
    if (a > b) Swap(a, b);
    long long answer = 0;
    for (int i = a; i <= b; i++)
        answer += i;
    return answer;
}