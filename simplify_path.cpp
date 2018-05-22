class Solution {
public:
    string simplifyPath(string path) {

        string result = "";
        string cur_dir = "";

        list<string> * stk = new list<string>();

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/' || i == path.size() - 1) {
                if (path[i] != '/') {
                    cur_dir += path[i];
                }
                if (cur_dir == "..") {
                    if (!stk->empty())
                        stk->pop_back();
                } else if (cur_dir != "." && cur_dir != "") {
                    stk->push_back(cur_dir);
                }
                cur_dir = "";
            } else {
                cur_dir += path[i];
            }
        }

        while (!stk->empty()) {
            result += "/" + stk->front();
            stk->pop_front();
        }
        
        if (result == "")
            result = "/";

        delete stk;
        return result;
    }
};