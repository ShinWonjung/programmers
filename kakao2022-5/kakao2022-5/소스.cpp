#include <string>
#include <vector>

using namespace std;

int sheep = 1;
int wolf = 0;

int stop = 0;

vector<bool>check(20, 0);
vector<int>_info;
void redfs(int n, vector<int>* vec)
{
	check[n] = 0;
	wolf--;
	for (int i = 0; i < vec[n].size(); i++)
	{
		int next = vec[n][i];
		if (next == stop) return;
		if (check[next] && _info[next]==1)
			redfs(next, vec);
	}
}
void dfs(int n, vector<int>* vec)
{
	check[n] = 1;
	for (int i = 0; i < vec[n].size(); i++)
	{
		int next = vec[n][i];
		if (check[next] == false)
		{
			if (_info[next] == 1)
			{
				if (wolf + 1 < sheep)
				{
					int su = sheep;
					wolf++;
					dfs(next, vec);
					if (su == sheep)
					{
						stop = n;
						redfs(next, vec);
					}
				}
			}
			else if (_info[next] == 0)
			{
				sheep++;
				_info[next] = 3;
				dfs(next, vec);
			}
			else
				dfs(next, vec);
		}
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;

	_info = info;
	vector<int>* vec = new vector<int>[info.size() + 1];

	for (int i = 0; i < edges.size(); i++)
	{
		vec[edges[i][0]].push_back(edges[i][1]);
		vec[edges[i][1]].push_back(edges[i][0]);
	}
	int su = sheep;
	while (1)
	{
		dfs(0, vec);
		if (su == sheep) break;
		su = sheep;
		for (int i = 0; i < check.size(); i++)
			check[i] = 0;
	}

    return sheep;
}
int main()
{
	solution({ 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0 }, { {0, 1},{0, 2},{1, 3},{1, 4},{2, 5},{2, 6},{3, 7},{4, 8},{6, 9},{9, 10} });
}