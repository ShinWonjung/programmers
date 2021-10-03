#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) { 
    vector<string> answer;
    vector<pair<string, string>>vname;
    vector<pair<string, bool>>active;
    
    for (auto s : record)
    {
        string id, name;
        if (s[0] == 'E' || s[0] == 'C')
        {
            int i = 4;
            while (1)
            {
                if (s[i] == ' ')break;
                i++;
            }
            i++;
            while (1)
            {
                if (s[i] == ' ')break;
                id += s[i];
                i++;
            }
            i++;
            while (i < s.length())
            {
                name += s[i];
                i++;
            }
        }
        else
        {
            for (int i = 6; i < s.length(); i++)
            {
                id += s[i];
            }
        }

        if (s[0] == 'E')
        {
            bool b = false;
            for (int i = 0; i < vname.size(); i++)
            {
                if (vname[i].first == id)
                {
                    vname[i].second = name;
                    b = true;
                    break;
                }
            }
            if (b == false)
                vname.push_back(make_pair(id, name));
            active.push_back(make_pair(id, 1));
        }
        else if (s[0] == 'L')
            active.push_back(make_pair(id, 0));
        else
        {
            for (int i = 0; i < vname.size(); i++)
            {
                if (vname[i].first == id)
                {
                    vname[i].second = name;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < active.size(); i++)
    {
        if (active[i].second == 1)
        {
            for (int j = 0; j < vname.size(); j++)
            {
                if (vname[j].first == active[i].first)
                {
                    answer.push_back(vname[j].second);
                    break;
                }
            }
            answer[i] += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else
        {
            for (int j = 0; j < vname.size(); j++)
            {
                if (vname[j].first == active[i].first)
                {
                    answer.push_back(vname[j].second);
                    break;
                }
            }
            answer[i] += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
    }

    return answer;
}
int main()
{
    
    vector<string>s = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    vector<string>answer = solution(s);
    for (auto s : answer)
        cout << s << '\n';
    return 0;
}