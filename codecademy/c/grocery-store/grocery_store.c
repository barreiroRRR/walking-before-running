#include <stdio.h>

int main() {
  
 int appleQuantity;
 double applePrice = 1.49;
 float appleReview = 823;
 float reviewers = 9;
 int appleReviewDisplay;
 const char appleLocation = 'F';
 int dayOfWeek = 2;
 appleReview += 52;
 reviewers += 1;


 appleQuantity = 23;
 appleReview = 82.5;
 float appleReviewAverage = appleReview / reviewers;
 appleReviewDisplay = (int)appleReviewAverage;
 dayOfWeek = 3;

 if(appleQuantity < 10 && dayOfWeek == 3)
 {
  printf("Sale on apples today, today only they are: $%.2f\n", applePrice * .9);
 }

 // Put all your code above this and if you declare your variables using the given names and types there is no need to change any of the code below.
 printf("An apple costs: $%.2f, there are %d in inventory found in section: %c and your customers gave it an average review of %d%%!", applePrice, appleQuantity, appleLocation, appleReviewDisplay);

}