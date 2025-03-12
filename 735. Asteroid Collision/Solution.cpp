class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;
        vector<int> result;

        for(int i = 0; i < asteroids.size(); i++){
            int rightAsteroid = asteroids[i];
            bool isDestroyed = false;

            while(!asteroidStack.empty() && rightAsteroid < 0 && asteroidStack.top() > 0){
                int leftAsteroid = asteroidStack.top();
                int direction = leftAsteroid + rightAsteroid;
                
                if(direction > 0){ //left asteroid bigger
                    isDestroyed = true;
                    break;
                }
                else if(direction < 0) // right bigger, keep checking
                {
                    asteroidStack.pop();
                }
                else { //Both equal
                    isDestroyed = true;
                    asteroidStack.pop();
                    break;
                }
            }

            if(!isDestroyed){
                asteroidStack.push(rightAsteroid);
            }

        }

        int i = asteroidStack.size() - 1;
        result = vector<int>(asteroidStack.size(), 0);
        while (i >= 0){
            result[i] = asteroidStack.top();
            asteroidStack.pop();
            i--;
        }

        return result;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
