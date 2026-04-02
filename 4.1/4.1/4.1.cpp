#define _CRT_SECURE_NO_WARNINGS
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
	
	//将已填格子的处理逻辑与尝试填数字的逻辑分开
	if(a[x][y]) return dfs(x,y+1);
	
	for(int i = 1;i <= n;i++)
	{
		if(row[x][i] || col[y][i] || st[x/3][y/3][i]) continue;
		
		row[x][i] = col[y][i] = st[x/3][y/3][i] = true;
		a[x][y] = i;
		//判断返回值是为了决定当前分支是否成功
		if(dfs(x,y+1)) return true;
		row[x][i] = col[y][i] = st[x/3][y/3][i] = false;
		a[x][y] = 0;
	}
	//当前分支无解，必须回溯到上一层
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
#include <algorithm>

using namespace std;

const int N = 20;

int n,w;
int c[N];
int cnt,s[N];
int ret = N;

bool cmp(int a,int b)
{
	return a > b;
}

void dfs(int pos)
{
	if(cnt > ret) return;
	if(pos > n)
	{
		ret = cnt;
		return;
	}
	
	//先尝试加入到已有缆车中 
	for(int i = 1;i <= cnt;i++)
	{
		if(c[pos] + s[i] > w) continue;
		
		s[i] += c[pos];
		dfs(pos+1);
		s[i] -= c[pos];
	}
	
	//再开新缆车
	cnt++;
	s[cnt] = c[pos];
	dfs(pos+1);
	s[cnt] = 0;
	cnt--; 
}

int main()
{
	cin >> n >> w;
	for(int i = 1;i <= n;i++) cin >> c[i];
	
	sort(c+1,c+1+n,cmp);
	
	dfs(1);
	
	cout << ret << endl;
	return 0;
}

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 25;

LL a,b,c;
LL f[N][N][N];

LL dfs(LL a,LL b,LL c)
{
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if(a > 20 || b > 20 || c > 20) return dfs(20,20,20);
	
	if(f[a][b][c]) return f[a][b][c];
	
	if(a < b && b < c) return f[a][b][c] = dfs(a,b,c-1) + dfs(a,b-1,c-1) - dfs(a,b-1,c);
	
	return f[a][b][c] = dfs(a-1,b,c) + dfs(a-1,b-1,c) + dfs(a-1,b,c-1) - dfs(a-1,b-1,c-1);
	
}

int main()
{
	while(cin >> a >> b >> c)
	{
		if(a == -1 && b == -1 && c == -1) break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,dfs(a,b,c));
	}
	return 0;
}


#include <iostream>

using namespace std;

const int N = 210;

int T,p;
int x,y;
int f[N][N];
int cnt = 1;

int dfs(int x,int y)
{
	if((cnt % 2) && ((x + y) % p == 0)) return 1;
	if((cnt % 2 != 0) && ((x + y) % p == 0)) return 2;
	
	if(f[x][y]) return -1;
	
	x = (x + y)
	
	cnt++;
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> x >> y;
		if(dfs(x,y) == 1) cout << 1 << endl;
		else if(dfs(x,y) == 2) cout << 2 << endl;
		else cout << "error" << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int T, p;
int x, y;
char f[N][N];

char dfs(int x, int y)
{
	if (f[x][y]) return f[x][y];

	f[x][y] = '3';

	if (x == 0) return f[x][y] = '1';
	if (y == 0) return f[x][y] = '2';

	return f[x][y] = dfs((x + y) % p, (x + y + y) % p);
}

int main()
{
	cin >> T >> p;
	while (T--)
	{
		cin >> x >> y;
		char ret = dfs(x, y);
		if (ret == '1') cout << 1 << endl;
		else if (ret == '2') cout << 2 << endl;
		else cout << "error" << endl;
	}
	return 0;
}

