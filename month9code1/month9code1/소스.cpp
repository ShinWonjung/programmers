#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int answer = 0;
    queue<int>q;
    int i;
    for (i = 0; i < numbers.size(); i++)
    {
        q.push(numbers[i]);
    }
    i = 0;
    while (!q.empty())
    {
        if (i == q.front())
            q.pop();
        else
            answer += i;
        i++;
    }
    for (; i < 10; i++)
        answer += i;
    return answer;
}
int main()
{
    cout << solution({ 1,2,3,4,6,7,8,0 });
}