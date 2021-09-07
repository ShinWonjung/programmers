#include <cmath>
#include <iostream>
using namespace std;

long long solution(int w, int h) {
    long long gop = w * h;
    if (w == h) return gop - w;
    int cnt = 1;
    long long _w = w;
    long long _h = h;
    while (1)
    {
        if (_w % 2 == 0 && _h % 2 == 0)
        {
            _w /= 2;
            _h /= 2;
            cnt *= 2;
        }
        else break;
    }
    long long answer = _w + _h - 1;
    answer *= cnt;
    answer = w * h - answer;
    return answer;
}
int main()
{
    cout << solution(6, 4);
}