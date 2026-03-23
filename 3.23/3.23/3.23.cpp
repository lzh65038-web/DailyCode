测试数据 
10
1999999
12
1999999
-48444
568
12
-100
-2845630
100000001
263

//离散化模版一
//排序 + 去重 + 二分  
#include <iostream>
#include <algorithm>

using namespace std; 

const int N = 1e5 + 10;

int n,a[N];//原始数据
 
int pos,disc[N];//帮助离散化 
 
int find(int x)
{
	//二分查找x对应的下标
	int l = 1,r = pos;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(disc[mid] >= x)  r = mid;
		else l =  mid + 1;
	}
	return l; 
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];
	}
	
	//排序+去重 
	sort(disc+1,disc+1+n);
	//unique返回指针，减去初始位置的指针即为元素个数 
	pos = unique(disc+1,disc+1+n) - (disc+1);
	
	for(int i = 1;i <= n;i++)
	{
		cout << a[i] << "离散化后：" << find(a[i]) << endl; 
	}
	return 0;
}


//离散化模版一
//排序 + 哈希表 
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std; 

const int N = 1e5 + 10;

int n,a[N];//原始数据
 
int pos,disc[N];//帮助离散化 
unordered_map<int,int> mp;
 
 
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		disc[pos] = a[i];
	}
	
	//排序
	sort(disc+1,disc+1+pos);
	
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		int x = disc[i];
		if(mp.count(x)) continue;//哈希表中已经有该元素了
		mp[x] = ++cnt;
	}
	
	for(int i = 1;i <= n;i++)
	{
		cout << a[i] << "离散化后：" << mp[a[i]] << endl; 
	}
	return 0;
}



#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10;

int n;
unordered_map<int,int> mp;

int main()
{
	cin >> n;
	int cnt = 0;
	while(n--)
	{
		int x,y;cin >> x >> y;
		for(int i = x;i < y;i++)
		{
			if(mp.count(i)) continue;
			mp[i] = ++cnt;
		}
	}
	cout << mp.size() << endl;
	return 0;
}

