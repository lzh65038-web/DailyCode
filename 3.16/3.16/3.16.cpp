#include <iostream>
#include <algorithm>
 
using namespace std;

const int N = 1e5 + 10;

int n,a[N]; 

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int ret = 0;
//	for(int i = 1;i <= n;i++)
//	{
//		ret += abs(a[i] - a[(i + 1) / 2]);
//  }
    //直接用结论
	for(int i = 1;i <= n / 2;i++)
	{
		ret += abs(a[i] - a[n + 1 - i]); 
	} 
    cout << ret << endl;
	return 0;
}


#include <iostream>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n,a[N];

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	LL sum = 0,ret = -1e6;
	for(int i = 1;i <= n;i++)
	{
		sum += a[i];
		ret = max(sum,ret);
		if(sum < 0) sum = 0;
	}
	cout << ret << endl;
	return 0;
} 

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int n;
LL f[N];

int main()
{
	cin >> n;
	//预处理 
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		f[i] = f[i - 1] + x;
	}
	//f[i] - f[m]最大值
	LL ret = -1e6;//记录最终结果 
	LL prevmin = 0;//当前位置之前的最小字段和
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, f[i] - prevmin);
		prevmin = min(f[i], prevmin);
	}
	cout << ret << endl;
	return 0;
}

