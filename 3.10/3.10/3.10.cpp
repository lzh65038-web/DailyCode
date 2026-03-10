#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e3 + 10;

LL f[N][N];
int n,m,q;

void insert(int x1,int y1,int x2,int y2,int k)
{
	f[x1][y1] += k;
	f[x1][y2+1] -= k;
	f[x2+1][y1] -= k;
	f[x2+1][y2+1] += k; 
}
int main()
{
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			//预处理
			LL a; cin >> a;
			insert(i,j,i,j,a); 
		}
	}
	//处理q次操作
	while(q--)
	{
			LL x1,y1,x2,y2,k;
			cin >> x1 >> y1 >> x2 >> y2 >> k;
			insert(x1,y1,x2,y2,k);
	}
	//前缀和恢复原始数组
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j];
			cout << f[i][j] << " ";
		}
		cout << endl;
	 } 
	return 0;
 } 

#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n,m; 
int f[N][N];

void insert(int x1,int x2,int y1,int y2,int k)
{
	f[x1][y1] += k;
	f[x1][y2+1] -= k;
	f[x2+1][y1] -= k;
	f[x2+1][y2+1] += k; 
}
int main()
{
	cin >> n >> m;
	while(m--)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> x2 >> y1 >> y2;
		insert(x1,y1,x2,y2,1);
	}
	//恢复原始数组
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j];
			cout << f[i][j] << " ";
		}
		cout << endl;
	 } 
	return 0;
} 

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> mp;
const int N = 1e6 + 10;
int t,n;
int a[N];

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		
		int left = 1,right = 1,ret = 0;
		while(right <= n)//在合法区间内 
		{
			mp[a[right]]++;
			while(mp[a[right]] > 1)
			{
				mp[a[left]]--;
				left++;
			}
			//更新结果
			ret = max(ret,right-left+1);
			right++;
		}
		cout << ret << endl;
	}
	return 0;
 } 

#include <iostream> 
#include <unordered_map>
using namespace std;

const int N = 1e6 + 10;
int n,m;
int a[N];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	//滑动窗口
	//找到一个至少包含m个不同元素的区间，同时l尽可能小
	int l = 1,r = 1;
	unordered_map<int,int> mp;
	int best_l = 1,best_r = n;
	int best_len = 1e9;
	while(r <= n)
	{
		mp[a[r]]++;
		//找到合法的区间
		while(mp.size() == m)
		{
			//缩小窗口
			if(r-l+1 < best_len)
			{
				best_len = r - l + 1;
				best_l = l;
				best_r = r;
			}
			mp[a[l]]--;
			if(mp[a[l]] == 0) mp.erase(a[l]);
			l++; 
		}
		r++; 
	}
	cout << best_l << " " << best_r << endl;
	return 0;
}

#include <iostream>

using namespace std;

const int N = 1e5  + 10,M = 2e3 + 10;
int n,m;
int a[N];
int kind,mp[M];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	int ret = n;
	int left = 1,right = 1; 
	int l = 1,r = n;
	
	while(right <= n)
	{
		if(mp[a[right]]++ == 0) kind++;
		
		while(kind == m)
		{
			int len = right - left + 1;
			if(len < ret)
			{
				ret = len;
				l = left;
				r = right;
		    }
			if(mp[a[left]]-- == 1) kind--;
			left++;
		}
		right++; 
	}
	cout << l << " " << r << endl; 
	return 0;
 } 


#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	unordered_map<int, int> mp;
	int left = 1, right = 1;
	int best_len = 1e9;
	int best_l = 1;
	int best_r = n;

	while (right <= n)
	{
		mp[a[right]]++;

		while (mp.size() == m)
		{
			//判断是否需要更新区间 
			int len = right - left + 1;
			if (len < best_len)
			{
				//进行更新
				best_len = len;
				best_l = left;
				best_r = right;
			}
			//左指针右移
			mp[a[left]]--;
			if (mp[a[left]] == 0) mp.erase(a[left]);
			left++;
		}
		right++;
	}
	cout << best_l << " " << best_r << endl;
	return 0;
}
