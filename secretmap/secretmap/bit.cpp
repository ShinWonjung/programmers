#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++)
    {
        answer.push_back("");
        arr1[i] = arr1[i] | arr2[i];
        while (arr1[i] > 0)
        {
            if (arr1[i] % 2 == 0)answer[i] = ' ' + answer[i];
            else answer[i] = '#' + answer[i];
            arr1[i] /= 2;
        }
        while (answer[i].length() < n)
            answer[i] = ' ' + answer[i];
    }
    return answer;
}
int main()
{
    int n = 6;
    vector<int>arr1 = { 46, 33, 33 ,22, 31, 50 };
    vector<int>arr2 = { 27 ,56, 19, 14, 14, 10 };
    vector<string>s = solution(n, arr1, arr2);
    for (auto a : s)
        cout << a << '\n';
}