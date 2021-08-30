#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int result = 1;
    while (1)
    {
        bool stop = false;
        for (int i = 2; i <= arr.back(); i++)
        {
            if (i == arr.back()) stop = true;

            bool b = false;
            int cnt = 0;
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j] % i == 0)
                    cnt++;
                if (cnt == 2)
                {
                    b = true;
                    break;
                }
            }
            if (b == true)
            {
                for (int j = 0; j < arr.size(); j++)
                {
                    if (arr[j] % i == 0)
                        arr[j] /= i;
                }
                sort(arr.begin(), arr.end());
                result *= i;
                break;
            }
        }
        if (stop == true) break;
    }
    for (int j = 0; j < arr.size(); j++)
        result *= arr[j];
    return result;
}
int main()
{
    vector<int>v = { 3,4,9,16 };
    solution(v);
}