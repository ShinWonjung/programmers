#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> pluspostfix(vector<string> vec)
{
    vector<string>v;
    stack<string>s;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == "*") s.push(vec[i]);
        if (vec[i] == "+")
        {
            if (s.empty()) s.push(vec[i]);
            else if (s.top() != "-")
            {
                while (!s.empty()) 
                {
                    v.push_back(s.top());
                    s.pop();
                }
                s.push(vec[i]);
            }
        }
        if (vec[i] == "-")
        {
            while (!s.empty())
            {
                v.push_back(s.top());
                s.pop();
            }
            s.push(vec[i]);
        }
    }
}

long long solution(string expression) {
    int plus = 0;
    int minus = 0;
    vector<string> vec;
    string s = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
            s += expression[i];
        else
        {
            if (expression[i] == '+') plus++;
            else if (expression[i] == '-') minus++;
            vec.push_back(s);
            i++;
            s = expression[i];
            vec.push_back(s);
            s = "";
        }
    }
    long long answer = 0;
    return answer;
}