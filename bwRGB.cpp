#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char pic[SIZE][SIZE][RGB];

void getpic ();
void returnpic ();
void changepic ();

int main()
{
  getpic();
  changepic();
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

void changepic() {
  for (int i = 0; i < (SIZE-1); i++) {
    for (int j = 0; j< (SIZE-1); j++) {
        for (int k = 0; k < RGB; k++)
        {
            if (pic[i][j][k]>1)
            pic[i][j][k] = pic[i][j][1];
        else
            pic[i][j][k] = pic[i][j][0];

        }
        
    }
  }
}
