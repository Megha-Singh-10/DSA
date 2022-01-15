6. Zigzag Conversion
/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"*/

a) TC-> O(N^2)
SC->O(N^2)

class Solution {
public:
    string convert(string s, int n) {
        int gap=n-2,j=0,l=s.size(),k=0,p,m;
         if(l==1||l==2||n>=l||n==1)
            return s;
        int x=(l%(gap+3))==0?0:1;
        m=l;//((l/(gap+3)))*(gap+1)+x;
       
        vector<vector<string>> a(n,vector<string>(m,"@"));
        string result,q;
       
       
        while(k<l)
        {
            for(int i=0;i<n;i++)
            {
                if(k==l)
                {  a[i][j]="@";
                 break;
                }
                else
                a[i][j]=s[k++];                
            }
            j++;
            int i=gap;
            for(p=0;p<gap;p++)
            {
                
                 if(k==l)
                {  a[i--][j++]="@";
                 break;
                }
                else
                a[i--][j++]=s[k++];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]!="@")
                { q=a[i][j];
                result.append(q);
                 //cout<<result<<endl;
                }
               // cout<<a[i][j]<<" ";
            }
          // cout<<endl;
        }
        return result;
        
        
    }
};

b) TC->O(N^2)
SC-> O(N)

vector<string> ans(numRows,"")

    int j=0,i=0;
    int n = s.size();
	
    while(j<n)
    {
        i=0;
        while(i<numRows && j<n)
        {
            ans[i].push_back(s[j]);
            j++;
            i++;
        }
        
        // cout<<i<<endl;
        
        i = numRows - 2;
        
        while(i>0 && j<n)
        {
            ans[i].push_back(s[j]);
            j++;
            i--;
        }
    }
    
    string str = "";
    
    for(int i=0;i<numRows;i++)
    {
        str+=ans[i];
    }
    
    return str;
// Make a vector of size of number of rows , having empty string at all index
// Start a while loop until the end of string starting from index 0
// In one iteration we have to traverse in the fashion mention below-:
// First traversal from 0 to end of the vector and adding each character of string to each index of vector
// Second traversal from end of vector (from index size-2 because we have already added element at size-1 in first traversal) till the 1st index (leaving 0th index because we'll add element to that in next iteration)

// these 2 traversal make one iteration , we'll repeat that until end of string, finally add all the strings present in the vector :)
