#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (auto v : d)
    {
        if (budget >= v)
        {
            budget -= v;
            answer++;
        }
        else break;
    }
    return answer;
}