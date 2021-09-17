#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int max = 0;
    int midx = -1;
    for (int i = 0; i < land.size(); i++)
    {
        int prior = midx;
        max = 0;
        for (int j = 0; j < land[i].size(); j++)
        {
            if (j == prior) continue;
            if (land[i][j] > max)
            {
                max = land[i][j];
                midx = j;
            }
        }
        answer += max;
    }

    return answer;
}
int main() 
{
    cout<<solution({ {4,3,2,1},{2,2,2,1},{6,6,6,4},{8,7,6,5} });
}