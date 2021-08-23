//#include <string>
//#include <vector>
//#include <stack>
//#include <iostream>
//using namespace std;
//
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//    vector<string> answer;
//    for (int i = 0; i < n; i++)
//    {
//        answer.push_back("");
//        stack<int> s1;
//        stack<int> s2;
//        while (arr1[i] >= 2)
//        {
//            s1.push(arr1[i] % 2);
//            arr1[i] /= 2;
//        }
//        if (s1.size() < n)
//            s1.push(arr1[i]);
//        while (s1.size() < n)
//            s1.push(0);
//        while (arr2[i] >= 2)
//        {
//            s2.push(arr2[i] % 2);
//            arr2[i] /= 2;
//        }
//        if (s2.size() < n)
//            s2.push(arr2[i]);
//        while (s2.size() < n)
//            s2.push(0);
//        while (!s1.empty())
//        {
//            if (s1.top() || s2.top())
//                answer[i] += '#';
//            else
//                answer[i] += ' ';
//            s1.pop();
//            s2.pop();
//        }
//    }
//    return answer;
//}
//int main()
//{
//    int n = 6;
//    vector<int>arr1 = { 46, 33, 33 ,22, 31, 50 };
//    vector<int>arr2 = { 27 ,56, 19, 14, 14, 10 };
//    vector<string>s = solution(n, arr1, arr2);
//    for (auto a : s)
//        cout << a << '\n';
//}