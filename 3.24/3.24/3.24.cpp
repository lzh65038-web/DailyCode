#include <iostream>
#include <algorithm>
#include <unordered_map>
 
using namespace std;

const int N = 2e4 + 10;

int n,a[N],b[N];

unordered_map <int,int> mp;
int pos,disc[N * 2];

int f[N * 2];

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = b[i];
	}
	
	sort(disc+1,disc+1+pos);
	//如果想找到离散化之前的数组，必须要对数组去重 
 	pos = unique(disc+1,disc+1+pos) - (disc+1);
	//元素数量即为pos 
	
	for(int i = 1;i <= pos;i++)
	{
		int x = disc[i];
		mp[x] = i;
 	}
 	
 	//差分预处理 
 	for(int i = 1;i <= n;i++)
 	{
 		int l = mp[a[i]];
 		int r = mp[b[i]];
 		
 		f[l]++;f[r]--;
	}
	//还原差分数组 
	for(int i = 1;i <= pos;i++)
	{
		//mp中的数一共存到了cnt个，因此便利cnt次即可 
		//计算当前位置的前缀和
		f[i] = f[i-1] + f[i]; 
	}
	int ret = 0;
	for(int i = 1;i <= pos;i++)
	{
		int j = i;
		while(j <= pos && f[j] > 0) j++;
		//i~j
		ret += disc[j] - disc[i]; 
		i = j;
	}
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int M = 1010;

int n,m;
int a[M],b[M];

int pos,disc[M*2],ret[M];
unordered_map<int,int> mp;

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = b[i];
	}
	
	sort(disc+1,disc+1+pos);
	
	int cnt = 0;
	for(int i = 1;i <= m;i++)
	{
		int x = disc[i];
		if(mp.count(x)) continue;
		mp[x] = ++cnt;
	}
	
	//模拟
	for(int i = 1;i <= m;i++)
	{
		int l = mp[a[i]];
		int r = mp[b[i]];
		
		for(int j = l;j <= r;j++)
		{
			ret[j] = i;
		}
	 } 
	 int ans = 0;
	 for(int i = 2;i <= m;i++)
	 {
	 	//查询有几种不同的数字 
	 	if(a[i-1] != a[i]) ans++;
	 }
	 cout << ans << endl;
	return 0;
}

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 1010;

int n,m;
int a[N],b[N];

int pos,disc[N * 4];
unordered_map<int,int> mp;
int w[N * 4];//记录最终海报的编号 
bool st[N * 4];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; disc[++pos] = a[i] + 1;
		disc[++pos] = b[i]; disc[++pos] = b[i] + 1;
	}
	
	sort(disc+1,disc+1+pos);
	
	int cnt = 0;
	for(int i = 1;i <= pos;i++)
	{
		int x = disc[i];
		if(mp.count(x)) continue;
		mp[x] = ++cnt;
	}
	
	//模拟
	for(int i = 1;i <= m;i++)
	{
		int l = mp[a[i]];
		int r = mp[b[i]];
		
		for(int j = l;j <= r;j++)
		{
			//i~j
			w[j] = i;
		}
	} 
	 
	 //统计w[]数组中不同元素的个数 
	 int ret = 0;
	 for(int i = 1;i <= cnt;i++)
	 {
	 	int x = w[i];
	 	if(!x || st[x]) continue;
	 	ret++;
	 	st[x] = true;
	 }
	 cout << ret << endl;
	return 0;
}


#include <iostream>

using namespace std;

int n;
string s;

string func()
{
	//1.将A上的1-(n-1)个圆盘全部转移到C
	//2.将A上唯一的圆盘转移到B，并将C上所有圆盘转移到A 
}
int main()
{
	cin >> n >> s;
	func()
		return 0;
}
