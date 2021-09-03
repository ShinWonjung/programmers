#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int>q;
    for (int i = 0; i < progresses.size(); i++)
    {
        int n = 100 - progresses[i];
        if (n % speeds[i] == 0)
            q.push(n / speeds[i]);
        else
            q.push(n / speeds[i] + 1);
    }
    vector<int> answer;
    int first = q.front();
    answer.push_back(1);
    q.pop();
    while (!q.empty())
    {
        if (first >= q.front())
        {
            answer.back()++;
            q.pop();
        }
        else
        {
            first = q.front();
            answer.push_back(1);
            q.pop();
        }
    }
    return answer;
}
int main()
{
    vector<int>v1 = { 93,30,55 };
    vector<int>v2 = { 1,30,5 };
    solution(v1, v2);
}