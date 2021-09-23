#include <string>
#include <vector>

using namespace std;

int cnt(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n % 2)
            cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int key = cnt(n);
    while (1)
    {
        n++;
        if (cnt(n) == key)
            break;
    }
    return n;
}