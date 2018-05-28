class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        
        for (int i = 0; i < vec2d.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < vec2d[i].size(); j++) {
                temp.push_back(vec2d[i][j]);
            }
            m_Vec2d.push_back(temp);
        }
        
        m_I = 0;
        m_J = 0;
    }

    int next() {
        int value = m_Vec2d[m_I][m_J];
        
        if (m_J == m_Vec2d[m_I].size() - 1) {
            m_I++;
            m_J = 0;
        } else {
            m_J++;
        }
        
        return value;
    }

    bool hasNext() {
        // Write your code here
        if (m_I >= m_Vec2d.size())
            return false;

        if (m_J >= m_Vec2d[m_I].size() && m_I == m_Vec2d.size() - 1)
            return false;
            
        return true;
    }
    
private:

    vector<vector<int>> m_Vec2d;
    
    int m_I;
    int m_J;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */