/**https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/ */
//You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.
//You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
//Return a list of all the recipes that you can create. You may return the answer in any order.
//Note that two recipes may contain each other in their ingredients.


class FindAllPossibleRecipesFromGivenSupplies {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        List<String> res = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for(int i = 0; i < recipes.length; i++){
            map.put(recipes[i], ingredients.get(i));
        }
        for(String recipe : recipes){
            if(canMake(map, recipe, new HashSet<>(Arrays.asList(supplies)))){
                res.add(recipe);
            }
        }
        return res;
        
    }
}
     
    