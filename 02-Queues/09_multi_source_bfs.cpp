
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid grid size\n";
        return 0;
    }

    vector<vector<int>> grid(rows, vector<int>(cols));
    queue<pair<int, int>> q;
    int fresh = 0;

    cout << "Enter grid (0=empty, 1=fresh, 2=infected):\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> grid[r][c];

            if (grid[r][c] < 0 || grid[r][c] > 2) {
                cout << "Invalid cell value\n";
                return 0;
            }

            if (grid[r][c] == 2)
                q.push({r, c});
            else if (grid[r][c] == 1)
                fresh++;
        }
    }

    int minutes = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty() && fresh > 0) {
        int levelSize = q.size();
        bool spread = false;

        for (int i = 0; i < levelSize; i++) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                    spread = true;
                }
            }
        }

        if (spread)
            minutes++;
    }

    if (fresh > 0)
        cout << "Some cells cannot be infected\n";
    else
        cout << "Minimum time: " << minutes << " minute(s)\n";

    return 0;
}
