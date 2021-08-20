#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int>idx;
    for (int i = 0; i < board[0].size(); i++)
    {
        idx.push_back(0);
        int index = 0;
        while (1)
        {
            if (board[index][i] != 0)break;
            idx[i]++;
            index++;
            if (index == board.size())break;
        }
    }

    int answer = 0;
    stack<int>stack;
    for (auto num : moves)
    {
        if (idx[num - 1] == board.size())continue;

        if (!stack.empty() && stack.top() == board[idx[num - 1]][num - 1])
        {
            stack.pop();
            answer += 2;
        }
        else
            stack.push(board[idx[num - 1]][num - 1]);

        board[idx[num - 1]][num - 1] = 0;
        idx[num - 1]++;
    }

    return answer;
}
int main()
{
    vector<vector<int>>board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int>moves = { 1,5,3,5,1,2,1,4 };
    cout << solution(board, moves);
    return 0;
}