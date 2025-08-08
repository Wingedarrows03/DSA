class Solution {
    public double soupServings(int n) {
        // Optimization: if n is very large, the probability approaches 1
        // This is because A is more likely to be consumed faster than B
        if (n >= 4800) {
            return 1.0;
        }
        
        // Work in units of 25mL to reduce state space
        // Convert n to units of 25
        int units = (n + 24) / 25; // Ceiling division
        
        // Memoization map
        Double[][] memo = new Double[units + 1][units + 1];
        
        return solve(units, units, memo);
    }
    
    private double solve(int a, int b, Double[][] memo) {
        // Base cases
        if (a <= 0 && b <= 0) {
            // Both empty at same time - contribute 0.5 to probability
            return 0.5;
        }
        if (a <= 0) {
            // A is empty first - contribute 1 to probability
            return 1.0;
        }
        if (b <= 0) {
            // B is empty first - contribute 0 to probability
            return 0.0;
        }
        
        // Check memo
        if (memo[a][b] != null) {
            return memo[a][b];
        }
        
        double result = 0.0;
        
        // Operation 1: pour 100mL from A (4 units), 0mL from B
        result += 0.25 * solve(a - 4, b, memo);
        
        // Operation 2: pour 75mL from A (3 units), 25mL from B (1 unit)
        result += 0.25 * solve(a - 3, b - 1, memo);
        
        // Operation 3: pour 50mL from A (2 units), 50mL from B (2 units)
        result += 0.25 * solve(a - 2, b - 2, memo);
        
        // Operation 4: pour 25mL from A (1 unit), 75mL from B (3 units)
        result += 0.25 * solve(a - 1, b - 3, memo);
        
        memo[a][b] = result;
        return result;
    }
}