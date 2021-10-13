#include<string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char>st;
    for (auto a : s)
    {
        if (a == '(')
            st.push('(');
        else
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
    }
    if (!st.empty())
        return false;
    else
        return true;
}