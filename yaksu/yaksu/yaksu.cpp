#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        if (fmod(sqrt(i), 1) == 0)
            answer -= i;
        else
            answer += i;

    }
    return answer;
}
int main()
{
    cout << solution(13, 17);
    return 0;
}