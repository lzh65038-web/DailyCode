#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n;
string path;

void dfs(int pos)
{
	if (pos > n)
	{
		cout << path << endl;
		return;
	}
	//ฒปัก
	path += 'N';
	dfs(pos + 1);
	path.pop_back();

	//ัก
	path += 'Y';
	dfs(pos + 1);
	path.pop_back();
}
int main()
{
	cin >> n;

	dfs(1);
	return 0;
}