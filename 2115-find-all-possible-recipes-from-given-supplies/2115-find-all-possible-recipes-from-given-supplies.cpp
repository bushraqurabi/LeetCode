class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supplySet(supplies.begin(), supplies.end());

        
        vector<string> possibleRecipes;

        
        for (int i = 0; i < recipes.size(); i++) {
            bool canMake = true;

            
            for (const string& ingredient : ingredients[i]) {
                if (supplySet.find(ingredient) == supplySet.end()) {
                    canMake = false;
                    break;
                }
            }

            
            if (canMake) {
                possibleRecipes.push_back(recipes[i]);
                
                supplySet.insert(recipes[i]);
            }
        }

        return possibleRecipes;
    }
};
