class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        if (matrix.empty())
        {
            return;
        }
        
        int n = matrix.size();
        
        Coord c1, c2, c3, c4;
        
        for (int i = 0; i < n / 2; i++)
        {
            c1.i = i;
            c1.j = i;
            
            c2.i = i;
            c2.j = n - 1 - i;
            
            c3.i = n - 1 - i;
            c3.j = n - 1 - i;
            
            c4.i = n - 1 - i;
            c4.j = i;
            
            for (int j = i; j < n - 1 - i; j++)
            {
                int temp = matrix[c1.i][c1.j];

                matrix[c1.i][c1.j] = matrix[c4.i][c4.j];
                matrix[c4.i][c4.j] = matrix[c3.i][c3.j];
                matrix[c3.i][c3.j] = matrix[c2.i][c2.j];
                matrix[c2.i][c2.j] = temp;
                
                c1.j += 1;
                c2.i += 1;
                c3.j -= 1;
                c4.i -= 1;
            }
        }
    }
    
private:
    
    typedef struct
    {
        int i;
        int j;
    } Coord;
    
};