
cli()
PORTD &= B11110011;
PORTD |= B00000100;

for (long i = 0; i < cycles; i++){
    _delay_us(9.4375);
    PORTD &= B11111011;
    _delay_us(0.8750);
    PORTD |= B00001000;
    PIND = B00001000;
    PIND = B00000100;

}
sei();