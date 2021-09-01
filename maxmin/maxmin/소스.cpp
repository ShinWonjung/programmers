#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    stringstream ss(s);
    vector<int>v;
    string stringBuffer;

    while (getline(ss, stringBuffer, ' '))
    {
        v.push_back(stoi(stringBuffer));
    }
    sort(v.begin(), v.end());
    string answer = to_string(v.front()) + ' ' + to_string(v.back());
    return answer;
}