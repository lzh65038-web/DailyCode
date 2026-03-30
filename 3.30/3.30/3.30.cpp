#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int N = 15;

int n;

int ret;
vector<int> path;
bool col[N],st1[N * 2],st2[N * 2];

void dfs(int x)
{
	if(x > n)
	{
		ret++;
		if(ret <= 3)
		{
			for(auto e : path) cout << e << " "; 
			cout << endl;
		}
		return;
	}
	//以行为基准进行放置
	for(int y = 1;y <= n;y++)
	{
		//剪枝 
		if(col[y] || st1[y - x + n] || st2[y + x]) continue;
		path.push_back(y);
		col[y] = st1[y - x + n] = st2[y + x] = true;
		dfs(x+1);
		col[y] = st1[y - x + n] = st2[y + x] = false;
		path.pop_back();
	} 
}

int main()
{
	cin >> n;
	
	dfs(1);
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <cstring> 
using namespace std;

const int N = 12;

int n;
int a[N][N];
bool st[N];

void dfs(int x,int y)
{
	if(x > n || y > n) return;
	//标记所有已经出现的数字
	for(int i = 1;i <= n;i++)
	{
		if(a[x][i]) st[a[x][i]] = true;
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i][y]) st[a[i][y]] = true;
	} 
	if(a[x][y] == 0)
	{
		int tmp = 0;
		for(int i = 1;i <= n;i++)
		{
			if(!st[i]) tmp = st[i];
			break; 
		}
		a[x][y] = tmp;
	} 
	dfs(x,y+1);
	dfs(x+1,y);
	dfs(x+1,y+1);
	memset(st,0,sizeof(st));
}

int main()
{
	n = 9;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	
	dfs(1,1);
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

#include <iostream> 

using namespace std;

const int N = 10;

int n = 9;
int a[N][N];
bool row[N][N];
bool col[N][N];
bool st[N][N][N];

bool dfs(int x,int y)
{
	if(y == n)
	{
		x++;
		y = 0;
	} 
	if(x == n) return true;
	
	if(a[x][y]) return dfs(x,y+1);
	
	for(int i = 1;i <= 9;i++)
	{
		if(row[x][i] || col[y][i] || st[x/3][y/3][i]) continue;
		row[x][i] = col[y][i] = st[x/3][y/3][i] = true;
		a[x][y] = i;
		
		if(dfs(x,y+1)) return true;
		
		row[x][i] = col[y][i] = st[x/3][y/3][i] = false;
		a[x][y] = 0;
	}
	return false;
}
int main()
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cin >> a[i][j];
			int x = a[i][j];
			if(x)
			{
				row[i][x] = col[j][x] = st[i/3][j/3][x] = true;
			}
		}
	}
	
	dfs(0,0);
	
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 15;

int n;
int t[N], d[N], l[N];
bool st[N];

bool dfs(int pos, int end)
{
	if (pos > n) return true;

	for (int i = 1; i <= n; i++)
	{
		if (st[i]) continue;
		if (end > t[i] + d[i]) continue;

		st[i] = true;
		int newend = max(t[i], end) + l[i];
		//如果后续找到一解，直接返回true 
		if (dfs(pos + 1, newend)) return true;
		st[i] = false;
	}
	return false;
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		memset(st, 0, sizeof(st));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> t[i] >> d[i] >> l[i];

		if (dfs(1, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

