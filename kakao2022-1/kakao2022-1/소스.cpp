#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

bool compSec(pair<string, string> p1, pair<string, string> p2)
{
    return p1.second < p2.second;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector < pair<string, string>>_report(report.size(), make_pair("", ""));

    for (int i = 0; i < report.size(); i++)
    {
        int idx = 0;
        while (report[i][idx] != ' ')
        {
            _report[i].first += report[i][idx];
            idx++;
        }
        while (idx < report[i].length())
        {
            _report[i].second += report[i][idx];
            idx++;
        }
    }
    sort(_report.begin(), _report.end());
    _report.erase(unique(_report.begin(), _report.end()), _report.end());

    sort(_report.begin(), _report.end(), compSec);

    unordered_map<string, int>map;
    for (int i = 0; i < id_list.size(); i++)
        map.insert({ id_list[i], 0 });
    int cnt = 1;
    string s = _report.front().second;
    for (int i = 1; i < _report.size(); i++)
    {
        if (_report[i].second == s)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            s = _report[i].second;
        }
        if (cnt >= k && i + 1 < _report.size() && _report[i + 1].second != s)
        {
            for (int j = i - cnt + 1; j <= i; j++)
                map[_report[j].first]++;
        }
        else if (cnt >= k && i == _report.size() - 1)
        {
            for (int j = i - cnt + 1; j <= i; j++)
                map[_report[j].first]++;
        }
    }
    for (auto it = map.begin(); it != map.end(); it++)
        answer.push_back(it->second);
    return answer;
}
int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    int k = 2;
    vector<int>c  = solution(id_list, report, k);
    for (auto c : c)
        cout << c << ' ';
}