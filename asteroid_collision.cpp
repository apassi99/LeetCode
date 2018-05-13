class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> result;
        
        for (int i = 0; i < asteroids.size(); i++) {
            if (result.empty()) {
                result.push_back(asteroids[i]);
            } else if (willNotCollide(result.back(), asteroids[i])) {
                result.push_back(asteroids[i]);
            } else {

                while(!result.empty()) {
                    
                    if (willNotCollide(result.back(), asteroids[i])) {
                        result.push_back(asteroids[i]);
                        break;
                    }
                    
                    if (abs(result.back()) < abs(asteroids[i])) {
                        result.pop_back();
                        if (result.empty()) {
                            result.push_back(asteroids[i]);
                            break;
                        }
                    } else if (abs(result.back()) == abs(asteroids[i])) {
                        result.pop_back();
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        
        return result;
    }
    
private:
    
    bool willCollide(int a1, int a2) {
        return !willNotCollide(a1, a2);
    }
    
    bool willNotCollide(int a1, int a2) {
        
        if (a1 < 0 && a2 > 0) {
            return true;
        }

        return (a1 < 0 && a2 < 0) || (a1 > 0 && a2 > 0);
    }
};