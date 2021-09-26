#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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

int solution(string numbers) {
    int answer = 0;
    vector<char>vec;
    for (int i = 0; i < numbers.length(); i++)
        vec.push_back(numbers[i]);

    sort(vec.begin(), vec.end());
    
    vector<int>nums;
    do {
        string temp = "";
        for (int i = 0; i < vec.size(); i++)
        {
            temp += vec[i];
            nums.push_back(stoi(temp));
        }
    } while (next_permutation(vec.begin(), vec.end()));

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (isprime(nums[i]))
            answer++;
    }

    return answer;
}