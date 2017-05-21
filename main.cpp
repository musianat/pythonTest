//DELETE ANY NODE
/*
Nathan Musial 
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
#include <LinkedList.h>
#include <DoubleLinkNode.h>
#include <BaseNode.h>

string intToString (int); // converts int to string
int StringToInt (string); // converts string to int
string ArabicToRoman(int);
bool isValidArabic(string);
bool isValidRoman(string);

int RomanToArabic(string);
string ArabicToRoman(int);
void ReadInData(LinkedList&,string);
int main()
{
    LinkedList l;

	ReadInData(l,"numbers3.txt"); //read in data to file change filename here
		//ReadInData(l,"numbers1.txt"); //read in data to file change filename here

	//PrintToScreen(head,'0');
    //ofstream output;
   // output.open("list1to4999.txt");
  //  for(int i=1;i<5000;i++)
 //   {
    //    output<<ArabicToRoman(i)<<endl;
   // }
  //  output.close();
	bool exit=false;
	//cout << endl;
	while(!exit)
    {
        //l.PrintToScreen('0');
        char i;
        string choiceMenu;

        // bool arabicVal=false;
        cout<< "Would You like to:"<< endl //menu asks user what to do
            << "1 Search" << endl
            << "2 add" << endl
            << "3 Delete first" << endl
            << "4 Delete last" << endl
            << "5 Delete specific node" << endl
            << "6 Exit" << endl;



            cin >> choiceMenu;
            if(choiceMenu.length()==1)
                i=choiceMenu[0];

        switch(i){ // menu for determing waht user wants to do

        case '1': //sorting
            {

               bool searching=true;

            while(searching) //waits for the user to enter a correct response
            {
                cout << "Please enter a roman or arabic to search for: ";
                string input;
                cin >> input;
                int arabicNum=-1;
                if(isValidRoman(input)) // if valid roman convert arabic to roman
                    arabicNum=RomanToArabic(input);
                else if(isValidArabic(input))  //if valid arabic convert to int
                    arabicNum=StringToInt(input);
                if(arabicNum!=-1)
                {
                    searching=false;
                    if(l.BinarySearchForInt(arabicNum)) // if found
                        cout  << input << " found "<< endl;
                    else
                        cout  << input << " not found " << endl;
                }
                else
                    cout<< "invalid input" << endl;
            }
            break;
        }
        case '2': //add
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
                    DoubleLinkNode* hold= new DoubleLinkNode;
                    hold->setArabic(arabicNum);
                    hold->setRoman(romanNum);// adds node
                    l.AddNode(hold);
                    l.bubbleSort();
                   // l.PrintToScreen('0');
                    //cout<<"test";


                }
                else
                    cout<< "invalid input" << endl;

            }
            break;
        }
        case '3': //add
        {
           // l.deleteFirst();
           --l;

            break;
        }
        case '4': //add
        {
           // l.deleteLast();
           l--;
            break;
        }
        case '5': //add
        {
                 bool searching=true;

            while(searching) //waits for the user to enter a correct response
            {
                cout << "Please enter a roman or arabic to delete: ";
                string input;
                cin >> input;
                int arabicNum=-1;
                if(isValidRoman(input)) // if valid roman convert arabic to roman
                    arabicNum=RomanToArabic(input);
                else if(isValidArabic(input))  //if valid arabic convert to int
                    arabicNum=StringToInt(input);
                if(arabicNum!=-1)
                {
                    searching=false;
                    if(l.BinarySearchForInt(arabicNum)) // if found
                    {
                        cout  << input << " Deleted "<< endl;
                        l.deleteNode(l.BinarySearchForInt(arabicNum));
                    }
                    else
                        cout  << input << " not found " << endl;
                }
                else
                    cout<< "invalid input" << endl;
            }
            break;
        }
		case '6': // exit chosen
		    {
		        l.PrintToFile();
                exit=true;
                break;
		    }
		default: //invalid input
		    {
                cout<< "invalid choice" << endl;
                break;
		    }
        }
    }
	//PrintToScreen(head,'0');
}

void ReadInData(LinkedList &l,string filename)
{
    //cout<<"head: "<<l.getHead()<<endl;
	string line;
	int arabic;
	string roman;
	string input;
	//int arabicConv;
	//string romanConv;
	ifstream file;
	file.open(filename); // opens input file
	if(!file) // if doesn't open
		cout<< "Error opening file";

	while(file)
	{
	  //  /*
	  line="";
		arabic=0;
		roman="";
		input="";
		bool valid=false;

			file >> input;
				getline(file,line);
				if(isValidRoman(input)) // if a valid roman numeral is read in
                {
                    roman=input;
                    arabic=RomanToArabic(input);
                    valid=true;
                    // adds node to linked list
				}
                else if(isValidArabic(input)) // if a valid arabic numeral is read in
                {
                    arabic=StringToInt(input);
                    roman=ArabicToRoman(arabic);
                    valid=true;
                     // adds node to linked list
                }
                if(valid)
                    {
                        DoubleLinkNode* hold = new DoubleLinkNode;
                        hold->setArabic(arabic);
                        hold->setRoman(roman);
                    l.AddNode(hold);
                    //cout<< arabic <<"\t"<<roman<<endl;
                    }
	}
	//cout<<"printToScreen():"<<endl;
	l.bubbleSort();
	//l.PrintToScreen('0');
	file.close();
}
string intToString (int i) // converts int to string
{
   stringstream ss;
    ss << i;
    string newstring;
    ss >> newstring;
    return newstring;
}
int StringToInt (string s) // converts string to int
{
    int val;
    stringstream ss(s);
    ss >> val;
   return val;
}
string ArabicToRoman(int num)
{
    string roman; // string used to add roman charcters to
    int thous,huns,tens,ones; // Splits arabic number by ones, tens, hundreds, thousands
    thous=num/1000;
    huns=num%1000/100;
    tens=num%1000%100/10;
    ones=num%1000%100%10;

    if(thous >0 && thous <=4){  // Adds 1 M for every thousands place
        for(int i=0;i<thous;i++)
        {
            roman += "M";
        }
    }
    if(huns > 0 && huns <= 3){ // between 0 and 3 Adds C for every hundreds
        for(int i=0;i<huns;i++)
        {
            roman += "C";
        }
    }

    else if(huns==4){ // adds CD if hundred = 4
            roman += "CD";
        }
    else if(huns==5){ // adds D if huns = 5
        roman += "D";
    }
    else if(huns >5 && huns <=8){  // between 6 and 8 Adds C after the D for every hundreds
        roman += "D";
        for(int i=6;i<=huns;i++){
            roman += "C";
        }
    }
    else if (huns==9){ // adds CM if hundreds =9
        roman += "CM";
    }

    if(tens> 0 && tens <=3){ // between 0 and 3 Adds X for every tens
        for(int i=0; i<tens;i++)
        {
            roman+= "X";
        }
    }
    else if(tens==4){ // adds XL if tens = 4
        roman+="XL";
    }
    else if(tens==5){ // adds L if tens=5
        roman+="L";
    }
    else if(tens>5 && tens <=8){  // between 6 and 8 adds X after the L for every tens
        roman+="L";
        for (int i=6;i<=tens;i++)
        {
           roman +="X";
        }
    }
    else if(tens==9){  // if tens = 9 adds XC
        roman+="XC";
    }

    if(ones >0 && ones <=3){ // between 0 and 3 Adds I for every ones
        for (int i=0;i<ones;i++)
        {
            roman += "I";
        }
    }
    else if(ones==4){ // if ones = 4 adds IV
        roman+="IV";
    }
    else if(ones==5){ // if ones =5 adds V
        roman+="V";
    }
    else if(ones > 5 && ones <=8){ // between 6 and 8 adds I after the V for every ones
        roman+="V";
        for(int i=6;i<=ones;i++)
        {
            roman += "I";
        }
    }
    else if(ones == 9){ // if ones =9 adds IX
        roman+="IX";
    }
    return roman;
}

int RomanToArabic(string rom)
 {
    int sum=0;
    for(int i=0;i<rom.length();i++)
    {
       // cout << rom <<endl;
        if(rom.at(i)=='M'){
            sum += 1000;
        }
        else if(rom.at(i)=='D'){
            sum += 500;
        }
        else if(i !=rom.length()-1 && rom.at(i)=='C' && (rom.at(i+1)=='M' || rom.at(i+1)=='D')){
            sum -= 100;
        }
        else if(rom.at(i)=='C'){
            sum += 100;
        }
        else if(rom.at(i)=='L'){
            sum += 50;
        }
        else if(i !=rom.length()-1 && rom.at(i)=='X' && (rom.at(i+1)=='L' || rom.at(i+1)=='C')){
            sum -= 10;
        }
        else if(rom.at(i)=='X'){
            sum += 10;
        }
        else if(rom.at(i)=='V'){
            sum += 5;
        }
        else if( i !=rom.length()-1 && rom.at(i)=='I' && (rom.at(i+1)=='V' || rom.at(i+1)=='X')){ //out of bound error
            sum -= 1;
        }
        else if(rom.at(i)=='I'){
            sum+=1;
        }
      //  cout << sum << "\t";
    }
   // cout <<endl;
    string sumString; // Returns the total of all of the roman numerals
	//sumString=to_string(sum); // int to string;
	return sum;


}
bool isValidArabic(string input)
{
bool    arabicVal=true;

            int arabicNum;

            for(int k=0;k<input.length();k++) //determines if what user entered is a integer
            {
                if(!(isdigit(input[k])))
                    arabicVal=false;
            }
            if(arabicVal) // if the string is all digits
                arabicNum= StringToInt(input);
            else
                return false;
           if(arabicNum>4999 || arabicNum<1) // if arabic num is not between 1 and 4999
               return false;
           else
            return true; // number is valid
}
bool isValidRoman(string input)
{
             bool romanNum=false;
                for( int i=0;i<input.length();i++)
                {
                    if(input[i]=='I' || input[i]=='V' || input[i]=='X'
                    || input[i]=='L' || input[i]=='C' || input[i]=='D'
                    || input[i]=='M' ) // if only contains roman numeral character
                    {
                         romanNum=true;
                    }
                    else
                    {
                        romanNum=false; // there is an invalid character
						break;
                        //i=input.length()-1;
                    }
                }

            if(romanNum)
                return true;
            else
                return false;
}
