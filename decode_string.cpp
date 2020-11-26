class Solution {
public:
    string decodeString(string s) {
        
        int number       = 0;
        int openBrackets = 0;
        
        string result = "";
        string word   = "";
        
        bool extractingWord = false;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (!extractingWord)
            {
                if (s[i] >= '0' && s[i] <= '9')
                    number = (number * 10) + (s[i] - '0');
                else if (s[i] == '[')
                {
                    openBrackets++;
                    extractingWord = true;
                }
                else
                {
                    result.push_back(s[i]);
                }
            }
            else
            {
                openBrackets += (s[i] == '[') ? 1  :
                                (s[i] == ']') ? -1 : 0;
                
                if (openBrackets != 0)
                    word.push_back(s[i]);
                
                if (openBrackets == 0)
                {
                    result.append( decodeHelper(number, word) );
                    word.clear();
                    number = 0;
                    extractingWord = false;
                }
            }
        }
        
        return result;
    }
    
private:
    
    string decodeHelper(int num, string s)
    {
        string result   = "";
        string decodedS = decodeString(s);

        for (int i = 0; i < num; i++)
        {
            result.append(decodedS);
        }
        
        return result;
    }
    
};