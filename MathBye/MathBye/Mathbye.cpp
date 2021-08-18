#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int>v1 = { 1,2,3,4,5 };
    vector<int>v2 = { 2,1,2,3,2,4,2,5 };
    vector<int>v3 = { 3,3,1,1,2,2,4,4,5,5 };
    int v1_ = 0, v2_ = 0, v3_ = 0;
    for (int i = 1; i <= answers.size(); i++)
    {
        int num = i % v1.size() - 1;
        if (num == -1) num = v1.size() - 1;
        if (v1[num] == answers[i - 1]) v1_++;
        num = i % v2.size() - 1;
        if (num == -1) num = v2.size() - 1;
        if (v2[num] == answers[i - 1]) v2_++;
        num = i % v3.size() - 1;
        if (num == -1) num = v3.size() - 1;
        if (v3[num] == answers[i - 1]) v3_++;
    }
    vector<int> answer;
    int max = v1_;
    answer.push_back(1);
    if (max < v2_)
    {
        answer.clear();
        answer.push_back(2);
        max = v2_;
    }
    else if (max == v2_)
    {
        answer.push_back(2);
    }
    if (max < v3_)
    {
        answer.clear();
        answer.push_back(3);
        max = v3_;
    }
    else if (max == v3_)
    {
        answer.push_back(3);
    }

    return answer;
}
int main()
{
    vector<int>answers = { 1,3,2,4,2 };
    solution(answers);
    return 0;
}