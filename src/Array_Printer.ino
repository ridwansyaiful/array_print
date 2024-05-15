#include <Arduino.h>

const int nilai_X = 20;//59
const int nilai_Y = 10;//50

// float Array_X[nilai_X];
// float Array_Y[nilai_Y];
int Array_X[nilai_X];
int Array_Y[nilai_Y];
int sisa = nilai_X % nilai_Y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char buffer[100];
  int x;

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

  //____________________________________ X > Y jika X=2 kali dai Y
  // char buffer[100];
  for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++)
  {
    Array_X[i] = i + 1;
    sprintf(buffer, "array_x %d: %d\n", i, Array_X[i]);
    Serial.print(buffer);
  }

  for (int x = 0; x < sizeof(Array_Y) / sizeof(Array_Y[0]); x++)
  {
    Array_Y[x] = (Array_X[x + x] / 2) + 1;
    sprintf(buffer, "array_y %d: %d\n", x, Array_Y[x]);
    Serial.print(buffer);
  }

  // _________________________________X > Y ada sisa bagi
  // for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++)
  // {
  //   Array_X[i] = i + 1;
  //   Serial.print("array x :");
  //   Serial.println(Array_X[i]);
  // }

  // for (int i = 0; i < sizeof(Array_Y) / sizeof(Array_Y[0]); i++)
  // {
  //   if (i < sisa)
  //   {
  //     Array_Y[i] = (Array_X[i + i] + Array_X[i + i + 1]) / 2;
  //   }
  //   else
  //   {
  //     Array_Y[i] = Array_X[i + sisa];
  //   }
  //   Serial.print("Array y ");
  //   Serial.print(i);
  //   Serial.print(": ");
  //   Serial.println(Array_Y[i]);
  // }
  delay(1000);
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