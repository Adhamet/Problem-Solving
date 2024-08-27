class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto solve = [&](vector<int>& revisions, string version) {
            int n = version.size();
            for(int i = 0, j; i < n; i++) {
                string revision;
                j = i;
                while(j < n && version[j]!= '.') revision += version[j++];
                i = j;
                revisions.push_back(stoi(revision));
            }
        };
        
        vector<int> revisions1, revisions2;
        solve(revisions1, version1);
        solve(revisions2, version2);

        int i = 0, j = 0;
        while(i < revisions1.size() && j < revisions2.size()) {
            if(revisions1[i] > revisions2[j]) return 1;
            else if(revisions1[i] < revisions2[j]) return -1;
            i++; j++;
        }

        while(i < revisions1.size() && revisions1[i] == 0) i++;
        while(j < revisions2.size() && revisions2[j] == 0) j++;
        if(i < revisions1.size()) return 1;
        if(j < revisions2.size()) return -1;
        return 0;
    }
};
