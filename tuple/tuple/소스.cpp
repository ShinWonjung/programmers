#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool comp(pair<int, int>p1, pair<int, int>p2)
{
    return p1.second > p2.second;
}

vector<int> solution(string s) {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '}')
        {
            s.erase(i, 1);
            i--;
        }
    }

    istringstream ss(s);
    vector<pair<int, int>>tuples(10000, make_pair(0, 0));
    string stringBuffer;
    while (getline(ss, stringBuffer, ','))
    {
        if (tuples[stoi(stringBuffer)].first == 0)
            tuples[stoi(stringBuffer)].first = stoi(stringBuffer);
        tuples[stoi(stringBuffer)].second++;
    }
    sort(tuples.begin(), tuples.end(), comp);
    vector<int> answer;
    for (int i = 0; tuples[i].second != 0; i++)
        answer.push_back(tuples[i].first);
    return answer;
}
int main()
{
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}