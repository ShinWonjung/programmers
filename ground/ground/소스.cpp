#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for (int i = 1; i < land.size(); i++)
    {
        land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
        land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
        land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
        land[i][3] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
    }
    answer = max(land.back()[0], max(land.back()[1], max(land.back()[2], land.back()[3])));
    return answer;
}