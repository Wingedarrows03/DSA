#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class MovieRentingSystem {
private:
    // Map from movie ID to set of (price, shop) for unrented movies
    unordered_map<int, set<pair<int, int>>> unrentedByMovie;
    
    // Set of (price, shop, movie) for all rented movies
    set<tuple<int, int, int>> rentedMovies;
    
    // Map from (shop, movie) to price for quick lookup
    unordered_map<int, unordered_map<int, int>> shopMoviePrice;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1]; 
            int price = entry[2];
            
            // Store price for quick lookup
            shopMoviePrice[shop][movie] = price;
            
            // Add to unrented movies (sorted by price, then shop)
            unrentedByMovie[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        
        if (unrentedByMovie.find(movie) == unrentedByMovie.end()) {
            return result; // Empty list if movie not found
        }
        
        auto& movieSet = unrentedByMovie[movie];
        int count = 0;
        
        for (auto& pair : movieSet) {
            if (count >= 5) break;
            result.push_back(pair.second); // Add shop ID
            count++;
        }
        
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        
        // Remove from unrented
        unrentedByMovie[movie].erase({price, shop});
        
        // Add to rented (sorted by price, shop, movie)
        rentedMovies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        
        // Remove from rented
        rentedMovies.erase({price, shop, movie});
        
        // Add back to unrented
        unrentedByMovie[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        
        for (auto& tuple : rentedMovies) {
            if (count >= 5) break;
            int price = get<0>(tuple);
            int shop = get<1>(tuple);
            int movie = get<2>(tuple);
            result.push_back({shop, movie});
            count++;
        }
        
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */