    #include <bits/stdc++.h>
    using namespace std;
    #define  ll long long
    #define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
    // only god know what happens in there

    vector<int> bulidPrefix(string s) {
        int n = s.size();
        vector<int> prefix(n);
        prefix[0] = 0;
        int border = 0;
        /// border is the maximum prefix = suffix   , *NOTE* // the border must be less than the whole length
        /// a b x a b y a b x a b x
        //  0 0 0 1 2 0 1 2 3 4 5 3
        for (int i = 1; i < n; i++) {
            /// i will see if i can expand from now or not !
            while (border > 0 and s[i] != s[border])
                border = prefix[border - 1];
            /// if the current char that i want to expand with not equal s[border]
            /// then i will see the prev border until i reach the 0  then break or find border = current
            /// EX : abxabxy
            // a    --> border = 0
            // a ,b --> border = 0
            // a,b,x--> border = 0
            // a b x a --> border = 1
            // a b x a b--> border = 2
            // a b x a b x-->  border = 3
            // abxabxy -- > border = 0 .
            if (s[i] == s[border])border++;
            prefix[i] = border;
        }
        return prefix;
    }

   

    int main() {
        fast;
     
 return 0;
    }


