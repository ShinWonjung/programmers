#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int>q;
    for (int i = 0; i < bridge_length; i++)
        q.push(0);
    int s = 0;
    while (!truck_weights.empty())
    {
        s -= q.front();
        q.pop();
        if (s + truck_weights.front() <= weight)
        {
            q.push(truck_weights.front());
            s += truck_weights.front();
            truck_weights.erase(truck_weights.begin());
        }
        else
            q.push(0);
        answer++;
    }
    while (!q.empty())
    {
        q.pop();
        answer++;
    }
    return answer;
}
int main()
{
    solution(2, 10, { 7,4,5,6 });
}