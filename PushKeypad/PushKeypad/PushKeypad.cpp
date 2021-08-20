#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int kp[4][3] = { 1,2,3,4,5,6,7,8,9,-1,0,-1 };
    int lefti = 3, leftj = 0;
    int righti = 3, rightj = 2;
    for (auto num : numbers)
    {
        int i, j;
        if (num == 0)
        {
            i = 3;
            j = 1;
        }
        else
        {
            i = (num - 1) / 3;
            j = (num + 2) % 3;
        }

        if (j == 0)
        {
            lefti = i;
            leftj = j;
            answer += 'L';
        }
        else if (j == 2)
        {
            righti = i;
            rightj = j;
            answer += 'R';
        }
        else
        {
            int ldist = abs(lefti - i);
            int rdist = abs(righti - i);
            if (leftj == j) rdist += abs(rightj - j);
            else if (rightj == j) ldist += abs(leftj - j);
            if (ldist > rdist || hand == "right" && ldist == rdist)
            {
                righti = i;
                rightj = j;
                answer += 'R';
            }
            else if (ldist < rdist || hand == "left" && ldist == rdist)
            {
                lefti = i;
                leftj = j;
                answer += 'L';
            }
        }
    }

    return answer;
}
int main()
{
    vector<int>numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";
    cout << solution(numbers, hand);
    return 0;
}