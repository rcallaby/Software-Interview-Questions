#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 256
#define COLS 256
#define GRAYLEVELS 256

void histogram_equalization(unsigned char image[ROWS][COLS], int rows, int cols);
void print_histogram(int histogram[GRAYLEVELS]);

int main() {
  unsigned char image[ROWS][COLS];

  // Load the image here

  histogram_equalization(image, ROWS, COLS);

  // Save the equalized image here

  return 0;
}

void histogram_equalization(unsigned char image[ROWS][COLS], int rows, int cols) {
  int i, j, k;
  int histogram[GRAYLEVELS];
  float cumulative_histogram[GRAYLEVELS];
  float normalization_factor = (float) (rows * cols);

  // Initialize histogram
  for (k = 0; k < GRAYLEVELS; k++) {
    histogram[k] = 0;
  }

  // Calculate the histogram
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      histogram[image[i][j]]++;
    }
  }

  // Calculate the cumulative histogram
  cumulative_histogram[0] = (float) histogram[0] / normalization_factor;
  for (k = 1; k < GRAYLEVELS; k++) {
    cumulative_histogram[k] = cumulative_histogram[k - 1] + (float) histogram[k] / normalization_factor;
  }

  // Apply histogram equalization
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      image[i][j] = (unsigned char) round(cumulative_histogram[image[i][j]] * (GRAYLEVELS - 1));
    }
  }
}

void print_histogram(int histogram[GRAYLEVELS]) {
  int k;
  for (k = 0; k < GRAYLEVELS; k++) {
    printf("%d: %d\n", k, histogram[k]);
  }
}
