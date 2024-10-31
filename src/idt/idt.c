#include "idt.h"

struct interrupt_descriptor idt[sxOS_TOTAL_INTERRUPTS];
struct idtr_desc idtr;

extern void idt_load(struct idtr_desc *idtr);
extern void int21h();
extern void no_interrupt();

void idt_zero(){
    print("\nDivision by zero error!\n");
}


void idt_set(int interrupt_num, void *address){
    struct interrupt_descriptor *desc=&idt[interrupt_num];
    desc->offset_1=(uint32_t) address & 0x0000ffff;             // get lower 4 bytes
    desc->selector=KERNEL_CODE_SELECTOR;
    desc->zero=0x00;
    desc->type_attributes=0xEE ;      // EE = 1 11 0 1110 {P DPL STORAGE_SEG(=0 for int) GATE_TYPE}
    desc->offset_2=(uint32_t)address>>16;
}

void idt_init(){
    memset(idt,0,sizeof(idt));
    idtr.limit=sizeof(idt)-1;
    idtr.base=(uint32_t) idt;
    for(int i=0;i<sxOS_TOTAL_INTERRUPTS;i++){
        idt_set(i,no_interrupt);
    }

    idt_set(0,idt_zero);
    idt_set(0x21,int21h);
    idt_load(&idtr);
}

void int21h_handler(){

    // Notify PIC that interrupt has been handled
    outb(0x20, 0x20);                   // 0x20 port -> 0x20 command == end of interrupt || basically tell PIC we're done handling
}

void no_interrupt_handler(){
    outb(0x20,0x20); // tell the PIC we're done handling
}

