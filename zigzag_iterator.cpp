class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // do intialization if necessary
        m_v1 = v1;
        m_v2 = v2;
        m_idx1 = 0;
        m_idx2 = 0;
        flag = true;
    }

    /*
     * @return: An integer
     */
    int next() {
        // write your code here
        int val;

        if (!hasNext())
            return -1;

        if (m_idx1 >= m_v1.size())
            flag = false;
        else if (m_idx2 >= m_v2.size())
            flag = true;

        val  = (flag) ? m_v1[m_idx1++] : m_v2[m_idx2++];
        flag = !flag;

        return val;

    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here
        return m_idx1 < m_v1.size() || m_idx2 < m_v2.size();
    }

private:

    vector<int> m_v1;
    vector<int> m_v2;

    int m_idx1;
    int m_idx2;
    bool flag;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */