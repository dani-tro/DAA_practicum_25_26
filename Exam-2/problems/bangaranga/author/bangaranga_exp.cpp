#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, t;
int mat[505][505];
bool visited[505][505];
int min_time = INF;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int steps, int current_time) {
    if (current_time >= min_time) return;

    if (r == n && c == n) {
        min_time = min(min_time, current_time);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && !visited[nr][nc]) {
            visited[nr][nc] = true;
            
            int next_time = current_time + t;
            if ((steps + 1) % 3 == 0) {
                next_time += mat[nr][nc]; 
            }

            dfs(nr, nc, steps + 1, next_time);
            
            visited[nr][nc] = false; 
        }
    }
}

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];

    visited[1][1] = true;
    dfs(1, 1, 0, 0);

    cout << min_time << "\n";
    return 0;
}
