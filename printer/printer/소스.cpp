#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int, int>>dq;
    for (int i = 0; i < priorities.size(); i++)
        dq.push_back(make_pair(priorities[i], i));
    vector<pair<int, int>>result;

    while (dq.size() != 1)
    {
        auto cur = dq.front();
        int pri = cur.first;
        for (int i = 1; i < dq.size(); i++)
        {
            if (pri < dq[i].first)
            {
                for (int j = 0; j < i; j++)
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
                break;
            }
            if (i == dq.size() - 1)
            {
                result.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    result.push_back(dq.front());
    int i;
    for (i = 0; i < result.size(); i++)
    {
        if (result[i].second == location)
            return i + 1;
    }
}

int main()
{
    vector<int>v = { 2,1,3,2 };
    solution(v, 2);
}