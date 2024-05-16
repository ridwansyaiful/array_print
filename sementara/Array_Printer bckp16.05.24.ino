#include <Arduino.h>

const int nilai_X = 505; // 59
const int nilai_Y = 300;  // 50

float Array_X[nilai_X];
float Array_Y[nilai_Y];
// int Array_X[nilai_X];
// int Array_Y[nilai_Y];
int sisa = nilai_X % nilai_Y;
// float bagi = nilai_X / nilai_Y;
int bagi = nilai_X / nilai_Y;
char buffer[500];

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++) // Array X
  {
    Array_X[i] = i + 1;
    sprintf(buffer, "array_x %d: %.2f\n", i, Array_X[i]);
    Serial.print(buffer);
    // Serial.print("ARRAY_X ");
    // Serial.print(i);
    // Serial.print(":");
    // Serial.println(Array_X[i]);
  }
}

void loop()
{
  // char buffer[100];

  // if(sisa>nilai_Y)

  // if (bagi > 1)
  // {
  //   sisa = sisa + nilai_Y;
  // }
  // else
  // {
  //   sisa=sisa;
  // }

  for (int i = 0; i < sizeof(Array_Y) / sizeof(Array_Y[0]); i++) // Array Y
  {
    if (nilai_X < nilai_Y) // jika X < Y
    {
      for (int i = 0; i < sizeof(Array_X) / sizeof(Array_X[0]); i++)
      {
        Array_Y[i] = Array_X[i];
        //        sprintf(buffer, "array_y %d: %.2f\n", i, Array_Y[i]);
        //        Serial.print(buffer);

        Serial.print("ARRAY_Y ");
        Serial.print(i);
        Serial.print(":");
        Serial.println(Array_Y[i]);
      }
    }
    else // jika X > Y dan X = Y
    {

      if (bagi > 4 && bagi < 6)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 5] + Array_X[i * 5 + 1] + Array_X[i * 5 + 2] + Array_X[i * 5 + 3] + Array_X[i * 5 + 4] + Array_X[i * 5 + 5]) / 6;
          Serial.print("Sisa :");
          Serial.println(sisa);
        }
        else
        {
          Array_Y[i] = (Array_X[i * 5 + sisa] + Array_X[i * 5 + 1 + sisa] + Array_X[i * 5 + 2 + sisa] + Array_X[i * 5 + 3 + sisa] + Array_X[i * 5 + 3 + sisa]) / 5;//* 1.007412
        }
        // Serial.print("bagi 5 ");
        Serial.print(bagi);
      }

      else if (bagi > 3 && bagi < 5)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 4] + Array_X[i * 4 + 1] + Array_X[i * 4 + 2] + Array_X[i * 4 + 3] + Array_X[i * 4 + 3]) / 5;
          Serial.print("Sisa :");
          Serial.println(sisa);
        }
        else
        {
          Array_Y[i] = (Array_X[i * 4 + sisa] + Array_X[i * 4 + 1 + sisa] + Array_X[i * 4 + 2 + sisa] + Array_X[i * 4 + 3 + sisa]) / 4;//* 1.006061
        }
        // Serial.print("bagi:");
        Serial.print(bagi);
      }

      else if (bagi > 2 && bagi < 4)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 3] + Array_X[i * 3 + 1] + Array_X[i * 3 + 2] + Array_X[i * 3 + 3]) / 4;
        }
        else
        {
          Array_Y[i] = (Array_X[i * 3 + sisa] + Array_X[i * 3 + 1 + sisa] + Array_X[i * 3 + 2 + sisa]) / 3;//*1.005051
        }
        // Serial.println("__bagi 3");
        Serial.print(bagi);
      }

      else if (bagi > 1 && bagi < 3)
      {
        if (i < sisa)
        {
          Array_Y[i] = (Array_X[i * 2] + Array_X[i * 2 + 1] + Array_X[i * 2 + 2]) / 3;
          Serial.print("Sisa :");
          Serial.println(sisa);
        }
        else
        {
          Array_Y[i] = (Array_X[i * 2 + sisa] + Array_X[i * 2 + 1 + sisa]) / 2;//* 1.003367
        }
        // Serial.println("__bagi 2");
        Serial.print(bagi);
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
        // Serial.println("__bagi 1");
        Serial.print(bagi);
      }
      else
      {
        Serial.println("pembagi X dan Y terlalu banyak");
      }
      //      sprintf(buffer, "array_y %d: %.2f\n", i, Array_Y[i]);
      //      Serial.print(buffer);
      Serial.print("ARRAY_Y ");
      Serial.print(i);
      Serial.print(":");
      Serial.println(Array_Y[i]);
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