#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
    int i;
    for (i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
            return "�輭���� " + to_string(i) + "�� �ִ�";
    }
}

int main()
{
    cout << solution({ "ssd","Kim" });
}