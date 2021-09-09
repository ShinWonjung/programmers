#include <string>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;
vector<pair<string, char>> priority{ {"*",' '},{"+",' '},{"-",' '} };
vector<string> pr{ "012","021","102","120","201","210" };

vector<string> postfix(vector<string> vec)
{
    vector<string>v;
    stack<pair<string, char>>s;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == "*")
        {
            if (s.empty()) s.push(make_pair(vec[i], priority[0].second));
            else if (s.top().second >= priority[0].second)
            {
                while (!s.empty() && s.top().second >= priority[0].second)
                {
                    v.push_back(s.top().first);
                    s.pop();
                }
                s.push(make_pair(vec[i], priority[0].second));
            }
            else
                s.push(make_pair(vec[i], priority[0].second));
        }
        else if (vec[i] == "+")
        {
            if (s.empty()) s.push(make_pair(vec[i], priority[1].second));
            else if (s.top().second >= priority[1].second)
            {
                while (!s.empty() && s.top().second >= priority[1].second)
                {
                    v.push_back(s.top().first);
                    s.pop();
                }
                s.push(make_pair(vec[i], priority[1].second));
            }
            else
                s.push(make_pair(vec[i], priority[1].second));
        }
        else if (vec[i] == "-")
        {
            if (s.empty()) s.push(make_pair(vec[i], priority[2].second));
            else if (s.top().second >= priority[2].second)
            {
                while (!s.empty() && s.top().second >= priority[2].second)
                {
                    v.push_back(s.top().first);
                    s.pop();
                }
                s.push(make_pair(vec[i], priority[2].second));
            }
            else
                s.push(make_pair(vec[i], priority[2].second));
        }
        else
            v.push_back(vec[i]);
    }
    while (!s.empty())
    {
        v.push_back(s.top().first);
        s.pop();
    }
    return v;
}
long long solve(vector<string> vec)
{
    long long answer = 0;
    stack<long long>s;
    for (int i = 0; i < vec.size(); i++)
    {
        if (isdigit(vec[i][0]))
            s.push(stoi(vec[i]));
        else
        {
            answer = s.top();
            s.pop();
            if (vec[i] == "*") answer = s.top() * answer;
            else if (vec[i] == "+") answer = s.top() + answer;
            else if (vec[i] == "-") answer = s.top() - answer;
            s.pop();
            s.push(answer);
        }
    }
    return s.top();
}
long long solution(string expression) {
    vector<string> vec;
    string s = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
            s += expression[i];
        else
        {
            vec.push_back(s);
            s = expression[i];
            vec.push_back(s);
            s = "";
        }
    }
    vec.push_back(s);
    long long answer = 0;
    long long max = 0;
    
    for (int i = 0; i < pr.size(); i++)
    {
        priority[0].second = pr[i][0];
        priority[1].second = pr[i][1];
        priority[2].second = pr[i][2];
        vector<string>temp = postfix(vec);
        answer = abs(solve(temp));
        if (max < answer) max = answer;
    }

    return max;
}