class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();

        unordered_set<string>s(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;

        q.push({beginWord,1});

        s.erase(beginWord); //if exists

        // tc - n * 26 * wordlength

        while(!q.empty()){
            
           string cur = q.front().first;
           int steps = q.front().second;

           q.pop();

           if(cur == endWord) return steps;

           for(int i=0;i<cur.length();i++){

            for(char ch = 'a'; ch <= 'z';ch++){
                string temp = cur;
                temp[i] = ch;

                if(s.find(temp) != s.end()){
                    q.push({temp,steps+1});
                    s.erase(temp);
                }
            }
           }
        }

        return 0;
    }
};