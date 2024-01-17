/* This code is to make a joystick control LEDs based on the direction of the joystick and the LED placement
   Programmer: Pranay Ranjan
   Date: 1/17/2024
   
*/
// Set analog and digital pins to variables for data reading of the joystick and the pins numbers for LEDs
int x_pin = A0; 
int y_pin = A1; 
int l_led = 11; 
int r_led = 9;
int f_led = 8; 
int b_led = 10; 

void setup(){ // run once
  Serial.begin(9600); // start the serial monitor
  pinMode(x_pin, INPUT); // Set "x_pin" as INPUT through pinMode
  pinMode(y_pin, INPUT); // Set "y_pin" as INPUT through pinMode
}

void loop(){ // runs infinitely
  // sets the integer value of "x_data" and "y_data" to the values that are stored in "x_pin" and "y_pin" by reading the analog values
  int x_data = analogRead(x_pin);
  int y_data = analogRead(y_pin); 

  // makes the Serial monitor print out the x_data and y_data every 100 milliseconds in a formatted way
  Serial.print("x_data:");
  Serial.print(x_data); 
  Serial.print("\t"); 
  Serial.print("y_data:"); 
  Serial.println(y_data); 
  delay(100); 

  /* The output value from the joystick for X_data and y_data will be between 0 and 1023. It will be zero at one end and 1023 at other end
   *  we set the threshhold of 100 and 900 so that LEDs respond only when joystick is turned at extream end and not in central position 
    */
  // if statement that if the joystick on the x axis is above 900 (in the left direction) then the left LED turns on
  if(x_data > 900)
    digitalWrite(l_led, HIGH); 


  // else if statement that if the joystick on the x axis is below 100 (in the right direction) then the right LED turns on
  else if (x_data < 100)
    digitalWrite(r_led, HIGH);

  // when the joystick is not in the direction left or direction right, both LEDs stay off
  else {
    digitalWrite(l_led, LOW);
    digitalWrite(r_led, LOW);
  }
  
  // if statement that if the joystick on the y axis is above 900 (in the front direction) then the front LED turns on
  if(y_data > 900)
    digitalWrite(f_led, HIGH); 

  // else if statement that if the joystick on the y axis is below 100 (in the back direction) then the back LED turns on
  else if (y_data < 100)
    digitalWrite(b_led, HIGH);

  // if the joystick is neither above 900 or below 100 (not at ends) then both front and back LEDs are off
  else {
    digitalWrite(f_led, LOW);
    digitalWrite(b_led, LOW);
  } 
}
