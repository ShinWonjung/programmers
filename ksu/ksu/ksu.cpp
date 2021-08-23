#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        priority_queue<int,vector<int>,greater<int>>q;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
            q.push(array[j]);
        for (int j = 1; j < commands[i][2]; j++)
            q.pop();
        answer.push_back(q.top());
    }
    return answer;
}
int main()
{
    vector<int>a = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>>b = { {2, 5, 3},{4, 4, 1 }, {1, 7, 3} };
    solution(a, b);
}