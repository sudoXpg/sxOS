#include "fxn.h"

void int_to_str(unsigned int num, char *str) {
    int i = 0;
    
    // Handle the special case for 0
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0'; // Null-terminate the string
        return;
    }

    // Extract digits and convert to characters
    while (num > 0) {
        int digit = num % 10; // Get last digit
        str[i++] = digit + '0'; // Convert to character
        num /= 10; // Remove the last digit
    }

    str[i] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct order
    for (int start = 0, end = i - 1; start < end; start++, end--) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

double sqrt(double num) {
    if (num < 0) return -1; // Error for negative input
    if (num == 0 || num == 1) return num;

    double guess = num / 2.0;
    double epsilon = 0.000001; // Accuracy

    while ((guess * guess - num > epsilon) || (num - guess * guess > epsilon)) {
        guess = (guess + num / guess) / 2.0;
    }

    return guess;
}

void sum(){
    uint32_t i=0;
    uint32_t sum;
    char s[20];
    char istr[20];
    while(i<UINT32_MAX){
        sum+=i;
        int_to_str(sum,s);
        int_to_str(i,istr);
        print(istr);
        print(" : ");
        print(s);
        print("\n");
        i++;
    }
}

int isPrime(uint32_t num){
    for(int i=2;i<=sqrt((double)i);i++){
        
        if(num%2==0 || num%5==0 || num%3==0 || num%7==0 || num%11==0 || num%13==0 ){
            return 0;
        }
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}


void prime(){
    uint32_t i=2;
    char s[20];
    while(1){
        if(isPrime(i)){
            int_to_str(i,s);
            print(s);
            print("\n");
            i++;
        }
    }

}