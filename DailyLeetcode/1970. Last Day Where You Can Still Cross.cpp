#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int Row, Col;
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<int>>& grid, int row, int col) {
        if (row >= Row || row < 0 || col >= Col || col < 0 ||
            grid[row][col] == 1) {
            return false;
        }
        if (row == Row - 1)
            return true;

        grid[row][col] = 1; // visit mark current cell

        for (auto dir : direction) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (dfs(grid, newRow, newCol))
                return true;
        }
        return false;
    }

    bool bfs(vector<vector<int>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] =
            1; // jaise hi queue mai push karo waise hi use visit mark kar do
        while (q.size() != 0) {
            auto ele = q.front();
            q.pop();
            int i = ele.first;
            int j = ele.second;
            if (i == Row - 1)
                return true;
            for (auto dir : direction) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if (new_i >= 0 && new_i < Row && new_j >= 0 && new_j < Col &&
                    grid[new_i][new_j] == 0) {
                    q.push({new_i, new_j});
                    grid[new_i][new_j] = 1;
                }
            }
        }
        return false;
    }
    bool canCross(vector<vector<int>>& cells, int mid) {
        vector<vector<int>> grid(Row, vector<int>(Col, 0));
        // mid index tak cell mai pani bar diya hai
        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        // now check from top row ki hum bottom tak pahuch paa rahe hai ya nahi
        for (int j = 0; j < Col; j++) {
            if (grid[0][j] == 0 && bfs(grid, 0, j))
                return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        Row = row;
        Col = col;
        int result = 0;
        int low = 0;
        int high = cells.size() - 1; // total days
        // optimised approach
        // mid tak grid mai pani bar diya then use BS concept able to reach from
        // top to bottom or not
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canCross(cells, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result + 1;
    }
};