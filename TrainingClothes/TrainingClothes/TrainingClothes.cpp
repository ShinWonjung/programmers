#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int>::iterator iter;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (iter = lost.begin(); iter != lost.end(); iter++)
    {
        auto ridx = find(reserve.begin(), reserve.end(), *iter);
        if (ridx != reserve.end())
        {
            *iter = 0;
            reserve[ridx - reserve.begin()] = 0;
        }
    }
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    while (!lost.empty() && lost.front() == 0)lost.erase(lost.begin());
    while (!reserve.empty() && reserve.front() == 0)reserve.erase(reserve.begin());
    //진짜 체육복이 없고 두 개인 학생 걸러냄

    if (lost.empty())return n;
    int answer = n - lost.size();
    for (iter = lost.begin(); iter != lost.end(); iter++)
    {
        int ridx = 0;
        while (ridx < reserve.size() && *iter + 1 >= reserve[ridx])
        {
            if (*iter + 1 == reserve[ridx] || *iter - 1 == reserve[ridx])
            {
                answer++;
                reserve.erase(reserve.begin() + ridx);
                break;
            }
            ridx++;
        }
    }



    /*for (auto elem : lost)cout << elem;
    cout << '\n';
    for (auto elem : reserve)cout << elem;
    cout << answer;*/
    return answer;
}
int main()
{
    vector<int>lost = { 5,4,3,2,1 };
    vector<int>reserve = { 3,1,5,2,4 };
    cout<<"\n\n"<<solution(10, lost, reserve);
    return 0;
}