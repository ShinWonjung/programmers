#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    bool answer = true;
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i].length() < phone_book[i + 1].length())
        {
            for (int j = 0; j < phone_book[i].length(); j++)
            {
                if (phone_book[i][j] != phone_book[i + 1][j])
                {
                    answer = true;
                    break;
                }
                else answer = false;
            }
            if (answer == false)
                return answer;
        }
    }
    return answer;
}
int main()
{
    vector<string>v;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    cout << solution(v);
    return 0;
}