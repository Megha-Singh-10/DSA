151. Reverse Words in a String
/* Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.*/

a) TC-> O(N*N)
SC->O(N)

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string result;
        int start,end;
        end=n-1;
        string sub="";
        cout<<"hi\n"<<n<<endl;
        while(n!=0 && end>=0)
        {
          
            while(s[end]==' ' && end>0)
                end--; 
             if(end==0 && s[end]==' ')
               break;
             cout<<"end "<<end<<" start ";
            start=end;
            
            while(s[start]!=' ' && start>0)
                start--;
            cout<<start<<endl;
            if(start==0 && s[start]!=' ')
             sub=s.substr(start,end-start+1);
            else
             sub=s.substr(start+1,end-start);        
            cout<<sub<<"\n";
            if(result.size()==0)
            result.append(sub);
            else
                result.append(" "+sub);
            end=start-1;
            n--;
        }
        cout<<result<<endl;
        return result;
    }
};

b) Solution 2: Reverse whole string then reverse word by word - O(1) in Space Complexity

Reverse the whole string.
Then we iterate characters in string s, fill found word into s then reverse it, word by word.
Let l keep the starting index of the current word, r keep the next index for filling the current word.
Reverse the current word, which is s[l..r-1]
Set space character for character s[r] if r < s.size()
Finally, resize the string s to remove redundant chars.
image

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};

Complexity

Time: O(N), where N <= 10^4 is length of string s.
Space: O(1)