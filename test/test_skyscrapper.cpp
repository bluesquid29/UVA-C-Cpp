#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SkyscraperSolver {
private:
    int n;
    vector<vector<int>> grid;
    vector<int> top, bottom, left, right;
    
    // Check if placing num at (row, col) is valid
    bool isValid(int row, int col, int num) {
        // Check row
        for (int c = 0; c < n; c++) {
            if (grid[row][c] == num) return false;
        }
        // Check column
        for (int r = 0; r < n; r++) {
            if (grid[r][col] == num) return false;
        }
        return true;
    }
    
    // Count visible buildings from a vector
    int countVisible(const vector<int>& buildings) {
        int count = 0;
        int maxHeight = 0;
        for (int h : buildings) {
            if (h > maxHeight) {
                count++;
                maxHeight = h;
            }
        }
        return count;
    }
    
    // Check if current row satisfies left and right clues
    bool checkRow(int row) {
        bool rowComplete = true;
        for (int c = 0; c < n; c++) {
            if (grid[row][c] == 0) {
                rowComplete = false;
                break;
            }
        }
        
        if (!rowComplete) return true;
        
        // Check left clue
        if (left[row] != 0) {
            vector<int> buildings;
            for (int c = 0; c < n; c++) {
                buildings.push_back(grid[row][c]);
            }
            if (countVisible(buildings) != left[row]) return false;
        }
        
        // Check right clue
        if (right[row] != 0) {
            vector<int> buildings;
            for (int c = n - 1; c >= 0; c--) {
                buildings.push_back(grid[row][c]);
            }
            if (countVisible(buildings) != right[row]) return false;
        }
        
        return true;
    }
    
    // Check if current column satisfies top and bottom clues
    bool checkCol(int col) {
        bool colComplete = true;
        for (int r = 0; r < n; r++) {
            if (grid[r][col] == 0) {
                colComplete = false;
                break;
            }
        }
        
        if (!colComplete) return true;
        
        // Check top clue
        if (top[col] != 0) {
            vector<int> buildings;
            for (int r = 0; r < n; r++) {
                buildings.push_back(grid[r][col]);
            }
            if (countVisible(buildings) != top[col]) return false;
        }
        
        // Check bottom clue
        if (bottom[col] != 0) {
            vector<int> buildings;
            for (int r = n - 1; r >= 0; r--) {
                buildings.push_back(grid[r][col]);
            }
            if (countVisible(buildings) != bottom[col]) return false;
        }
        
        return true;
    }
    
    // Backtracking solver
    bool solve(int row, int col) {
        if (row == n) {
            return true; // All cells filled successfully
        }
        
        int nextRow = (col == n - 1) ? row + 1 : row;
        int nextCol = (col == n - 1) ? 0 : col + 1;
        
        for (int num = 1; num <= n; num++) {
            if (isValid(row, col, num)) {
                grid[row][col] = num;
                
                // Check constraints for completed row/column
                if (checkRow(row) && checkCol(col)) {
                    if (solve(nextRow, nextCol)) {
                        return true;
                    }
                }
                
                grid[row][col] = 0; // Backtrack
            }
        }
        
        return false;
    }
    
public:
    SkyscraperSolver(int size) : n(size) {
        grid.assign(n, vector<int>(n, 0));
        top.resize(n);
        bottom.resize(n);
        left.resize(n);
        right.resize(n);
    }
    
    void setClues(vector<int>& t, vector<int>& r, vector<int>& b, vector<int>& l) {
        top = t;
        right = r;
        bottom = b;
        left = l;
    }
    
    bool solve() {
        return solve(0, 0);
    }
    
    void printGrid() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
                if (j < n - 1) cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    
    while (cin >> n) {
        SkyscraperSolver solver(n);
        
        vector<int> top(n), right(n), bottom(n), left(n);
        
        // Read clues: top, right, bottom, left
        for (int i = 0; i < n; i++) cin >> top[i];
        for (int i = 0; i < n; i++) cin >> right[i];
        for (int i = 0; i < n; i++) cin >> bottom[i];
        for (int i = 0; i < n; i++) cin >> left[i];
        
        solver.setClues(top, right, bottom, left);
        
        if (solver.solve()) {
            solver.printGrid();
        } else {
            cout << "No solution" << endl;
        }
    }
    
    return 0;
}
