#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string s;

int main()
{
	cin >> s;
	int n = s.size() - 1;
	//滑动窗口
	int l = 0,r = 0,ret = n;
	unordered_map<char,int> mp;
	while(r <= n)
	{
		mp[s[r]]++;
		while(mp.size() == 26)
		{
			//更新结果
			int len = r - l + 1;
			if(len < ret) ret = len;
			//缩小窗口
			mp[s[l]]--; 
			if(mp[s[l]] == 0) mp.erase(s[l]);
			l++; 
		}
		r++;
	} 
	cout << ret << endl;
	return 0;
}


#include <iostream>

using namespace std;

string s;

int main()
{
	cin >> s;
	//滑动窗口
	int n = s.size() - 1;
	int l = 0,r = 0,ret = n,kind = 0;
	int cnt[26] = {0};
	while(r <= n)
	{
		int x = s[r] - 'a';
		//0~25 映射 a - z 
		//判断是否需要加1
		cnt[x]++;
		if(cnt[x] == 1) kind++;
		while(kind == 26)
		{
			int len = r - l + 1; 
			//更新最短区间
			if(len < ret) ret = len;
			//缩小窗口
			int y = s[l] - 'a';	
			cnt[y]--;
			if(cnt[y] == 0) kind--;
			l++;
		}
		r++; 
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int N,sum;
int a[N];

int main()
{
	cin >> n;
	//1.求出一整圈的长度 
	for(int i = 1;i < n;i++)
	{
		int a[i];cin >> a[i];
		sum += a[i];
	} 
	int la; cin >> la;
	sum += la;
	//2.滑动窗口,找到一个距离最大的子数组
	int l = 1,r = 1;ret = 0,dis = 0;
	//覆盖所有值，在每一段区间中找出当前值的距离 
	while(r < n)
	{
		//计算当前区间的距离
		int dis1 = s[r] - s[l];
		int dis2 = sum - dis1;
		dis = (dis,ret);
		while() 
	}  
	return 0;
}

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N];

int main()
{
	int n; cin >> n;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int l = 1, r = 1;
	LL k = 0;
	LL ret = 0;
	while (r <= n)
	{
		//进入窗口
		k += a[r];
		while (2 * k >= sum)
		{
			ret = max(ret, sum - k);
			//出窗口
			k -= a[l];
			l++;
		}
		ret = max(ret, k);
		r++;
	}
	cout << ret << endl;
	return 0;
}
