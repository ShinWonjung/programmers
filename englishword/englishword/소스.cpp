#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);

    unordered_set<string>set;
    set.insert(words[0]);
    for (int i = 1; i < words.size(); i++)
    {
        set.insert(words[i]);
        if (words[i - 1].back() != words[i].front() ||
            set.size() - 1 != i)
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
    }

    return answer;
}