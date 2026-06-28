class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        summing the ASCII values of characters. This is insufficient because different sets of characters can result in the same sum (e.g., 'f'+'e' is 102+101=203, and 'j'+'a' is 106+97=203).
        To fix this while keeping your structure minimal:

        I added a second tracking variable squares to track the sum of the squares of the ASCII values.
        */
        long long c = 0;
        long long squares = 0;
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0;i<s.length() && i<t.length();i++){
            c+= static_cast<int>(s[i]);
            c-= static_cast<int>(t[i]);
            squares += (long long)s[i] * s[i];
            squares -= (long long)t[i] * t[i];
        }
        if(c==0 && squares == 0){
            return true;
        }
        else{
            return false;
        }
    }
};