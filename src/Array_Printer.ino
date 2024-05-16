#include <Arduino.h>

const int nilai_X = 500; // Panjang Array_X
const int nilai_Y = 50; // Panjang Array_Y

float Array_X[nilai_X];
float Array_Y[nilai_Y];

int bagi = nilai_X / nilai_Y;
int sisa = nilai_X % nilai_Y;
int selisihY = nilai_Y - nilai_X;
char buffer[500];

void hitungArrayY()
{
  for (int i = 0; i < sizeof(Array_Y) / sizeof(Array_Y[0]); i++)
  {
    float total = 0.0;
    int j;

    if (i < sisa)
    {
      for (j = i * (bagi + 1); j < (i + 1) * (bagi + 1); j++)
      {
        total += Array_X[j];
      }
    }
    else
    {
      for (j = i * bagi + sisa; j < (i + 1) * bagi + sisa; j++)
      {
        total += Array_X[j];
      }
    }

    Array_Y[i] = total / (i < sisa ? (bagi + 1) : bagi);

    sprintf(buffer, "array_y %d: %.2f\n", i, Array_Y[i]);
    Serial.print(buffer);

    if (i == nilai_X - 1)
    {
      break;
    }
  }
}

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
  hitungArrayY();
}
