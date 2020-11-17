class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        if (S == T)
        {
            return 0;
        }

        m_result  = INT_MAX;
        
        for (int busNumber = 0; busNumber < routes.size(); busNumber++)
        {  
            unordered_set<int> stops (routes[busNumber].begin(), routes[busNumber].end());
            m_busStopMap[busNumber] = stops;
        }

        for (int busNumber = 0; busNumber < routes.size(); busNumber++)
        {   
            for (int nextBusNumber = busNumber + 1; nextBusNumber < routes.size(); nextBusNumber++)
            {
                if (intersect(m_busStopMap[busNumber], m_busStopMap[nextBusNumber]))
                {
                    m_busGraph[busNumber].insert(nextBusNumber);
                    m_busGraph[nextBusNumber].insert(busNumber);
                }
            }
        }
        
        unordered_map<int, unordered_set<int>>::iterator it;
        for (it = m_busStopMap.begin(); it != m_busStopMap.end(); it++)
        {
            unordered_set<int> * stops = &it->second;
            
            if (stops->find(S) != stops->end())
            {
                bfs(it->first, T);
            }
        }
        
        return (m_result == INT_MAX) ? -1 : m_result;
    }
    
private:
    
    void bfs(int startBus, int endStop)
    {
        if (m_result == 1)
        {
            return;
        }

        list<int> q;
        
        q.push_back(startBus);
        
        int busesTaken = 0;
        
        while (!q.empty())
        {
            int size = q.size();
            
            busesTaken++;

            for (int i = 0; i < size; i++)
            {
                int currentBus = q.front();
                q.pop_front();
                
                // Current bus stops at endStop
                if (m_busStopMap[currentBus].find(endStop) !=
                    m_busStopMap[currentBus].end())
                {
                    m_result = min(m_result, busesTaken);
                    continue;
                }
                
                if (m_visitingNodes.find(currentBus) != m_visitingNodes.end())
                {
                    continue;
                }
                
                m_visitingNodes.insert(currentBus);
                
                unordered_set<int>::iterator it;
                for (it = m_busGraph[currentBus].begin(); it != m_busGraph[currentBus].end(); it++)
                {
                    q.push_back(*it);
                }
            }
        }
    }
    
    bool intersect(unordered_set<int> &stops1, unordered_set<int> &stops2)
    {
        unordered_set<int>::iterator it;
        for (it = stops1.begin(); it != stops1.end(); it++)
        {
            if (stops2.find(*it) != stops2.end())
            {
                return true;
            }
        }
        
        return false;
    }
    
    unordered_map<int, unordered_set<int>> m_busStopMap; // bus -> stops
    unordered_map<int, unordered_set<int>> m_busGraph; // storing bus connection
    unordered_set<int> m_visitingNodes; // keep track of cycles
    
    int m_result;
};

// stop graph
