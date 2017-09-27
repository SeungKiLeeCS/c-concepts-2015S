// Name: Seung Ki Lee                                       //
// Date: 2016.05.25                                         //
// Program: leePA1-2                                        //
// Desciption: The program will print the numbers from 1 to //
// 100 and print Fizz at the multiple of 3, and Buzz at the //
// multiple of 5. For common multiples, it will say FizzBuzz//

#include <iostream>
using namespace std;

int main()
{
    for(int i=1; i<101; ++i) // loop to print out numbers from 1~100
    {
        if(i%3==0 && i%5==0) // if the number is divisible by 3&5, print FizzBuzz.
        {
            cout<<"FizzBuzz" << endl;
        }
        else if(i%3==0) // if the number is divisible by 3, print Fizz.
        {
            cout<<"Fizz" << endl; // if the number is divisible by 5, print Buzz.
        }
        else if(i%5==0)
        {
            cout<<"Buzz" << endl;
        }
        else // if the number is not divisible by either 3 or 5, print the number.
        {
            cout<<i << endl;
        }
    }
    return 0;
}

