#https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
#You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.
#You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
#Return a list of all the recipes that you can create. You may return the answer in any order.
#Note that two recipes may contain each other in their ingredients.


class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """      
        from collections import Counter
        supplies = Counter(supplies)
        result = []
        for i, recipe in enumerate(recipes):
            if all(supplies[ingredient] > 0 for ingredient in ingredients[i]):
                result.append(recipe)
                for ingredient in ingredients[i]:
                    supplies[ingredient] -= 1
        return result
        

    