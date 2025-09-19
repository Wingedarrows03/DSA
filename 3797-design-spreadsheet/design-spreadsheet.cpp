class Spreadsheet {
private:
    vector<vector<int>> grid;
    int numRows;
    
    // Helper function to parse cell reference (e.g., "A1" -> row=0, col=0)
    pair<int, int> parseCellReference(const string& cell) {
        int col = cell[0] - 'A';  // Convert 'A'-'Z' to 0-25
        int row = stoi(cell.substr(1)) - 1;  // Convert 1-indexed to 0-indexed
        return {row, col};
    }
    
    // Helper function to get value from cell reference or integer
    int parseValue(const string& token) {
        // Check if it's a cell reference (starts with a letter)
        if (isalpha(token[0])) {
            auto [row, col] = parseCellReference(token);
            return grid[row][col];
        } else {
            // It's a number
            return stoi(token);
        }
    }
    
public:
    Spreadsheet(int rows) : numRows(rows) {
        // Initialize grid with 26 columns and specified rows, all values = 0
        grid.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [row, col] = parseCellReference(cell);
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row, col] = parseCellReference(cell);
        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        // Formula format is "=X+Y"
        // Remove the '=' at the beginning
        formula = formula.substr(1);
        
        // Find the '+' operator
        size_t plusPos = formula.find('+');
        
        // Extract X and Y
        string X = formula.substr(0, plusPos);
        string Y = formula.substr(plusPos + 1);
        
        // Parse and return the sum
        return parseValue(X) + parseValue(Y);
    }
};