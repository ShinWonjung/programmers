#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    int i = 0;
    for(int n : numbers)
    {
       while (n != i)
       {
           answer += i;
           i++;
       }
        i++;
    }
    return answer;
}
int main(void)
{
    vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 0};
    int a = solution(numbers);
    cout << a;
    return 0;
}
