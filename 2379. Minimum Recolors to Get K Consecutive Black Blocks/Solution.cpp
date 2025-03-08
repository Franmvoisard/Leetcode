class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int minRequiredOperations = 0;
        int currentWindowRequiredOperations = 0;
        
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W') currentWindowRequiredOperations++;
        }
        minRequiredOperations = currentWindowRequiredOperations;

        for(int i = k; i < blocks.size(); i++){
            if(blocks[i-k] == 'W') currentWindowRequiredOperations--;
            if(blocks[i] == 'W') currentWindowRequiredOperations++;
        
            minRequiredOperations = min(minRequiredOperations, currentWindowRequiredOperations);
        }
        return minRequiredOperations;
    }
};
