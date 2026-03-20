#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int n;
//小根堆 
priority_queue<LL,vector<LL>,greater<LL>> heap;

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) 
	{
		int x;cin >> x;
		heap.push(x);
	}
	//构造哈夫曼树
	LL ret = 0;
	while(heap.size() > 1)
	{
		LL x = heap.top();heap.pop();
		LL y = heap.top();heap.pop();
		ret += x + y;
		heap.push(x+y); 
	}
	cout << ret << endl;
	return 0;
 } 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

int n;

priority_queue<int, vector<int>, greater<int>> heap;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		heap.push(x);
	}

	int ret = 0;
	while (heap.size() > 1)
	{
		int x = heap.top(); heap.pop();
		int y = heap.top(); heap.pop();
		ret += x + y;
		heap.push(x + y);
	}
	cout << ret << endl;
	return 0;
}
