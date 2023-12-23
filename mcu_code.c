```c
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Define pins for temperature control
#define HEATER_PIN PORTB0
#define COOLER_PIN PORTB1

// Define pins for radiation simulation
#define RADIATION_PIN PORTB2

// Define pins for sensor readings
#define TEMP_SENSOR_PIN PORTC0
#define RADIATION_SENSOR_PIN PORTC1
#define PRESSURE_SENSOR_PIN PORTC2

// Function to initialize ADC
void ADC_init() {
    ADMUX = (1<<REFS0); // Use AVcc as the reference
    ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // Enable ADC and set prescaler to 128
}

// Function to read ADC value
uint16_t ADC_read(uint8_t ch) {
    ch &= 0b00000111; // Limit the channel selection to 0-7
    ADMUX = (ADMUX & 0xF8) | ch; // Clear the older channel selection and set the new one
    ADCSRA |= (1<<ADSC); // Start conversion
    while(ADCSRA & (1<<ADSC)); // Wait for conversion to complete
    return (ADC);
}

// Function to control temperature
void control_temperature(int target_temp) {
    int current_temp = ADC_read(TEMP_SENSOR_PIN);
    if (current_temp < target_temp) {
        PORTB |= (1<<HEATER_PIN);
        PORTB &= ~(1<<COOLER_PIN);
    } else if (current_temp > target_temp) {
        PORTB |= (1<<COOLER_PIN);
        PORTB &= ~(1<<HEATER_PIN);
    } else {
        PORTB &= ~(1<<HEATER_PIN);
        PORTB &= ~(1<<COOLER_PIN);
    }
}

// Function to simulate radiation
void simulate_radiation(int radiation_level) {
    if (radiation_level > 0) {
        PORTB |= (1<<RADIATION_PIN);
    } else {
        PORTB &= ~(1<<RADIATION_PIN);
    }
}

int main(void) {
    // Initialize ADC
    ADC_init();

    // Set pins as output
    DDRB |= (1<<HEATER_PIN) | (1<<COOLER_PIN) | (1<<RADIATION_PIN);

    // Main loop
    while (1) {
        control_temperature(25); // Set target temperature to 25 degrees Celsius
        simulate_radiation(1); // Simulate radiation
        _delay_ms(1000); // Delay for 1 second
    }

    return 0;
}
```
