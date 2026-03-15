#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n, m;
int a[N];

LL calc(LL x)
{
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= x) ret += a[i] - x;
	}
	return ret;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	//寻找右端点
	int l = 0, r = 1e6;
	while (l < r)
	{
		LL mid = (l + r + 1) / 2;
		if (calc(mid) >= m) l = mid;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}

#include <iostream>

using namespace std;

const int N = 5e4 + 10;
int l, n, m;
int a[N];

int calc(int x)
{
	int cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		int j = i + 1;
		while (j <= n && a[j] - a[i] < x) j++;
		cnt += j - i - 1;
		i = j - 1;
	}
	return cnt;
}
int main()
{
	cin >> l >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = l;
	n++;

	int left = 1, right = l;
	while (left < right)
	{
		int mid = (left + right + 1) / 2;
		//当前mid的跳跃距离对应移走的岩石数目 
		if (calc(mid) <= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	return 0;
}




//题一 
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, k;
LL a[N];

LL calc(int x)
{
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i] / x;
	}
	return sum;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e9;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (calc(mid) >= k) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}



//题二 
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;
int n, m;
LL a[N];

LL calc(int x)
{
	LL cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt += x / a[i];
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 2e5;
	while (l < r)
	{
		LL mid = (l + r) / 2;
		if (calc(mid) >= mid) r = mid;
		l = mid + 1;
	}
	cout << l << endl;
	return 0;
}




//题三 
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n, c;
LL a[N];

LL calc(int x)
{
	LL ret = 0;
	LL cnt = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			ret = min(ret, a[j] - a[i]);
			if (ret >= x) cnt++;
		}
	}
}
int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e5 + 10;
	while (l < r)
	{
		LL mid = (l + r + 1) / 2;
		if (calc(mid) <= c) l = mid;
		r = mid - 1;
	}
	return 0;
}


//题一 
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, h;
LL a[N];


bool calc(LL x)
{
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		LL time = 0;
		time += ceil(a[i] / x);
		if (time > h) return false;
	}
	return true;
}
int main()
{
	cin >> n >> h;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int l = 1, r = 1e9;
	while (l < r)
	{
		LL mid = (l + r) / 2;
		if (calc(mid) <= h) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}


//题二 
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n, d;
LL a[N];

int calc(LL x)
{
	long long cur = 0;
	long long days = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] + cur > c)
		{
			days++;
			cur = 0;
		}
		cur += a[i];
	}
	return days <= d;
}
int main()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e5;
	while (l < r)
	{
		LL mid = (l + r) / 2;
		if (calc(mid) <= d) r = mid;
		else l = mid + 1;
	}
	return 0;
}


#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, k;
LL a[N];

LL calc(LL x)
{
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += a[i] / x;
	}
	return ret;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e9;
	while (l < r)
	{
		LL mid = (l + r + 1) / 2;
		if (calc(mid) >= k) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}

