#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)	return a;

	return gcd(b, a % b);
}

int getArrayGcd(const vector<int>& arr) {
	int res = arr[0];

	for (int i = 1; i < arr.size(); i++)
		res = gcd(res, arr[i]);

	return res;
}

bool canDivide(const vector<int>& arr, int g) {
	for (int n : arr)
		if (n % g == 0)return true;

	return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;

	int gcd_A = getArrayGcd(arrayA);
	int gcd_B = getArrayGcd(arrayB);

	if (!canDivide(arrayB, gcd_A))
		answer = max(answer, gcd_A);

	if (!canDivide(arrayA, gcd_B)) 
		answer = max(answer, gcd_B);

	return answer;
}

int main() {
	int n;
	cin >> n;
	vector<int> arrayA(n), arrayB(n);

	for (int i = 0; i < n;i++)
		cin >> arrayA[i];
	for (int i = 0; i < n;i++)
		cin >> arrayB[i];

	cout << solution(arrayA, arrayB) << '\n';

	return 0;
}