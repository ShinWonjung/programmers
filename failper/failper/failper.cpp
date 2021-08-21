#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(pair<int, double>v1, pair<int, double>v2)
{
    return v1.second > v2.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>>v;
    sort(stages.begin(), stages.end());
    int num = 1;
    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] != num)
        {
            v.push_back(make_pair(num, 0));
            num++;
        }
        else
        {
            int player = stages.size() - i;
            double fail = 1;
            while (stages[i + 1] == num && i < stages.size() - 1)
            {
                fail++;
                i++;
            }
            
            v.push_back(make_pair(num, fail / player));
            num++;
        }
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
        answer.push_back(v[i].first);

    return answer;
}
int main()
{
    int N = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    stages = solution(N, stages);
    for (auto a : stages)
        cout << a << ' ';
    return 0;
}