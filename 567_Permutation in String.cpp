class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;
        vector<int> count1(26,0); //26個位置，每個位置的初始值都填0
        vector<int> count2(26,0);

        //先統計s1全部，以及s2的前s1個字元
        for (int i = 0;i < s1.length();i++)
        {
            count1[s1[i]-'a']++; //利用減去 'a' 對應到 0-25(ASCII編碼中，a-z是連續排列的)
            count2[s2[i]-'a']++;
        }
        if (count1 == count2)
            return true;
        for (int i = s1.length();i < s2.length();i++)
        {
            count2[s2[i]-'a']++;
            count2[s2[i-s1.length()]-'a']--;
            if (count1 == count2)
                return true;
        }
        return false;
    }
};