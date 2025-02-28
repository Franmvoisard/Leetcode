# **Analysis of Pascal's Triangle Implementations**

## **Overview**
This document compares two implementations of generating Pascal’s Triangle:
1. **Original Implementation** (Uses a 2D vector to store all rows explicitly).
2. **Alternative Implementation** (Constructs rows directly but still stores all rows).
3. **Truly Optimized Implementation** (Only stores one row at a time, reducing space complexity to O(numRows)).

We will analyze their differences, identify patterns, and discuss time and space complexity.

---

## **Original Implementation**
### **How It Works**
- Initializes a 2D vector (`results`) to store all rows of Pascal’s Triangle.
- Iterates `numRows` times, generating each row based on the previous row.
- Uses a helper function (`calculateRowValues`) to compute new rows.
- Each row is stored explicitly, leading to **O(numRows²) space complexity**.

### **Complexity Analysis**
- **Time Complexity:** O(numRows²) (Each row takes O(i) operations, summing to O(numRows²)).
- **Space Complexity:** O(numRows²) (Stores all rows in memory).

---

## **Alternative Implementation (Single Vector Per Row but Stores All Rows)**
### **How It Works**
- Uses a **single vector per row** to construct each row in-place.
- Iterates `numRows` times, updating the vector from right to left.
- Stores all generated rows in `results`, meaning the final output still requires **O(numRows²) space**.

### **Code Snippet (Alternative Approach)**
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // Initialize row with 1s
            
            for (int j = i - 1; j > 0; j--) { // Update row in reverse to avoid overwriting
                row[j] = results[i - 1][j - 1] + results[i - 1][j];
            }
            
            results.push_back(row);
        }
        
        return results;
    }
};
```

### **Complexity Analysis**
- **Time Complexity:** O(numRows²) (Same as original, as we still compute all values).
- **Space Complexity:** O(numRows²) (Stores all rows, just like the original implementation).

---

## **Truly Optimized Implementation (Only One Row Stored at a Time)**
### **How It Works**
- Instead of storing all rows, it **only keeps the current row**.
- Updates values **in-place** from right to left to prevent overwriting important data.
- Achieves **O(numRows) space complexity**, as it does not retain previous rows.

### **Code Snippet (Optimized Space Approach)**
```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }
        
        return row;
    }
};
```

### **Complexity Analysis**
- **Time Complexity:** O(numRows²) (We still iterate through all elements).
- **Space Complexity:** O(numRows) (Only one row is stored at a time).

---

## **Key Differences and Insights**
| Aspect                 | Original Implementation            | Alternative Implementation        | Truly Optimized Implementation  |
|------------------------|----------------------------------|----------------------------------|----------------------------------|
| **Approach**          | Uses a 2D vector to store all rows | Constructs each row independently but still stores all | Stores only one row, updating in-place |
| **Memory Usage**      | O(numRows²) (Stores all rows)    | O(numRows²) (Stores all rows)    | O(numRows) (Only keeps the latest row) |
| **Performance**       | O(numRows²) time, high memory usage | O(numRows²) time, slightly better memory handling | O(numRows²) time, lowest memory usage |
| **Code Simplicity**   | Uses an extra function to compute rows | Directly modifies rows inline | Minimal storage, in-place updates |

### **Pattern Observed**
- The key to optimizing Pascal’s Triangle generation is **reducing memory usage** while maintaining the same computational logic.
- The **truly optimized approach** only keeps the latest row, achieving **O(numRows) space complexity**.
- This is achieved by updating values **in reverse order**, ensuring no data is overwritten prematurely.

---

## **Conclusion**
- **Original Implementation** is straightforward but **memory-intensive**.
- **Alternative Implementation** improves row construction efficiency but still **stores all rows**, so its space complexity remains **O(numRows²)**.
- **Truly Optimized Implementation** minimizes memory usage to **O(numRows) space**, making it the best choice when only a single row is needed.

🚀 **Optimization Lesson:** If all rows are required, both the original and alternative implementations have the same complexity. However, when only a specific row is needed, using **O(numRows) space** is the most efficient choice!

