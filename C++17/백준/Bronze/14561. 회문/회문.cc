#include <iostream>
#include <vector>

using namespace std;

bool IsPalindrome(long long A, int n)
{
	vector<long long> digits;

	if (A == 0)
		return 1;

	while (A > 0)
	{
		digits.push_back(A % n);
		A /= n;
	}

	int size = digits.size();

	for (int i = 0; i < size / 2; i++)
		if (digits[i] != digits[size - 1 - i])
			return 0;

	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		long long A;
		int n;
		cin >> A >> n;

		cout << IsPalindrome(A, n) << "\n";
	}

	return 0;
}