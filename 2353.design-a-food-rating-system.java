/*
 * @lc app=leetcode.cn id=2353 lang=java
 * @lcpr version=30204
 *
 * [2353] 设计食物评分系统
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class FoodRatings {
    private Map<String, PriorityQueue<Food>> cuisineToFoods;
    private Map<String, Integer> foodToIndex;
    String[] cuisines;
    String[] foods;
    int[] ratings;
    int n;
    // Class to represent a food with its rating and name
    private class Food implements Comparable<Food> {
        String name;
        int rating;
        int index;
        
        Food(String name, int rating, int index) {
            this.name = name;
            this.rating = rating;
            this.index = index;
        }
        
        @Override
        public int compareTo(Food other) {
            if (this.rating != other.rating) {
                return other.rating - this.rating; // Higher rating first
            } 
            return this.name.compareTo(other.name); // Lexicographically smaller name first
        }
    }
    
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        n = foods.length;
        this.foods = foods;
        this.cuisines = cuisines;
        this.ratings = ratings;
        cuisineToFoods = new HashMap<>();
        foodToIndex = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Food food = new Food(foods[i], ratings[i], i);
            cuisineToFoods.computeIfAbsent(cuisines[i], k -> new PriorityQueue<>()).add(food);
            foodToIndex.put(foods[i], i);
        }
    }
    public void changeRating(String food, int newRating) {
        int index = foodToIndex.get(food);
        ratings[index] = newRating;
        Food newFood = new Food(food, newRating, index);
        cuisineToFoods.get(cuisines[index]).add(newFood);
    }
    public String highestRated(String cuisine) {
        while (!cuisineToFoods.get(cuisine).isEmpty()) {
            // top()
            Food food = cuisineToFoods.get(cuisine).peek();
            if (ratings[food.index] == food.rating) {
                return food.name;
            }
            // pop()
            cuisineToFoods.get(cuisine).poll();
        }
        return "";
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */
// @lc code=end



