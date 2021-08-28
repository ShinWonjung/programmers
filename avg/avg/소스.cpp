#include <numeric>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = accumulate(arr.begin(), arr.end(), 0LL);
    return answer / arr.size();
}