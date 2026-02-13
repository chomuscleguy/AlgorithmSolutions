#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int K;
        string N;
        cin >> K >> N;

        int dec = stoi(N);

        int hex = stoi(N, nullptr, 16);

        int oct = 0;
        int valid = 1;

        for (char c : N)
        {
            if (c < '0' || c > '7')
            {
                valid = 0;
                break;
            }
        }

        if (valid)
            oct = stoi(N, nullptr, 8);

        cout << K << ' ' << oct << ' ' << dec << ' ' << hex << '\n';
    }

    return 0;
}