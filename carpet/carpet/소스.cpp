#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 5000; i > 0; i--)
    {
        for (int j = 1; j <= 5000; j++)
        {
            if (brown == ((i * 2) + (j * 2) - 4) && yellow == (i * j - brown))
            {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
}