#include <iostream>

using namespace std;

void initializeTensMap(string tensMap[]){
    tensMap[0] = "zero";
    tensMap[1] = "ten";
    tensMap[2] = "twenty";
    tensMap[3] = "thirty";
    tensMap[4] = "fourty";
    tensMap[5] = "fifty";
    tensMap[6] = "sixty";
    tensMap[7] = "seventy";
    tensMap[8] = "eighty";
    tensMap[9] = "ninety";
}
void initializeUnitMap(string unitMap[]){
    unitMap[0] = "zero";
    unitMap[1] = "one";
    unitMap[2] = "two";
    unitMap[3] = "three";
    unitMap[4] = "four";
    unitMap[5] = "five";
    unitMap[6] = "six";
    unitMap[7] = "seven";
    unitMap[8] = "eight";
    unitMap[9] = "nine";
    unitMap[10] = "ten";
    unitMap[11] = "eleven";
    unitMap[12] = "twelve";
    unitMap[13] = "thirteen";
    unitMap[14] = "fourteen";
    unitMap[15] = "fifteen";
    unitMap[16] = "sixteen";
    unitMap[17] = "seventeen";
    unitMap[18] = "eighteen";
    unitMap[19] = "nineteen";
}
string numberToWords(int number){
    string words;
    string unitMap[20];
    string tensMap[10];
    words = "";
    if ((int)((double)number / 1000000) > 0) {
        words += numberToWords((int)((double)number / 1000000))+" million ";
        number %= 1000000;
    }
    if ((int)((double)number / 1000) > 0) {
        words += numberToWords((int)((double)number / 1000))+" thousand ";
        number %= 1000;
    }
    if ((int)((double)number / 100) > 0) {
        words += numberToWords((int)((double)number/100))+" hundred ";
        number %= 100;
    }
    if (number > 0) {
        if (words != "") words = words + " and ";
        initializeUnitMap(unitMap);
        initializeTensMap(tensMap);
        if (number < 20) words += unitMap[number];
        else {
            words += tensMap[(int)((double)number / 10)];
            if (number % 10 > 0) words += "-" + unitMap[number % 10];            
        }
    }
    return words;
}

int main(int argc, char** argv) {
	unsigned int number=0;cout<<"Input number = ";cin>>number;
	if(number == 0) cout<<endl<<"Your number is Zero"<<endl;
	else cout<<endl<<"Your number is "<<numberToWords(number)<<endl;
	return 0;
}
