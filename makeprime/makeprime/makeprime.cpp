#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++)
        for (int j = i + 1; j < nums.size() - 1; j++)
            for (int g = j + 1; g < nums.size(); g++)
                if (isprime(nums[i] + nums[j] + nums[g]))
                    answer++;

    return answer;
}

int main()
{
    vector<int>v = { 1,2,3,4 };
    cout << solution(v);
    return 0;
}