#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, P, C;
	cin >> A >> P >> C;

	cout << max(A + C, P) << '\n';

	return 0;
}