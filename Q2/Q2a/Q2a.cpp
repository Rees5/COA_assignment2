#include <iostream>
#include <string>
#include <string.h>
#define TEXTTABLE_ENCODE_MULTIBYTE_STRINGS
#define TEXTTABLE_USE_EN_US_UTF8
#include "TextTable.h"
using namespace std;
//convert decimal to binary
string Binary(int num,int size) {
    string s="";
    char result[size]="";
    for (int i = size; i >= 0; i--) {
      int k = num >> i;
      if (k & 1){
        s=s+"1";
         strcpy(result,"1");
      }
      else{
        s=s+"0";
        strcpy(result,"0");
      }

    }
    return s;
}
string Hex(int decimal){
   string hex = "";
   if(decimal>0){
    while (decimal > 0) {
      int remainder = decimal % 16;
      if (remainder >= 0 && remainder <= 9)
         hex = to_string(remainder) + hex;
      else
         hex = (char)('A' + remainder % 10) + hex;
      decimal /= 16;
   }
   } else {
       hex = "0"+hex;
   }

   return hex;
}
int main() {
//intial array structure with format decimal number, number of binary bits -1
    int data[23][2] = {{0,3},{1,3}, {2,3}, {3,3},{4,3},{5,3},{6,3},{7,3},
    {8,3},{9,3},{10,3},{11,3},{12,3},{13,3},{14,3},{15,3},{16,7},{17,7},{18,7},{31,7}
    ,{100,7},{255,7},{256,11}

    };

//output
TextTable t( '-', '|', '+' );
    t.add("Decimal (Base 10)");
    t.add("Binary (Base 2)");
    t.add("Hexadecimal (Base 16)");
    t.endOfRow();

    // append records to table
    for (int i = 0; i < 23; i++)
    {
        t.add(to_string(data[i][0]));
        t.add(Binary(data[i][0],data[i][1]));
        t.add(Hex(data[i][0]));
        t.endOfRow();
    }
    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    cout<<endl;
    std::cout << t;
}
