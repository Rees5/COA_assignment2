#include<bits/stdc++.h>
#include <iostream>
#include <string>
#define TEXTTABLE_ENCODE_MULTIBYTE_STRINGS
#define TEXTTABLE_USE_EN_US_UTF8
#include "TextTable.h"


TextTable t( '-', '|', '+' );

using namespace std;
//generate random float
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
//converting decimal to binary number
string convert_tobinary(int sn,double num, int k_prec)
{
   string binary = "";
   //getting the integer part
   int Integral = num;
   //getting the fractional part
   double fractional = num - Integral;
   string flag = "Approximate";
   //converting integer to binary
   while (Integral)
   {
      int rem = Integral % 2;
      binary.push_back(rem +'0');
      Integral /= 2;
   }
   //reversing the string to get the
   //required binary number
   reverse(binary.begin(),binary.end());
   binary.push_back('.');
   //converting fraction to binary
   while (k_prec--)
   {
      fractional *= 2;
      if(fractional ==1.0){
          flag="Exact";

      }
      int fract_bit = fractional;
      if (fract_bit == 1)
      {
         fractional -= fract_bit;
         binary.push_back(1 + '0');
      }
      else
      binary.push_back(0 + '0');
   }
    string str=to_string(num);
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
    t.add(to_string(sn));
    t.add(str);
    t.add(binary);
    t.add(flag);
    t.endOfRow();
   return binary;
}

int main()
{
    srand(static_cast<int>(time(0)));
    const double arrayNum[3] = {0.01, 0.01,0.001};
    t.add("S/No.");
    t.add("Decimal Number");
    t.add("Binary Number");
    t.add("Remarks");
    t.endOfRow();

    //default values
    convert_tobinary(1,11.81, 5);
    convert_tobinary(2,21.25, 2);
    //auto generated values
	for(int i=2;i<30;i++){
        int RandIndex = rand() % 3;
        int stdpc= (rand() % 4) + 2;
        double sc =  arrayNum[RandIndex];
	    double x=(int)(fRand(1.25,119.5)/sc)*sc;
	    convert_tobinary(i+1,x, stdpc);
	}
	std::cout << t;
   return 0;
}
