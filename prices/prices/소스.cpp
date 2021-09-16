#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<pair<int, int>> result;
    stack<pair<int, int>> stack;
    stack.push(make_pair(prices[0], 0));
    for (int i = 1; i < prices.size(); i++)
    {
        if ((!stack.empty() && stack.top().first <= prices[i]) || stack.empty())
        {
            stack.push(make_pair(prices[i], i));
            continue;
        }
        while (!stack.empty() && stack.top().first > prices[i])
        {
            result.push_back(make_pair(stack.top().second, i - stack.top().second));
            stack.pop();
        }
        stack.push(make_pair(prices[i], i));
    }
    int siz = prices.size() - 1;
    while (!stack.empty())
    {
        result.push_back(make_pair(stack.top().second, siz - stack.top().second));
        stack.pop();
    }
    sort(result.begin(), result.end());
    for (auto i : result)
        answer.push_back(i.second);
    return answer;
}