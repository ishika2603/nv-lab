int myInt = 20;
unsigned long myTimeStamp = 1416813706;
const char *myCharArray = { "This is myCharArray"};
float myFloat = 3.14159265359;

void setup()
{
  Serial.begin(115200);
  Serial.print(myInt);
  Serial.print(myTimeStamp);
  Serial.print(myCharArray);
  Serial.print(myFloat, 6); //prints to six places right of the decimal
}
void loop()
{
  exit(0);
}