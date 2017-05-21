#include "BaseNode.h"
#include <iostream>

BaseNode::BaseNode()
{
    roman="";
    arabic=0;
}
BaseNode::BaseNode(int n)

{
    arabic=n;
    roman=ArabicToRoman(n);

}
BaseNode::BaseNode(string s)
{
    roman = s;
    arabic = RomanToArabic(s);

}
BaseNode::BaseNode(const BaseNode &obj)
{
    roman=obj.roman;
    arabic=obj.arabic;

}



ostream &operator<<(ostream&strm,BaseNode &obj)
{
    strm << obj.getRoman() << "\t" << obj.getArabic();
   return strm;
}
istream &operator>>(istream&strm,BaseNode &obj)
{
   bool searching=true;
             while(searching) //waits for the user to enter a correct response
            {
                cout << "Please enter a roman or arabic to add: ";
                string input;
                cin >> input;
                int arabicNum=-1;
                string romanNum;
                bool valid=false;
                //cout<<"test";
                if(isValidRoman(input)) // if valid roman convert arabic to roman
                    {
                        valid=true;
                        arabicNum=RomanToArabic(input);
                        romanNum=input;
                    }
                else if(isValidArabic(input))  //if valid arabic convert to int
                    {
                        valid=true;
                        arabicNum=StringToInt(input);
                        romanNum=ArabicToRoman(arabicNum);

                    }
                if(valid)
                {
                    searching=false;
                    obj.setArabic(arabicNum);
                    obj.setRoman(romanNum);
                    return strm;
                }
                else
                    cout<< "invalid input" << endl;
            }
            return strm;
}
