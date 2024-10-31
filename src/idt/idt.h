#ifndef IDT_H
#define IDT_H

#include "../config.h"
#include <stdint.h>
#include "../display/print.h"
#include "../mem/memset.h"
#include "../io/io.h"
#include "../display/print.h"



struct interrupt_descriptor {
   uint16_t offset_1;                   // offset bits 0..15
   uint16_t selector;                   // a code segment selector in GDT or LDT
   uint8_t  zero;                       // unused, set to 0
   uint8_t  type_attributes;            // gate type, dpl, and p fields
   uint16_t offset_2;                   // offset bits 16..31
}__attribute((packed));

struct idtr_desc{                       // describes the IDTR
    uint16_t limit;                     // size of descriptor table
    uint32_t base;                      // address of start of descriptor table
}__attribute__((packed));   


void idt_set(int interrupt_num, void *address);
void idt_init();

void enable_interrupts();
void disable_interrupts();


#endif