class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if (s.size() > t.size())
            return false;
        int i = 0;
        int n = s.size();
        int a = 0;
        int lastleft = -1;
        bool k = true;
        while (i < n && a < t.size()) {
            if (s[i] == t[a]||(k&&(n-i==t.size()-a))) {
                if(s[i]!=t[a])k=false;
                i++;
               
                lastleft = a;
                 a++;
            } else
                a++;
        }
        if (i == n)
            return true;
        else {
            int j = n - 1;
            int lastright = n;
            int b = n - 1;
            while (j > i && b > lastleft) {
                if (s[j] == t[b]) {
                   
                    j--;
                    lastright = b;
                     b--;
                } else
                    b--;
            }
            if (i == j+1 && lastleft < lastright )
                return true;
        }
        int j = n - 1;
        int b = t.size() - 1;
        int lastright = n;
        k = true;
        while (j >= 0 && b >= 0) {
            if (s[j] == t[b]||((k)&&j==b)) {
                if(s[j]!=t[b])k=false;
                j--;
                lastright = b;
                b--;
                
                std::cout<<b;
            } else
                b--;
        }
        if (j == -1)
            return true;
         else {
            i = 0;
            a = 0;
            lastleft = -1;
            while (i < j && a < lastright) {
                if (s[i] == t[a]) {
                    i++;
                    
                    lastleft = a;
                    a++;
                } else
                    a++;
            }
            if (i == j+1 && lastleft < lastright )
                return true;
        }
        return false;
    }
};