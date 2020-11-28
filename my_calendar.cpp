class MyCalendar {
public:
    MyCalendar() {
        m_root = NULL;
    }
    
    bool book(int start, int end) {
        
        Interval newInterval = {start, end};

        if (search(m_root, newInterval))
        {
            return false;
        }
        
        m_root = insert(m_root, newInterval);
        
        return true;
    }
    
private:
    
    struct Interval
    {
        int start;
        int end;
        
        bool operator>(const Interval &rhs)
        {
            return start >= rhs.end;
        }
        bool operator<(const Interval &rhs)
        {
            return end <= rhs.start;
        }
    };
    
    typedef struct Interval Interval;
    
    struct TreeNode
    {
        Interval interval;
        struct TreeNode * left;
        struct TreeNode * right;
    };
    
    typedef struct TreeNode TreeNode;
    
    TreeNode * m_root;
    
    // Note: Can make this insert re-balance the search tree 
    //       ( AVL implementation)
    TreeNode * insert(TreeNode * n, Interval &interval)
    {
        if (!n)
        {
            n = new TreeNode;
            n->interval = interval;
            n->left = NULL;
            n->right = NULL;
            return n;
        }
        
        if (interval > n->interval)
            n->right = insert(n->right, interval);
        else if (interval < n->interval)
            n->left = insert(n->left, interval);
        
        return n;
    }
    
    bool search(TreeNode * n, Interval &interval)
    {
        if (!n)
            return false;
        
        if (interval > n->interval)
            return search(n->right, interval);
        else if (interval < n->interval)
            return search(n->left, interval);
        else
            return true;
    }
    
    void print(TreeNode * n)
    {
        if (!n)
            return;
        
        print(n->left);
        cout << "[" << n->interval.start << ",  " << n->interval.end << "],  ";
        print(n->right);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */