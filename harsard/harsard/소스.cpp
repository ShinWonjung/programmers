#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int _x = x;
    while (_x)
    {
        sum += _x % 10;
        _x /= 10;
    }
    return x % sum ? false : true;
}