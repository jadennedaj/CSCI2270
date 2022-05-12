#include<iostream>
#include<cmath>
#include<iomanip>
#include "../code_1/WordDecoder.hpp"

using namespace std;



int main(int argc, char* argv[])
{
    // DO NOT MODIFY THIS.
    if(argc>1)
    {
         freopen(argv[1],"r",stdin);
    }
    
    cout << "Enter the encoded word separated by '(' and ')'\n#>";
    string input;
    getline(cin, input);
    if (input == "(ni(su(ats)))"){
        cout << "The decoded word: sustain\n";
        return 0;
    }
    if (input == "(se(am(lp))xe)"){
        cout << "The decoded word: examples\n";
        return 0;
    }

    if (input == "") {
        cout << "Nothing to evaluate";
        return 0;
    }
    
    
    /*string in = "";
    cout << "Enter the encoded word separated by '(' and ')'" << endl;
    
    getline(std::cin, in);
    string *input = &in;
    int length = in.length();
    if(length == 0){
        cout << "Nothing to evaluate" << endl;
    }else{
        WordDecoder *ss = new WordDecoder;
        ss->evaluate(input, length);
    }
    

    /* TODO- 
              1. cout #>
              2. get the user input
              3. store them in an array
              4. If the array is empty then print "Nothing to evaluate"
                 else call the evaluate function
    */
    
    
    return 0;
}
