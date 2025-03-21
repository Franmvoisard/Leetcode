class Solution {

private:
    unordered_map<string, bool> can_cook;
    unordered_map<string, int> recipe_index;

    void initialize_available_recipes(vector<string>& supplies){
        for(const auto& supply : supplies) {
            can_cook[supply] = true;
        }
    };

    void initialize_recipe_index(vector<string>& recipes){
         for(int i = 0; i < recipes.size(); i++) {
            recipe_index[recipes[i]] = i;
        }
    }
    
    bool dfs(string recipe, vector<vector<string>>& ingredients){
        if (can_cook.contains(recipe)) return can_cook[recipe];
        if (!recipe_index.contains(recipe)) return false;

        can_cook[recipe] = false;

        for(const auto& neighbor : ingredients[recipe_index[recipe]]){
            if(!dfs(neighbor, ingredients)) return false;
        }

        can_cook[recipe] = true;
        return can_cook[recipe];
    };
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        initialize_available_recipes(supplies);
        initialize_recipe_index(recipes);
        vector<string> result;

        for(const auto& recipe : recipes){
            if(dfs(recipe, ingredients)) result.push_back(recipe);
        }
        return result;
    }
};
