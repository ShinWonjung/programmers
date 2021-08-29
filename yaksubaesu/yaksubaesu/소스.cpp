#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int& min = n < m ? n : m;

    for (int i = min; i < 0; i--)
    {
        if (n % i == 0 && m % i == 0)
        {
            answer.push_back(i);
            n /= i;
            m /= i;
            answer.push_back(i * n * m);
            return answer;
        }
    }
}

int main()
{
    vector<int>v = solution(3, 12);
    return 0;
}