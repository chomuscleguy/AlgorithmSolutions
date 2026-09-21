#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    int right[10001] = { 0 };
    int left[10001] = { 0 };

    int rightTopping = 0;
    int leftTopping = 0;

    for (int n : topping) {
        if (right[n] == 0) 
            rightTopping++;

        right[n]++;
    }

    for (int n : topping) {
        if (left[n] == 0) 
            leftTopping++;
        
        left[n]++;
        right[n]--;

        if (right[n] == 0)
            rightTopping--;
        

        if (leftTopping == rightTopping) 
            answer++;
    }

    return answer;
}

int main(){
    int n;
    cin >> n;

    vector<int> topping(n);

    for (int i = 0; i < n; i++)
        cin >> topping[i];

    cout << solution(topping) << '\n';

    return 0;
}

