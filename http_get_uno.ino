int sensor=12;
int val=0;
char incomingByte = 0;   // for incoming serial data
String yazi="";
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {
 while (Serial1.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial1.read();
                yazi+=incomingByte;
                // say what you got:
               // Serial.print("I received: ");
        }
        if(!yazi.equals("")) {
                        Serial.print(yazi);
                        }
yazi="";
}
