class Solution {
public:
    bool isValid(string str) {
        stack<char> ch;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            ch.push(str[i]);
        } else {
            if(ch.size() == 0){
                return false;
            }

            if((ch.top() == '(' && str[i] == ')') ||
                (ch.top() == '{' && str[i] == '}') ||
                (ch.top() == '[' && str[i] == ']')){
                    ch.pop();
                } else {
                    return false;
                }
        }
    }

    return (ch.size() == 0);
    }
};