#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
    bool magicSquare(vector<vector<int>>& grid, int sr, int sc) {
        int sumRef = 0;
        // took first row as reference sum
        for (int j = sc; j < sc + 3; j++) {
            sumRef += grid[sr][j];
        }
        // calculating and matching the sum of rest rows with refrowsum
        for (int i = sr + 1; i < sr + 3; i++) {
            int sumRow = 0;
            for (int j = sc; j < sc + 3; j++) {
                sumRow += grid[i][j];
            }
            if (sumRow != sumRef)
                return false;
        }
        // calculating and matching the sum of  cols with refrowsum
        for (int j = sc; j < sc + 3; j++) {
            int sumCol = 0;
            for (int i = sr; i < sr + 3; i++) {
                sumCol += grid[i][j];
            }
            if (sumCol != sumRef)
                return false;
        }
        // calculating and matching the sum of  diags with refrowsum
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < 3; i++) {
            diag1 += grid[sr + i][sc + i];
            diag2 += grid[sr + i][sc + 2 - i];
        }
        if (diag1 != sumRef || diag2 != sumRef)
            return false;

        unordered_set<int> st;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (grid[i][j] > 9 || grid[i][j] == 0)
                    return false;
                st.insert(grid[i][j]);
            }
        }
        if (st.size() != 9)
            return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;
        if (rows < 3 || cols < 3)
            return 0;
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (magicSquare(grid, i, j))
                    result += 1;
            }
        }
        return result;
    }
int main(){

}
