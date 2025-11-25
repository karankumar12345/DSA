class Solution {
public:
    bool isAnagram(string s, string t) {
           
          if(s.size()!=t.size()){
            return 0;
          } 
          int count[26]={0};

          for(int i=0;i<t.size();i++){
                count[s[i]-'a']++;
                count[t[i]-'a']--;
          }
          for(int i=0;i<26;i++){
            if(count[i]!=0){
                return 0;
            }
          }
          return true;
    }
};