#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 2)
    {
        if (n % 3 == 0)
        {
            n--;
            answer = '4' + answer;
        }
        else if (n % 3 == 1)
            answer = '1' + answer;
        else if (n % 3 == 2)
            answer = '2' + answer;

        n /= 3;
    }
    if (n == 1)
        answer = '1' + answer;
    else if (n == 2)
        answer = '2' + answer;

    return answer;
}