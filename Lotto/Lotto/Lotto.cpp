#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int find(vector<int>v, int num, int left, int right)
{
    int mid;
    while (1)
    {
        mid = (left + right) / 2;
        if (v[mid] == num)
            return mid;
        if (left >= right)
            return -1;
        if (v[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    for (int i = 0; i < 6; i++)
    {
        if (lottos[i] == 0)continue;
        int f = find(win_nums, lottos[i], 0, win_nums.size() - 1);
        if (f != -1)
        {
            win_nums.erase(win_nums.begin() + f);
            lottos[i] = 1;
        }
        else
            lottos[i] = -1;
    }

    vector<int> answer = { 0,0 };
    for (int i = 0; i < 6; i++)
    {
        if (lottos[i] == 1)
        {
            answer[0]++;
            answer[1]++;
        }
        else if (lottos[i] == 0)
            answer[0]++;
    }
    for (int i = 0; i < 2; i++)
    {
        switch (answer[i])
        {
        case 6:
            answer[i] = 1;
            break;
        case 5:
            answer[i] = 2;
            break;
        case 4:
            answer[i] = 3;
            break;
        case 3:
            answer[i] = 4;
            break;
        case 2:
            answer[i] = 5;
            break;
        default:
            answer[i] = 6;
            break;
        }
    }
    
    return answer;
}
int main()
{
    vector<int>l = { 44, 1, 0, 0, 31, 25 };
    vector<int>w = { 31, 10, 45, 1, 6, 19 };
    vector<int>a = solution(l , w);
    cout << a[0] << ' ' << a[1];
    return 0;
}