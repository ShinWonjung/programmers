#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    for (int i = 0; i < people.size(); i++)
    {
        if (people[i] + people.back() <= limit)
            people.pop_back();
        else
        {
            people.pop_back();
            i--;
        }
        answer++;
    }
    return answer;
}
int main()
{
    solution({ 70, 50, 80, 50 }, 100);
}