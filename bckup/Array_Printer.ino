#include <Arduino.h>

const int nilai_X = 205; // 59
const int nilai_Y = 100; // 50

float Array_X[nilai_X];
float Array_Y[nilai_Y];
// int Array_X[nilai_X];
// int Array_Y[nilai_Y];
int sisa = nilai_X % nilai_Y;
// float bagi = nilai_X / nilai_Y;
int bagi = nilai_X / nilai_Y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char buffer[100];

  // if(sisa>nilai_Y)
  Serial.print(bagi);
  // if (bagi > 1)
  // {
  //   sisa = sisa + nilai_Y;
  // }
  // else
  // {
  //   sisa=sisa;
  // }

  for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++) // Array X
  {
    Array_X[i] = i + 1;
    sprintf(buffer, "array_x %d: %.2f\n", i, Array_X[i]);
    Serial.print(buffer);
  }

  for (int i = 0; i < sizeof(Array_Y) / sizeof(Array_Y[0]); i++) // Array Y
  {
    if (nilai_X < nilai_Y) // jika X < Y
    {
      for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++)
      {
        Array_Y[i] = Array_X[i];
        sprintf(buffer, "array_y %d: %.2f\n", i, Array_Y[i]);
        Serial.print(buffer);
      }
    }
    else // jika X > Y dan X = Y
    {

      if (bagi > 4 && bagi < 7)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 5] + Array_X[i * 5 + 1] + Array_X[i * 5 + 2] + Array_X[i * 5 + 3] + Array_X[i * 5 + 3]) / 5;
        }
        else
        {
          Array_Y[i] = (Array_X[i * 4] + Array_X[i * 4 + 1] + Array_X[i * 4 + 2] + Array_X[i * 4 + 3]) / 4;
        }
      }

      else if (bagi > 2 && bagi < 5)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 4] + Array_X[i * 4 + 1] + Array_X[i * 4 + 2] + Array_X[i * 4 + 3]) / 4;
        }
        else
        {
          Array_Y[i] = (Array_X[i * 3] + Array_X[i * 3 + 1] + Array_X[i * 3 + 2]) / 3;
        }
      }

      else if (bagi > 1 && bagi < 3)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 3] + Array_X[i * 3 + 1] + Array_X[i * 3 + 2]) / 3;
        }
        else
        {
          Array_Y[i] = (Array_X[i * 2] + Array_X[i * 2 + 1]) / 2;
        }
      }
      else if (bagi < 2)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 2] + Array_X[i * 2 + 1]) / 2;
        }
        else // jika X = Y
        {
          Array_Y[i] = Array_X[i + sisa];
        }
      }
      sprintf(buffer, "array_y %d: %.2f\n", i, Array_Y[i]);
      Serial.print(buffer);
    }
    delay(200);
  }
}

//____________________________________ X = Y
// char buffer[100];
//  for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++) {
//    Array_X[i] = i + 1;
//    sprintf(buffer, "array_x %d: %d\n", i, Array_X[i]);
//    Serial.print(buffer);
//
//    for (int i = 0; i < sizeof(Array_Y) / sizeof(Array_Y[0]); i++)
//    {
//      Array_Y[i] = Array_X[i];
//      sprintf(buffer, "array_y %d: %d\n", i, Array_Y[i]);
//      Serial.print(buffer);
//    }

//____________________________________ X < Y
// char buffer[100];
//  for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++) {
//    Array_X[i] = i + 1;
//    sprintf(buffer, "array_x %d: %d\n", i, Array_X[i]);
//    Serial.print(buffer);
//
//    for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++)
//    {
//      Array_Y[i] = Array_X[i];
//      sprintf(buffer, "array_y %d: %d\n", i, Array_Y[i]);
//      Serial.print(buffer);
//    }

//____________________________________ X > Y jika X=2 kali dai Y
// char buffer[100];
//   for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++)
//   {
//     Array_X[i] = i + 1;
//     sprintf(buffer, "array_x %d: %d\n", i, Array_X[i]);
//     Serial.print(buffer);
//   }

//   for (int x = 0; x < sizeof(Array_Y) / sizeof(Array_Y[0]); x++)
//   {
//     Array_Y[x] = (Array_X[x + x] / 2) + 1;
//     sprintf(buffer, "array_y %d: %d\n", x, Array_Y[x]);
//     Serial.print(buffer);
//   }