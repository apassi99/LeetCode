class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        vector<vector<string>> result;
        vector<string> split_result;
        
        string dir = "";
        string file_name = "";
        string file_contents = "";
        string file_loc = "";
        
        map<string, vector<string>> mapFileContentsToLoc;
        
        for (int i = 0; i < paths.size(); i++) {
            split_result.clear();
            split(paths[i], " ", split_result);
            
            dir = split_result[0];
            
            for (int j = 1; j < split_result.size(); j++) {
                file_name = "";
                file_contents = "";
                file_loc = "";

                extract_file_contents(split_result[j], &file_name, &file_contents);
                
                file_loc.append(dir);
                file_loc.append("/");
                file_loc.append(file_name);
                mapFileContentsToLoc[file_contents].push_back(file_loc);
            }
            
        }
        
        map<string, vector<string>>::iterator it;

        for ( it = mapFileContentsToLoc.begin(); it != mapFileContentsToLoc.end(); it++ ) {
            if (it->second.size() > 1)
                result.push_back(it->second);
        }
        
        return result;
    }
    
private:
    
    void split(const string &s, const char* delim, vector<string> & v){
        char * dup = strdup(s.c_str());
        char * token = strtok(dup, delim);
        while(token != NULL){
            v.push_back(string(token));
            token = strtok(NULL, delim);
        }
        free(dup);
    }
    
    void extract_file_contents(string &s, string *file_name, string *file_contents) {
        
        int EXTRACT_FILE_NAME = 0;
        int EXTRACT_FILE_CONTENTS = 1;
        
        int state = EXTRACT_FILE_NAME;
        
        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == '(') {
                state = EXTRACT_FILE_CONTENTS;
                continue;
            }
            
            if (s[i] == ')') {
                break;
            }
            
            if (state == EXTRACT_FILE_NAME) {
                (*file_name) += s[i];
            } else {
                (*file_contents) += s[i];
            }
        }
    }
};