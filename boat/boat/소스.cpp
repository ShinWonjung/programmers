#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    for (int i = 0; i < people.size(); i++)
    {
        int num = people[i];
        int su = 0;
        int cur = 0;
        bool b = false;
        for (int j = i + 1; j < people.size(); j++)
        {
            if (num + people[j] <= limit)
            {
                if (num + su < num + people[j])
                {
                    su = people[j];
                    cur = j;
                    b = true;
                }
            }
            if (num + people[j] == limit)
                break;
        }
        if (b) people.erase(people.begin() + cur);
        answer++;
    }
    return answer;
}
int main()
{
    solution({ 70, 50, 80, 50 }, 100);
}