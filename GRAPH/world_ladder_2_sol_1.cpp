class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        int level=0;
        vector<string>used_on_level;
        used_on_level.push_back(beginWord);
        vector<vector<string>>ans;

        while (!q.empty())
        {
            vector<string>vec= q.front();
            q.pop();
            //Erease all the word that has been used in the prev level to transform
            if (vec.size()>level)
            {
                level++;
                for(auto it:used_on_level)
                {
                    st.erase(it);
                }
            }

            string word=vec.back();
            if(word==endWord)
            {
                if(ans.size()==0) ans.push_back(vec);
                else if(ans[0].size()==vec.size()) ans.push_back(vec);
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        vec.push_back(word);
                        q.push(vec);
                        //Mark as visited on the level
                        used_on_level.push_back(word);
                        vec.pop_back();
                    }
                }
                
                word[i] = original;
            }
        }
        return ans;
    }
};