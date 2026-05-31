#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
int n, t;
int mat[505][505];
int dist[505][505];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct State {
    int time, r, c, steps;
    bool operator>(const State& other) const {
        return time > other.time;
    }
};

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            dist[i][j] = INF;
        }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1, 1, 0});
    dist[1][1] = 0;

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        if (curr.time > dist[curr.r][curr.c]) continue;

        if (curr.r == n && curr.c == n) {
            cout << curr.time << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
                int next_time = curr.time + t;
                if ((curr.steps + 1) % 3 == 0) {
                    next_time += mat[nr][nc];
                }

                if (next_time < dist[nr][nc]) {
                    dist[nr][nc] = next_time;
                    pq.push({next_time, nr, nc, curr.steps + 1});
                }
            }
        }
    }
    return 0;
}
