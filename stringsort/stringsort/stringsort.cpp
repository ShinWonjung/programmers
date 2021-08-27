#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int i;
bool compare(string s1, string s2)
{
    if (s1[i] == s2[i])
        return s1 < s2;
    else
        return s1[i] < s2[i];
}
vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}