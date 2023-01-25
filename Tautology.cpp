#include <bits/stdc++.h>

using namespace std;

#define C(a, b) (a & b)
#define D(a, b) (a | b)
#define I(a, b) (!a | b)
#define E(a, b) (!(a ^ b))
#define N(a)    (!a)

void solve() 
{
    string s;
    cin >> s;
    
    int var[26];
    for(int i = 0; i < 26; i++) var[i] = -1;
    
    int n = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] >= 'a' && var[s[i] - 'a'] == -1)
        {
            var[s[i] - 'a'] = n ++;
        }
    }
    
    int val[n];
    
    for(int i = 0; i < (1 << n); ++i)
    {
        for(int j = 0; j < n ; ++j)
            val[j] = (i >> j) & 1;
            
        std::stack<int> st;
        
        for(int k = s.size()-1; k >= 0; --k)
        {
            if(s[k] >= 'a')
            {
                st.push(val[var[s[k] - 'a']]);
                
                continue;
            }
            
            int val1 = st.top();
            st.pop();
            int val2;

            switch(s[k])
            {
            case 'C':
                val2 = st.top();
                st.pop();
                st.push(C(val1, val2));
                break;
            case 'D':
                val2 = st.top();
                st.pop();
                st.push(D(val1, val2));
                break;
            case 'I':
                val2 = st.top();
                st.pop();
                st.push(I(val1, val2));
                break;
            case 'E':
                val2 = st.top();
                st.pop();
                st.push(E(val1, val2));
                break;
            case 'N':
                st.push(N(val1));
                break;
            default:
                break;
            }
        }
        
        if(st.top() == 0)
        {
            cout <<"NO\n";
            return;
        }
    }
    
    cout << "YES\n";
    return;
}

int main() {
    int T;
    cin >> T;
    
    while(T --)
        solve();

	return 0;
}