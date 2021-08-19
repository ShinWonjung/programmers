#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    if (new_id == " ")
        return "aaa";

    for (int i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            answer += new_id[i] - 'A' + 'a';
        else if (new_id[i] == '.')
        {
            while (new_id[i + 1] != '.')
            {

            }
        }
    }

    return answer;
}