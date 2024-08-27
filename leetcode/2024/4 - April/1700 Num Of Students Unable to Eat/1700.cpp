class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cs_count = 0;
        int ss_count = 0;

        for (int student : students) {
            if (student == 0) cs_count++;
            else ss_count++;
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0 && cs_count == 0) return ss_count; 
            if (sandwich == 1 && ss_count == 0) return cs_count;
            if (sandwich == 0) cs_count--;
            else ss_count--;
        }

        return 0;
    }
};
