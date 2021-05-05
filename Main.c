#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "delay.h"

float a;
float b;
float c;
float ax;
float bx;
float cx;
int choice;
int again_choice;
int do_actions = 1;

float solve(int action) {
  if (action == 1) {
    ax = a * a;
    bx = b * b;
    cx = ax + bx;
    c = sqrt(cx);
    return c;
  } else if (action == 2) {
    ax = a * a;
    cx = c * c;
    bx = cx - ax;
    b = sqrt(bx);
    return b;
  } else {
    fprintf(stderr, "\nSyntax error: Invalid syntax\n");
  }
}

int done() {
  printf("\n\nLeaving in 5 seconds . . .\n");
  delay(5);
  exit(0);
}

void main() {
  printf("\n");
  do_actions = 1;
  while (do_actions = 1) {
    a = 0.0;
    b = 0.0;
    c = 0.0;

    printf("What would you like to do with your right triangle?\n\n");
    printf("[1] Find the length of the line that doesn't touch the right angle\n");
    printf("[2] Find the length of one of the lines that touch the right triangle\n");
    printf("[3] Nothing\n\n");
    printf("Type your answer: ");
    scanf("%i", &choice);
    printf("\n\n");

    if (choice == 1) {
      do_actions = 0;
      printf("What is the length of 1 of the sides that touch the right angle?\n> ");
      scanf("%f", &a);
      printf("\nWhat is the length of the other side that touches the right angle?\n> ");
      scanf("%f", &b);
      printf("\nThe length of the line that doesnt touch the right angle is %f\n\n", solve(1));
      printf("Do you want to go again? [1 = Yes, 0 = No]: ");
      scanf("%i", &again_choice);
      if (again_choice == 1) {
        do_actions = 1;
      } else {
        done();
      }
    } else if (choice == 2) {
      do_actions = 0;
      printf("What is the length of the known side that touches the right angle?\n> ");
      scanf("%f", &a);
      printf("\nWhat is the length of the side that doesn't touch the right angle?\n> ");
      scanf("%f", &c);
      printf("\nThe length of the the unknown line that touches the right angle is %f\n\n" , solve(2));
      printf("Do you want to go again? [1 = Yes, 0 = No]: ");
      scanf("%i", &again_choice);
      if (again_choice == 1) {
        do_actions = 1;
      } else {
        done();
      }
    } else if (choice == 3) {
      done();
    } else {
      fprintf(stderr, "Invalid response, try again\n\n\n");
    }
  }
}
