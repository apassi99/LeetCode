class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        if (S == T)
        {
            return 0;
        }

        m_result  = INT_MAX;

        for (int routeNumber = 0; routeNumber < routes.size(); routeNumber++)
        {   
            for (int i = 0; i < routes[routeNumber].size(); i++)
            {
                int busStopNumber = routes[routeNumber][i];
                
                for (int j = 0; j < routes[routeNumber].size(); j++)
                {
                    if (j == i)
                    {
                        continue;
                    }
                    
                    pair<int,int> p = std::make_pair(routes[routeNumber][j], routeNumber);
                    m_stopGraph[busStopNumber].push_back(p);
                }
            }
        }
        
        //rearrange(T);
        //dfs(S, -1, S, T, 1);
        
        bfs(S, T);

        return (m_result == INT_MAX) ? -1 :  m_result;
        
    }
    
private:
    
    struct NodeData
    {
        int curStop;
        int curRoute;
        int prevRoute;
        int busesTakenSoFar;
    };
    
    void bfs(int startStop, int endStop)
    {
        list<NodeData> q;
        
        NodeData nodeData = {startStop, -1, -1, 1};
        
        q.push_back(nodeData);
        
        while (!q.empty())
        {
            int size = q.size();
            
            for (int i = 0; i < size; i++)
            {
                NodeData n = q.front();
                q.pop_front();
                
                //cout << "visiting nod: cS:  " << n.curStop 
                //     << ",  cR: " << n.curRoute 
                //     << ",  pR: " << n.prevRoute
                //     << ",  b:  " << n.busesTakenSoFar << endl;
                
                if (n.curStop == endStop)
                {
                    m_result = min(m_result, n.busesTakenSoFar);
                    m_costGraph[n.curStop] = 0;
                    continue;
                }
                
                if (m_result == 1)
                {
                    return;
                }

                if (m_visitingNodes.find(n.curStop) != m_visitingNodes.end())
                {
                    continue;
                }

                if (m_costGraph.find(n.curStop) != m_costGraph.end())
                {
                    if (n.busesTakenSoFar >= m_costGraph[n.curStop])
                    {
                        continue;
                    }
                }

                // Mark node as visiting
                m_visitingNodes.insert(n.curStop);

                // Mark busses taken to come here
                m_costGraph[n.curStop] = n.busesTakenSoFar;

                vector<pair<int,int>> nextStops = m_stopGraph[n.curStop];

                for (int i = 0; i < nextStops.size(); i++)
                {
                    NodeData nextStopNode;
                    
                    int nextStop      = nextStops[i].first;
                    int nextRoute     = nextStops[i].second;
                    bool newBusTaken  = (n.curRoute != -1) && (n.curRoute != nextRoute);
            
                    if (n.curStop == nextStop)
                    {
                        continue;
                    }

                    nextStopNode.curStop = nextStop;
                    nextStopNode.curRoute = nextRoute;
                    nextStopNode.prevRoute = n.curRoute;
                    nextStopNode.busesTakenSoFar = (newBusTaken) ? n.busesTakenSoFar + 1 : n.busesTakenSoFar;

                    //cout << "Adding route: ";
                    //cout << "cS:  " << nextStopNode.curStop  <<  ",  "
                    //     << "cR:  " << nextStopNode.curRoute <<  ",  "
                    //     << "pR:  " << nextStopNode.prevRoute << ",  "
                    //     << "b:   " << nextStopNode.busesTakenSoFar << endl;
                    
                    q.push_back(nextStopNode);
                }

                m_visitingNodes.erase(n.curStop);
            }
        }
    }

    
    void dfs(int prevStop, int curRoute, int curStop, int endStop, int busesTakenSoFar)
    {
        
        if (curStop == endStop)
        {
            m_result = min(m_result, busesTakenSoFar);
            m_costGraph[curStop] = 0;
            return;
        }

        if (m_visitingNodes.find(curStop) != m_visitingNodes.end())
        {
            return;
        }

        if (m_costGraph.find(curStop) != m_costGraph.end())
        {
            if (busesTakenSoFar >= m_costGraph[curStop])
            {
                return;
            }
        }

        // Mark node as visiting
        m_visitingNodes.insert(curStop);

        // Mark busses taken to come here
        m_costGraph[curStop] = busesTakenSoFar;
        
        vector<pair<int,int>> nextStops = m_stopGraph[curStop];
        
        for (int i = 0; i < nextStops.size(); i++)
        {
            int nextStop      = nextStops[i].first;
            int nextRoute     = nextStops[i].second;
            bool newBusTaken  = (curRoute != -1) && (curRoute != nextRoute);
            
            if (curStop == nextStop)
            {
                continue;
            }
            
            busesTakenSoFar += newBusTaken ? 1 : 0;

            dfs(curStop, nextRoute, nextStop, endStop, busesTakenSoFar);

            busesTakenSoFar -= newBusTaken ? 1 : 0;
        }
        
        m_visitingNodes.erase(curStop);
    }
    
    // hack for time on dfs
    void rearrange(int endStop)
    {
        unordered_map<int, vector<pair<int,int>>>::iterator it;
        
        for (it = m_stopGraph.begin(); it != m_stopGraph.end(); it++)
        {
            vector<pair<int,int>> *nextStops = &it->second;
            
            if (nextStops->empty())
            {
                continue;
            }
            
            int lastNotEndStopIdx = 0;
            
            for (int i = 0; i < nextStops->size(); i++)
            {
                if ( (*nextStops)[i].second == endStop)
                {
                    pair<int,int> p = (*nextStops)[lastNotEndStopIdx];
                    (*nextStops)[lastNotEndStopIdx] = (*nextStops)[i];
                    (*nextStops)[i] = p;
                    lastNotEndStopIdx++;
                    
                }
            }
        }
    }
    
    unordered_map<int, vector<pair<int,int>>> m_stopGraph; // storing stop connection
    unordered_map<int, int> m_costGraph; // memo table
    unordered_set<int> m_visitingNodes; // keep track of cycles
    
    int m_result;
};

// stop graph
