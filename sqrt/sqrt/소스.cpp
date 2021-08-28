#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    if (fmod(sqrt(n), 1)) return -1;
    long long answer = pow(static_cast<int>(sqrt(n)) + 1, 2);
    return answer;
}