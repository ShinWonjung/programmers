#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int>map;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        map[c] = 0;
    }
    for (int i = 0; i < skill.length(); i++)
    {
        map[skill[i]] = i + 1;
    }
    for (int i = 0; i < skill_trees.size(); i++)
    {
        int cnt = 0;
        bool flag = true;
        for (int j = 0; j < skill_trees[i].length(); j++)
        {
            if (map[skill_trees[i][j]] == cnt + 1)
                cnt++;
            else if (map[skill_trees[i][j]] > cnt)
            {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    return answer;
}
int main()
{
    solution("CBD", { "CAD" });
}