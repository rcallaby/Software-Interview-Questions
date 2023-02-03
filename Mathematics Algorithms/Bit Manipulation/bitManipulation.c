#include <stdio.h>
#include <stdint.h>

//Here is a very simple demonstration of bit mainipulaiton in C.

// Function to set the nth bit of a number to 1
uint32_t set_bit(uint32_t num, uint32_t bit) {
  return num | (1 << bit);
}

// Function to clear the nth bit of a number to 0
uint32_t clear_bit(uint32_t num, uint32_t bit) {
  return num & ~(1 << bit);
}

// Function to toggle the nth bit of a number
uint32_t toggle_bit(uint32_t num, uint32_t bit) {
  return num ^ (1 << bit);
}

// Function to check if the nth bit of a number is set
int is_bit_set(uint32_t num, uint32_t bit) {
  return (num & (1 << bit)) != 0;
}

int main(void) {
  uint32_t num = 0b1010;

  printf("Original number: %u\n", num);

  // Set the 2nd bit to 1
  num = set_bit(num, 1);
  printf("After setting 2nd bit: %u\n", num);

  // Clear the 3rd bit to 0
  num = clear_bit(num, 2);
  printf("After clearing 3rd bit: %u\n", num);

  // Toggle the 1st bit
  num = toggle_bit(num, 0);
  printf("After toggling 1st bit: %u\n", num);

  // Check if the 4th bit is set
  int result = is_bit_set(num, 3);
  printf("Is 4th bit set? %d\n", result);

  return 0;
}
