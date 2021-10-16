#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int ans = 665;
	int cnt = 0;
	while (cnt != n)
	{
		++ans;
		string temp = to_string(ans);
		if (temp.find("666") != string::npos)
			cnt++;
	}
	cout << ans;
	return 0;
}