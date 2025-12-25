// 0. Documentation Section
// main.c
// Purpose: Implement Lab 4 logic for TM4C123 LaunchPad
// Author: D.D.N.Devinda_Kaushalya
// Date: December 25, 2025
// Hardware Connections:
//   Input:  SW1 connected to PF4 (Negative Logic)
//   Input:  SW2 connected to PF0 (Negative Logic)
//   Output: Red LED connected to PF1 (Positive Logic)
//   Output: Blue LED connected to PF2 (Positive Logic)
//   Output: Green LED connected to PF3 (Positive Logic)

// 1. Pre-processor Directives Section
// Define Port F data register address to access physical pins
#define GPIO_PORTF_DATA_R (*((volatile unsigned long *)0x400253FC))

// 2. Declarations Section
void PortF_Init(void); // Function prototype for initialization

// 3. Main Subroutine Section
int main(void){
  unsigned long In; // Variable to store switch input data
  
  PortF_Init(); // Call initialization once at the start
  
  while(1){ // Infinite loop: embedded software never finishes
    
    // Read Inputs: Mask with 0x11 to select PF4 and PF0
    // 0x11 in binary is 0001 0001 (selecting bits 4 and 0)
    In = GPIO_PORTF_DATA_R & 0x11;
    
    // Implement Logic using the Truth Table
    // Remember: Negative Logic means '0' is pressed
    
    if(In == 0x00){ 
      // Both switches pressed (PF4=0, PF0=0)
      GPIO_PORTF_DATA_R = 0x04; // Output Blue
    } 
    else if(In == 0x01){ 
      // Just SW1 pressed (PF4 is 0, PF0 is 1)
      GPIO_PORTF_DATA_R = 0x02; // Output Red
    } 
    else if(In == 0x10){ 
      // Just SW2 pressed (PF4 is 1, PF0 is 0)
      GPIO_PORTF_DATA_R = 0x08; // Output Green
    } 
    else { 
      // Neither switch pressed (PF4=1, PF0=1)
      GPIO_PORTF_DATA_R = 0x00; // LEDs Off
    }
  }
}

// Subroutine to initialize Port F
void PortF_Init(void){
  // Note: Detailed initialization (Chapter 6) required for hardware
  // This function would normally set the clock, direction, and digital enable.
}