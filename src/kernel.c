#include "kernel.h"


void kernel_main(){
    
    termial_init();
    print(sxOS_logo);

    idt_init();
    enable_interrupts();

    print("\n Will print the sum of n numbers ");
    int k=0;
    for(uint64_t i=0;i<=60000000;i++){
        k++;
    }
    termial_init();
    print("\n");
    sum();
}
