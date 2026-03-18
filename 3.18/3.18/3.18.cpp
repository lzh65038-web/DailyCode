#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

typedef long long LL;

const int N = 25;
int n,a[N];

bool cmp(int x,int y)
{
	string s1 = to_string(x);
	string s2 = to_string(y);
	
	return s1 > s2;
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	string s = "";
	for(int i = i;i <= n;i++)
	{
		s += to_string(a[i]);
	}
	LL ret = stol(s);
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25;
int n;
string a[N];

bool cmp(string & x,string & y)
{
	return x + y > y + x;
}
int main()
{	
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	
	for(int i = 1;i <= n;i++) cout << a[i];
	return 0;
}


#include <iostream>
#include <map>
using namespace std;

const int N = 1e5 + 10;

const int N = 1e5 + 10;
int n,t[N],d[N];
int ret[N];
map<int,int> mp;//<编号，花数> 

int main()
{
	cin >> n;
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> t[i] >> d[i];
		sum += d[i];
	}
	for(int i = 1;i <= n;i++)
	{
		mp[i] = 2 * t[i] * (sum - d[i]);
	}	 
	//顺序输出编号
	while(!mp.empty())
	{
		cout << mp.begin()->first << 
	} 
	
	return 0
} 


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int n;

const int N = 1e5 + 10;
struct node
{
	int t;
	int d;
}a[N];

bool cmp(node& x, node& y)
{
	return x.t * y.d < y.t * x.d;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].t >> a[i].d;
	//找到最优顺序
	sort(a + 1, a + 1 + n, cmp);
	LL ret = 0;
	LL time = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += a[i].d * time;
		time += 2 * a[i].t;
	}
	cout << ret << endl;
	return 0;
}
