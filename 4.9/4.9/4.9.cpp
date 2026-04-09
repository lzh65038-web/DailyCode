#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int n;

priority_queue<LL, vector<LL>, greater<LL>> heap;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		heap.push(x);
	}

	LL ret = 0;
	while (heap.size() > 1)
	{
		LL a = heap.top(); heap.pop();
		LL b = heap.top(); heap.pop();

		ret += a + b;
		heap.push(a + b);
	}

	cout << ret << endl;

	return 0;
}