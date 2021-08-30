
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

bool validity (string infix);


int evaluate(string infix, const bool values[], string& postfix, bool& result)
     {
         
         if (validity(infix) == false) return 1;
         
  //INFIX TO POSTFIX CONVERSION
         
         postfix = ""; //initialize postfix to empty
         stack <char> convert; //initialize operator stack to empty
         
         for(int i = 0; i < infix.length(); i++){ //loop through infix string
             
             //NEED TO CHECK IF VALID
             
             switch(infix[i]){
                     
                 case ' ': //spaces for readability
                     break;
                     
                 case '0':
                 case '1':
                 case '2':
                 case '3':
                 case '4':
                 case '5':
                 case '6':
                 case '7':
                 case '8':
                 case '9':
                     postfix += infix[i]; //append infix to postfix
                     break;
                     
                 case '(':
                     convert.push(infix[i]); //push onto stack
                     break;
                     
                 case ')':
                     while (convert.top() != '('){
                         postfix += convert.top(); //append top to postfix
                         convert.pop();
                     }
                     
                     convert.pop(); //to pop the (
                     break;
                     
                 case '&':
                 case '|':
                 case '!':
                     while (convert.empty() != true && convert.top()!= '('){
                        //chECK PRECENDENCE
                         if (infix[i] == '&'){
                             if (convert.top() == '&'|| convert.top() == '!'){ //higher or equivalent precedence
                                 postfix += convert.top();
                                 convert.pop();
                             }
                             else break; //break out of loop to push
                         }
                    
                        else if (infix[i] == '|'){
                             postfix += convert.top();
                             convert.pop();
                         }
                         
                        else if (infix[i] == '!'){
                            if (convert.top() == '!'){ //check precedence
                                postfix += convert.top();
                                convert.pop();
                            }
                            else break; //break out of loop to push
                        }
                     }
                
                     convert.push(infix[i]); //push
                     break;

             }
             
             
             
         }
         
         while (convert.empty() != true){
             postfix += convert.top(); //append the stack top to postfix
             convert.pop();
         }
         
         // EVAULATION OF POSTFIX EXPRESSION
         
         stack <bool> operand;
         for (int i = 0; i < postfix.length(); i++){
             if (isdigit(postfix[i])){
                 operand.push(values[postfix[i]-'0']); //push the value onto stack
             }
             else if (postfix[i] == '&' || postfix[i] == '|'){
                 bool operand2 = operand.top();
                 operand.pop();
                 bool operand1 = operand.top();
                 operand.pop();
                 
                 if (postfix[i] == '&'){
                     bool opresult = (operand2 && operand1);
                     operand.push(opresult);
                 }
                 if (postfix[i] == '|'){
                     bool opresult = (operand2 || operand1);
                     operand.push(opresult);
                 }
             }
            else if (postfix[i] == '!'){
                bool flip = operand.top();
                operand.pop();
                if (flip == false){
                    operand.push(true);
                }
                if (flip == true){
                    operand.push(false);
                }
            }
     }
         result = operand.top();
         return 0; //valid and set
}




bool validity (string infix){ //function to check validity of infix
    
    string newinfix = "";
    for (int i = 0; i< infix.length() ; i++){
        if (infix[i] != ' ') newinfix += infix[i]; //remove spaces
    }
    
    if (newinfix[0] == '|' || newinfix[0] == '&' || newinfix[0] == ')') return false; //invalid first characters
    if (newinfix[newinfix.length()-1] == '&' ||newinfix[newinfix.length()-1] == '|'|| newinfix[newinfix.length()-1] == '!' ||newinfix[newinfix.length()-1] == '(') return false; //invalid last characters
    
    int startparen = 0; //count parentheses
    int endparen = 0;
        
        
    for (int i = 0; i < newinfix.length() -1; i++){ //loop through characters
        if (!isdigit(newinfix[i]) && newinfix[i] != '|' && newinfix[i] != '&' && newinfix[i] != '(' && newinfix[i] != ')' && newinfix[i] != '!') return false; // general valid characters
        
        if (isdigit(newinfix[i])){
            if (isdigit(newinfix[i+1])) return false; //can't have numbers next to each other
            if (newinfix[i+1] == '(') return false;
        }
        else if (newinfix[i] == '('){
            startparen++;
            if (!isdigit(newinfix[i+1]) && newinfix[i+1]!= '!' && newinfix[i+1] != '(') return false; //only allowed characters after start parentheses
        }
        else if (newinfix[i] == ')'){ //would never be 0 index bc of earlier condition
            endparen++;
            if (!isdigit(newinfix[i-1]) && newinfix[i-1] != ')') return false; //only permitted characters before start paren
        }
        else if (newinfix[i] == '!'){
            if (!isdigit(newinfix[i+1]) && newinfix[i+1] != '(' && newinfix[i+1] != '!') return false; //valid characters after !
            if (newinfix[i+1] == '&' || newinfix[i+1] == '|') return false; //operators cannot be next to each other
        }
        else if (newinfix[i] == '&'){
            if (newinfix[i+1] == '|' || newinfix[i+1] == '&') return false;
        }
        else if (newinfix[i] == '|'){
            if (newinfix[i+1] == '|' || newinfix[i+1] == '&') return false;
        }
        
    }
    if (newinfix[newinfix.length()-1] == ')') endparen++;
    if (startparen != endparen) return false; //parentheses must be in pairs
    
    
    return true;
}







int main()
    {
     
    }
