/**https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/ */
//You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.
//You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
//Return a list of all the recipes that you can create. You may return the answer in any order.
//Note that two recipes may contain each other in their ingredients.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findAllRecipes(char ** recipes, int recipesSize, char *** ingredients, int ingredientsSize, int* ingredientsColSize, char ** supplies, int suppliesSize, int* returnSize){
    char** arr = malloc(recipesSize * sizeof(char*));
    int i, j, k, l;
    int count = 0;
    for(i = 0; i < recipesSize; i++){
        arr[i] = malloc(100 * sizeof(char));
    }
    for(i = 0; i < recipesSize; i++){
        for(j = 0; j < ingredientsSize; j++){
            if(strcmp(recipes[i], ingredients[j][0]) == 0){
                for(k = 1; k < ingredientsColSize[j]; k++){
                    for(l = 0; l < suppliesSize; l++){
                        if(strcmp(ingredients[j][k], supplies[l]) == 0){
                            break;
                        }
                    }
                    if(l == suppliesSize){
                        break;
                    }
                }
                if(k == ingredientsColSize[j]){
                    strcpy(arr[count], recipes[i]);
                    count++;
                }
            }
        }
    }
    *returnSize = count;
    return arr;

}

    