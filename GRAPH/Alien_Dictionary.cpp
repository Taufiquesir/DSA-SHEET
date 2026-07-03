class Solution
{
public:
    bool make_graph(string &s1, string &s2, vector<vector<int>> &adj, vector<int> &indeg)
    {
        int mini = min(s1.size(), s2.size());
        for (int i = 0; i < mini; i++)
        {
            if (s1[i] != s2[i])
            {
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                indeg[s2[i] - 'a']++;
                return true;
            }
        }
        // Invalid case: longer word comes before its prefix
        if (s1.size() > s2.size())
            return false;
        return true;
    }

    string findOrder(vector<string> &words)
    {
        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        vector<bool> present(26, false);
        // Mark all characters that appear
        for (auto &word : words)
        {
            for (char c : word)
                present[c - 'a'] = true;
        }
        // Build graph
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!make_graph(words[i], words[i + 1], adj, indeg))
                return "";
        }

        queue<int> q;

        int totalChars = 0;

        for (int i = 0; i < 26; i++)
        {
            if (present[i])
            {
                totalChars++;
                if (indeg[i] == 0)
                    q.push(i);
            }
        }

        string ans = "";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');
            for (int it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        // Cycle exists
        if (ans.size() != totalChars)
            return "";

        return ans;
    }
};