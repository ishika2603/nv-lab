// cli();
// PORTD &= B11110011;
// PORTD |= B00000100;

// for (long i = 0; i < cycles; i++){
//     _delay_us(9.4375);
//     PORTD &= B11111011;
//     _delay_us(0.8750);
//     // PORTD |= B00001000;
//     // PIND = B00001000;
//     PIND = B00000100;

// }
// sei();

#include <util/delay.h>

void generateTTLSequence() {
  // Disable interrupts to minimize jittering
  cli();

  // Set up the pins for the pulse sequence
  PORTD &= B11110011; // Set pins D2, D3, D4, and D5 low
  PORTD |= B00000100; // Set pin D2 high (laser driver control)

  // Generate pulse sequence
  for (long i = 0; i < 10; i++) {
    // Serial.println(i);
    _delay_us(9.4375);  // Delay for MW pulse
    PORTD &= B11111011; // Set pin D3 low (MW switch control)
    _delay_us(0.8750);  // Delay for waiting time
    PORTD |= B00001000; // Set pin D4 high (S1-S2 switches control)
    PIND = B00001000;   // Toggle pin D3 (MW switch control)
    PIND = B00000100;   // Toggle pin D2 (laser driver control)
  }

  // Re-enable interrupts
  sei();
}

int main() {
    Serial.begin(115200);
    // Serial.println("hello");
  // Call the function to generate the TTL sequence
  generateTTLSequence();
  Serial.println("exiting loop");
  
  // Return 0 to indicate successful execution
  return 0;
}