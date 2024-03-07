// CW Pulse sequence, laser stays on for some long duration.

#include <util/delay.h>

void generateTTLSequence() {
  // Disable interrupts to minimize jittering
  cli();

  // Set up the pins for the pulse sequence
  PORTD &= B11110011; // Set pins D2, D3, D4, and D5 low

  // Generate pulse sequence
    PIND = B00000100;   // Toggle pin D2 (laser driver control)
    // delay(1000);
    _delay_us(60000000); // set delay for 1 min rn
    PORTD &= B11111011; // set pin d2 low

  // Re-enable interrupts
  sei();
}

int main() {
    Serial.begin(115200);

  // Call the function to generate the TTL sequence
  generateTTLSequence();
  
  // Return 0 to indicate successful execution
  return 0;
}