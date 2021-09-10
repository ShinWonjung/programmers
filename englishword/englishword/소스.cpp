#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> p1, pair<string, int>p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);

    vector<pair<string, int>>sorted;
    for (int i = 0; i < words.size(); i++)
    {
        sorted.push_back(make_pair(words[i], i));
    }
    sort(sorted.begin(), sorted.end());

    int min = 101;
    for (int i = 1; i < sorted.size(); i++)
    {
        if (sorted[i].first == sorted[i - 1].first)
        {
            if (sorted[i].second < min)
                min = sorted[i].second;
        }
    }

    for (int i = 1; i < words.size(); i++)
    {
        if (words[i - 1].back() != words[i].front())
        {
            if (min > i) min = i;
            break;
        }
    }
    if (min != 101)
    {
        answer[0] = min % n + 1;
        answer[1] = min / n + 1;
    }

    return answer;
}
int main()
{
    solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });
}