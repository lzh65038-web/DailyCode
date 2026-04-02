#include <iostream>

using namespace std;

const int N = 110;

int n,m;
int a[N][N];
int ret;

void dfs(int x,int y)
{
	if(a[x][y] == 1) return;
	
	int val = a[x][y];
	if(val > a[x + 1][y])
	{
		ret = max(val,ret);
		dfs(x+1,y);
	}
	if(val > a[x - 1][y])
	{
		ret = max(val,ret);
		dfs(x-1,y);
	}
	if(val > a[x][y + 1])
	{
		ret = max(val,ret);
		dfs(x,y+1);
	}
	if(val > a[x][y - 1])
		{
		ret = max(val,ret);
		dfs(x,y-1);
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	}
	
	dfs(1,1);
	
	cout << ret << endl;
	return 0;
}

#include <iostream>

using namespace std;

const int N = 110;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int n,m;
int a[N][N];
int f[N][N];

int dfs(int i,int j)
{
	if(f[i][j]) return f[i][j];
	
	//初始化为至少一个格子 
	int len = 1;
	
	for(int k = 0;k < 4;k++)
	{
		int x = i + dx[k],y = j + dy[k];
		
		if(x < 1 || y < 1 || x > n || y > m) continue;
		if(a[x][y] >= a[i][j]) continue;
		
		len = max(dfs(x,y) + 1,len);
	}
	return f[i][j] = len;
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	}
	
	int ret = 1;
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			ret = max(dfs(i,j),ret);
		}
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 410;

typedef pair<int,int> PII;

int n,m,x,y;
int dist[N][N];

int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,-1,1};



void bfs()
{
	memset(dist,-1,sizeof(dist));
	
	queue<PII> q;
	
	q.push({x,y});
	dist[x][y] = 0;
	
	while(q.size())
	{
		auto e = q.front(); q.pop();
		int i = e.first;
		int j = e.second;
		for(int k = 0;k < 8;k++)
		{
			int x = i + dx[k],y = j + dy[k];
			if(x < 1 || x > n || y < 1 || y > m) continue;
			if(dist[x][y] != -1) continue;
			
			dist[x][y] = dist[i][j] + 1;
			
			q.push({x,y});
		}
		
	}
	
}

int main()
{
	cin >> n >> m >> x >> y;
	
	bfs();
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cout << dist[i][j] <<  " ";
		}
		cout << endl;
	}
	
	return 0;
}


#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int>  PII;

const int N = 410;

int n,m,x,y;
int dist[N][N];

int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,-1,1};

void bfs()
{
	memset(dist,-1,sizeof(dist));
	
	queue<PII> q;
	q.push({x,y});
	dist[x][y] = 0;
	
	while(q.size())
	{
		auto e = q.front(); q.pop();
		int p = e.first,s = e.second;
		
		for(int k = 0;k < 8;k++)
		{
			int i = p + dx[k];
			int j = s + dy[k];
			
			if(i < 1 || i > n || j < 1 || j > m) continue;
			if(dist[i][j] != -1) continue;
			
			dist[i][j] = dist[p][s] + 1;
			
			q.push({i,j});
		}
	}
}

int main()
{
	cin >> n >> m >> x >> y;
	 
	bfs();
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 


#include <iostream>
#include <queue> 
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 35;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int n, m;
char a[N][N];
int dist[N][N];
int ret;
int cnt = 1e5;

void bfs(int x, int y)
{
	memset(dist, -1, sizeof(dist));
	queue<PII> q;
	q.push({ x,y });
	dist[x][y] = 0;

	while (q.size())
	{
		auto e = q.front(); q.pop();
		int u = e.first, v = e.second;
		for (int k = 0; k < 4; k++)
		{
			int i = u + dx[k], j = v + dy[k];

			if (i < 1 || i > n || j < 1 || j > m) continue;
			if (dist[i][j] != -1) continue;
			if (a[i][j] == '*') continue;
			if (a[i][j] == 'e')
			{
				dist[i][j] = dist[u][v] + 1;
				cnt = min(cnt, dist[i][j]);
				ret++;
				continue;
			}

			q.push({ i,j });
			dist[i][j] = dist[u][v] + 1;

		}

	}
}

int main()
{
	cin >> n >> m;
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'k')
			{
				x = i;
				y = j;
			}
		}
	}

	bfs(x, y);

	if (ret == 0) cout << -1 << endl;
	else cout << ret << " " << cnt << endl;
	return 0;
}
