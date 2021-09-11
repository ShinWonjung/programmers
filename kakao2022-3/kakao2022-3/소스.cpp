#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	vector<pair<string, pair<string, string>>>vec;
	for (int i = 0; i < records.size(); i++)
	{
		istringstream ss(records[i]);
		vector<string>v;
		string stringBuffer;
		while (getline(ss, stringBuffer, ' '))
		{
			v.push_back(stringBuffer);
		}
		vec.push_back(make_pair(v[1], make_pair(v[0], v[2])));
	}
	sort(vec.begin(), vec.end());

	map<string, int>map;
	for (int i = 0; i < vec.size(); i++)
	{
		if (i + 1 < vec.size())
		{
			if (vec[i].first == vec[i + 1].first)
			{
				string inT = vec[i].second.first;
				string inM = vec[i].second.first;
				inT.erase(2, 3);
				inM.erase(0, 3);
				string outT = vec[i + 1].second.first;
				string outM = vec[i + 1].second.first;
				outT.erase(2, 3);
				outM.erase(0, 3);

				int time = (stoi(outT) - stoi(inT)) * 60;
				int minute = time;
				minute += stoi(outM) - stoi(inM);

				if (map.find(vec[i].first) != map.end())
					map[vec[i].first] += minute;
				else
					map[vec[i].first] = minute;
				i++;
			}
			else
			{
				string inT = vec[i].second.first;
				string inM = vec[i].second.first;
				inT.erase(2, 3);
				inM.erase(0, 3);

				int time = (23 - stoi(inT)) * 60;
				int minute = time;
				minute += 59 - stoi(inM);

				if (map.find(vec[i].first) != map.end())
					map[vec[i].first] += minute;
				else
					map[vec[i].first] = minute;
			}
		}
		else
		{
			string inT = vec[i].second.first;
			string inM = vec[i].second.first;
			inT.erase(2, 3);
			inM.erase(0, 3);

			int time = (23 - stoi(inT)) * 60;
			int minute = time;
			minute += 59 - stoi(inM);

			if (map.find(vec[i].first) != map.end())
				map[vec[i].first] += minute;
			else
				map[vec[i].first] = minute;
		}
	}

	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (it->second <= fees[0])
		{
			answer.push_back(fees[1]);
			continue;
		}
		int result = it->second - fees[0];
		if (result % fees[2])
		{
			result /= fees[2];
			result++;
		}
		else
			result /= fees[2];
		result *= fees[3];
		result += fees[1];
		answer.push_back(result);
	}
    return answer;
}
int main()
{
	solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
}