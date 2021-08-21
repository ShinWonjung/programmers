#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int>map;
    for (auto num : nums)
    {
        map.insert(make_pair(num, 1));
    }

    return nums.size() / 2 <= map.size() ? nums.size() / 2 : map.size();
}
int main()
{
    vector<int>v = { 1,3,2,3 };
    cout << solution(v);
    return 0;
}