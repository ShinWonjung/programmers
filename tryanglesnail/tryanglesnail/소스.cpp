#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n] {0, };

    int num = 1;
    int cnt = n;
    int row = 0;
    int col = 0;
    for (int i = 0;; i++)
    {
        col = i;
        for (int j = 0; j < cnt; j++)
        {
            arr[row++][col] = num++;
        }
        cnt--;
        if (cnt == 0) break;
        row--;
        for (int j = 0; j < cnt; j++)
        {
            arr[row][++col] = num++;
        }
        cnt--;
        if (cnt == 0) break;
        for (int j = 0; j < cnt; j++)
        {
            arr[--row][col] = num++;
        }
        cnt--;
        if (cnt == 0) break;
        row++;
    }

    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j])
                answer.push_back(arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        delete arr[i];
    delete arr;
    return answer;
}
int main()
{
    solution(4);
}