#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int solution(string dartResult) {
    int arr[3] = { 0, };
    int idx = 0;
    for (int i = 0; i < 3; i++)
    {
        arr[i] = dartResult[idx] - '0';
        if (dartResult[idx] == '1' && dartResult[idx + 1] == '0')
        {
            arr[i] = 10;
            idx++;
        }
        idx++;
        while (idx!=dartResult.size() && !(dartResult[idx] >= '0' && dartResult[idx] <= '9'))
        {
            if (dartResult[idx] == 'S')
            {
                idx++;
                continue;
            }
            else if (dartResult[idx] == 'D')
                arr[i] = pow(arr[i], 2);
            else if (dartResult[idx] == 'T')
                arr[i] = pow(arr[i], 3);
            else if (dartResult[idx] == '*')
            {
                if (i == 0)
                    arr[i] *= 2;
                else
                {
                    arr[i] *= 2;
                    arr[i - 1] *= 2;
                }
            }
            else if (dartResult[idx] == '#')
                arr[i] *= -1;

            idx++;
        }
    }
    int answer = arr[0] + arr[1] + arr[2];
    return answer;
}
int main()
{
    cout << solution("1D2S#10S");
}