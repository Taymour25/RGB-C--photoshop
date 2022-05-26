#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char pic[SIZE][SIZE][RGB];

void getpic ();
void returnpic ();
void revert ();

int main()
{
  getpic();
  revert();
  returnpic();
  return 0;
}

void getpic () {
   char userpic[100];

   cout << "Enter the source image file name: ";
   cin >> userpic;

   strcat (userpic, ".bmp");
   readRGBBMP(userpic, pic);
}

void returnpic () {
   char userpic[100];

   cout << "Enter the target image file name: ";
   cin >> userpic;

   strcat (userpic, ".bmp");
   writeRGBBMP(userpic, pic);
}

void revert() {
  for (int i = 0; i < (SIZE+1)/2; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k = 0; k < RGB; k++)
        {
            swap(pic[i][j][k],pic[SIZE-i][j][RGB-k]);
        }
        
    }
  }
}
