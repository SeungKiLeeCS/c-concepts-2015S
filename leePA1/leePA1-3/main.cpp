// Name: Seung Ki Lee                                       //
// Date: 2016.05.25                                         //
// Program: leePA1-3                                        //
// Desciption: The program will use loops to display three  //
// distinct figures with input height value. It will ask to //
// try again if the number is outside the range 4~10        //

#include <iostream>
using namespace std;

//prototypes for functions used in program.

void trapezoid(int height);
void triangle(int height);
void parallelogram(int height);

int main()
{
    int height = 0;
    bool flag = true;// boolean used for loop of error message.
    do
    {
    cout <<"Please choose a number from 4 to 10.";
    cin >> height;

    if(height >=4 && height <= 10) // setting range of 4~10 for the input value.
    {

    flag = false;

    //call functions for each shapes.

    trapezoid (height);
    cout<<"\n";

    triangle (height);
    cout<<"\n";

    parallelogram (height);
    }

    else
    {
        cout<<"The number is out of range. Please choose an integer ranging from 4 to 10."; //error message printed if the number entered is not within the range of 4~10.
    }
    }while(flag != false);
        return 0;
}


void trapezoid (int height)
{
   int row, col;
   for (row = 0; row < height; row++)
   {
      for (col = height - row; col > 0; col--)
      {
         cout << " "; // print blank spaces for incline or the left edge of trapezoid.
      }
      for (col = 0; col < height + 2 * row; col++)
      {
         if(col == 0|| col == height - 1 + 2 * row|| row == 0|| row == height-1) // check the four edges of hallow trapezoid.
            cout << "*"; // print just the edges of the trapezoid with asterisks.
         else
            cout << " ";//print inside of the asterisks with blank spaces.
      }
      cout << endl;
   }
}

void triangle(int height)
{
    int row, col;
    for (row = 0; row <= height-1; row++)
    {
        for (col = 0; col <= row; col++)
        {
            cout << "*"; // print the triangle using nested loops.
        }
        cout << endl;
    }
}

void parallelogram(int height)
{
    int row, col;
    for (row = 0; row < height; row++)
    {
       for (col = height - row; col > 0; col--)
       {
          cout << " "; // print blank spaces on the incline or the left edge of parellelogram.
       }

       for (col = 0; col < height; col++)
       {
          if(col == 0|| col == height - 1|| row == 0|| row == height-1) // check the four edges of the parellelogram.
             cout << "*";//print only the edges with asterisks.
          else
             cout << " ";//print inside of the asterisks with blank spaces.
       }
       cout << endl;
    }
}
