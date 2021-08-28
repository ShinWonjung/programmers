#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;
    long long num = n;
    while (num != 1)
    {
        if (cnt == 500) return -1;
        if (num % 2) num = num * 3 + 1;
        else num /= 2;
        cnt++;
    }
    return cnt;
}