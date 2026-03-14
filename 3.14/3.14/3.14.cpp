#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int m, n;
int a[N], b[N];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		//二分寻找t的左右端点
		int l = 1, r = m;
		while (l < r)
		{
			LL mid = (l + r) / 2;
			if (a[mid] >= t) r = mid;
			else l = mid + 1;
		}
		int ret_l = l;
		//右端点 
		l = 1, r = m;
		while (l < r)
		{
			LL mid = (l + r + 1) / 2;
			if (a[mid] <= t) l = mid;
			else r = mid - 1;
		}
		LL x = abs(a[ret_l] - t);
		LL y = abs(a[r] - t);

		ret += min(x, y);
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int m, n;
int a[N], b[N];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		int pos = lower_bound(a + 1, a + 1 + m, t) - a;
		if (pos == m + 1)
		{
			//没找到
			LL x = abs(a[1] - t);
			LL y = abs(a[m] - t);
			ret += min(x, y);
		}
		else
		{
			ret += abs(a[pos] - t);
		}

	}
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int m, n;
LL a[N];

int find(LL t)
{
	int l = 1, r = m;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (a[mid] >= t) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + 1 + m);
	a[0] = -1e7;
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		LL t; cin >> t;
		int pos = find(t);
		ret += min(abs(a[pos] - t), abs(a[pos - 1] - t));
	}
	cout << ret << endl;
}

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n, k, a[N];

LL calc(LL x)
{
	LL cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt += a[i] / x;
	}
	return cnt;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//找右端点
	int left = 0, right = 1e8;
	while (left < right)
	{
		LL mid = (left + right + 1) / 2;
		if (calc(mid) >= k)
		{
			//还能继续向右查找
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << left << endl;
	return 0;
}