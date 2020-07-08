/**
 * https://www.acmicpc.net/problem/2798
 * BOJ2798 - 블랙잭
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> card;
int N, M;

int solve() {
    int MIN = 987654321, size = card.size();

    for (int i = 0; i < size - 2; i++)
        for (int j = i + 1; j < size - 1; j++)
            for (int k = j + 1; k < size; k++)
                if (card[i] + card[j] + card[k] <= M)
                    MIN = MIN > M - (card[i] + card[j] + card[k])
                              ? M - (card[i] + card[j] + card[k])
                              : MIN;
    return M - MIN;
}

int main() {
    fastIO();

    cin >> N >> M;
    card.reserve(N);

    while (N--) {
        int num;
        cin >> num;
        card.push_back(num);
    }

    cout << solve() << '\n';

    return 0;
}