#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<pair<string, string>>records;
    unordered_map<string, string>user;
    for (int i = 0; i < record.size(); i++)
    {
        vector<string>temp;
        istringstream ss(record[i]);
        string stringbuffer;
        while (getline(ss, stringbuffer, ' '))
            temp.push_back(stringbuffer);
        
        if (temp[0] == "Enter" || temp[0] == "Change")
            user[temp[1]] = temp[2];
        
        if (temp[0] == "Enter" || temp[0] == "Leave")
            records.push_back(make_pair(temp[0], temp[1]));
    }
    vector<string> answer;
    for (int i = 0; i < records.size(); i++)
    {
        if (records[i].first == "Enter")
        {
            answer.push_back(user[records[i].second]);
            answer.back() += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else
        {
            answer.push_back(user[records[i].second]);
            answer.back() += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
    }
    return answer;
}