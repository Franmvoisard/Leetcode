# Two Sum Solution Explanation

## **Algorithm**
This solution uses a **hash map (unordered_map in C++)** to efficiently find two numbers that sum up to the given target.

### **Steps:**
1. **Initialize a hash map** (`unordered_map<int, int> map`) to store values and their corresponding indices.
2. **Iterate through the array**:
   - For each number `nums[i]`:
     - Check if it exists in the map (i.e., `map.find(nums[i]) != map.end()`).
       - If found, return the stored index and `i` as the solution.
     - Otherwise, store `target - nums[i]` as the key with `i` as the value.
3. If no solution is found after the loop, throw an exception.

## **Time and Space Complexity**
- **Time Complexity: O(N)**  
  - Each lookup and insertion operation in the hash map takes **O(1)** on average.
  - Since we traverse the list once, the overall complexity is **O(N)**.

- **Space Complexity: O(N)**  
  - In the worst case, we store **N** elements in the hash map, leading to **O(N) space usage**.

This is an **efficient one-pass solution** that finds the answer in **linear time**.
