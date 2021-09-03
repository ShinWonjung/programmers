#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int n : scoville)
        pq.push(n);

    long long spicy = 0;
    while (pq.size() >= 2 && pq.top() < K)
    {
        spicy = pq.top();
        pq.pop();
        spicy += pq.top() * 2;
        pq.pop();
        pq.push(spicy);
        answer++;
    }
    if (pq.top() < K) return -1;
    else return answer;
}
int main()
{
    vector<int>v = { 1, 1, 2 };
    cout << solution(v, 3);
}