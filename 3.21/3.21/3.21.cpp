#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int n;

struct node
{
	int l;
	int r;
}a[N];

bool cmp(node& x,node& y)
{
	return x.l < y.l;
}

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].l >> a[i].r;
	
	//按照左端点升序进行排序
	sort(a+1,a+1+n,cmp);
	
	//拿出第一个区间即为第一个区间被选 
	int ret = 1;
	
	//以第一个区间的右端点为基准值
	int r = a[1].r;
	
	for(int i = 2;i <= n;i++)
	{
		int left = a[i].l,right = a[i].r;
		if(left < r)
		{
			//第二个区间的左端点 < 第一个区间的右端点即为重叠
			//进行舍弃
			r = min(right,r); 
		}
		else
		{
			//不重叠，即为合法区间
			ret++;
			r = right; 
		}
	} 
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1010;

int n;
double d;

struct node
{
	double l;
	double r;
}a[N];


bool cmp(node& x, node& y)
{
	return x.l < y.l;
}

int main()
{
	int cnt = 0;
	while (cin >> n >> d, n && d)
	{
		cnt++;
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			double x, y; cin >> x >> y;
			if (y > d)flag = true;
			double len = sqrt(d * d - y * y);
			a[i].l = x - len;
			a[i].r = x + len;
		}
		cout << "Case " << cnt << ":";
		if (flag) cout << -1 << endl;

		else
		{
			//左端点升序 
			sort(a + 1, a + 1 + n, cmp);

			int ret = 1;
			double r = a[1].r;
			for (int i = 2; i <= n; i++)
			{
				//下一个区间 
				double left = a[i].l;
				double right = a[i].r;

				if (left <= r)
				{
					//重叠就取右端点小的
					r = min(r, a[i].r);
				}
				else
				{
					ret++;
					r = right;
				}
			}
			cout << ret << endl;
		}
	}
	return 0;
}

