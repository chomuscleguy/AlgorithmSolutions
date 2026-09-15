#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
	vector<int> answer;

	int days = (100 - progresses[0] + speeds[0] - 1) / speeds[0];
	int count = 1;

    for (int i = 1; i < progresses.size(); i++)
    {
        int cur = (100 - progresses[i] + speeds[i] - 1) / speeds[i];

        if (cur <= days)
            count++;
        else
        {
            answer.push_back(count);
            count = 1;
            days = cur;
        }
    }

    answer.push_back(count);

    return answer;
}

int main()
{
	int n;
	cin >> n;

	vector<int> progress(n);
	vector<int> speed(n);

	for (int i = 0; i < n; i++)
		cin >> progress[i];

	for (int i = 0; i < n; i++)
		cin >> speed[i];

	for (int n : solution(progress, speed))
		cout << n << ' ';

	return 0;
}