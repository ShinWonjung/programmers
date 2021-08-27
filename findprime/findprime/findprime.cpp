#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n) {
    vector<int>arr(n + 1, 0);
    int answer = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i] == 1)
            continue;
        for (int j = 2; i * j <= n; j++)
        {
            if (arr[i * j] == 1) continue;
            arr[i * j] = 1;
            answer++;
        }
    }
    answer = n - 1 - answer;
    return answer;
}
int main()
{
    cout << solution(10);
}