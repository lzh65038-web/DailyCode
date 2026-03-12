#include <iostream>

using namespace std;


const int N = 1e5 + 10;
int n,q,a[N];

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> q;
	while(q--)
	{
		LL x,y;cin >> x >> y;
		//找到左端点为l,右端点为r的区间，查询区间元素个数
		//1.左端点为x
		int l = 1,r = n;
		while(l < r)
		{
			int mid = (l + r)  / 2;
			if(a[mid] >= x) r = mid;
			else l = mid + 1;
		}
        if(a[l] < x)
        {
            cout << 0 << endl;
            continue;
        }
		int ret_l = l;
		//2.右端点
		l = ret_l,r = n;
		while(l < r)
		{
			int mid = (l + r + 1) / 2;
			if(a[mid] <= y) l = mid;
			else r = mid - 1;
		}
		if(a[r] > y)
        {
            cout << 0 << endl;
            continue;
        }	
		cout << r - ret_l + 1 << endl;	
	}
	return 0;
 }

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n,q,a[N];

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> q;
	while(q--)
	{
		int x,y;cin >> x >> y; 
		auto left = lower_bound(a+1,a+n+1,x);
		if(*left > y)
		{
			cout << 0 << endl;
			continue;
		}
		auto right = upper_bound(a+1,a+n+1,y);
		cout << right - left << endl;
	}
	return 0;
 } 


#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL; 
const int N = 2e5 + 10;
int n,c,a[N];

int main()
{
	cin >> n >> c;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	//枚举A,得到 B
	LL ret = 0; 
	for(int i = 2;i <= n;i++)
	{
		int x = a[i] - c;
		//找到x的起始与终止位置
		auto left = lower_bound(a+1,a+i,x);
		auto right = upper_bound(a+1,a+i,x);
		ret += right - left; 
	}
	cout << ret << endl;
	return 0;
 } 
