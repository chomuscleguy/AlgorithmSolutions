#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    answer.reserve(right - left + 1);

    for (long long i = left; i <= right; ++i) 
	{
        long long row = i / n;
        long long col = i % n;

        answer.push_back(max(row, col) + 1);
    }

    return answer;
}

int main()
{
	int n;
	cin >> n;

	long long left, right;
	cin >> left >> right;

	vector<int> v = solution(n, left, right);

	for (int n : v)
		cout << n << ' ';
	cout << '\n';


	return 0;
}