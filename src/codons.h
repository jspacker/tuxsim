#ifndef CODONS_H
#define CODONS_H
#include "GBase.h"
#include <ctype.h>

unsigned short packCodon(char n1, char n2, char n3);
//assumes n1,n2,n3 are UPPERCASE!

struct Codon {
 char nuc[3];
 Codon(char* str=NULL) {
  if (str==NULL) {
   nuc[0]='N';
   nuc[1]='N';
   nuc[2]='N';
   }
  else {
   nuc[0]=toupper(str[0]);
   nuc[1]=toupper(str[1]);
   nuc[2]=toupper(str[2]);
   }
  }

 Codon(char s1, char s2, char s3) {
   nuc[0]=toupper(s1);
   nuc[1]=toupper(s2);
   nuc[2]=toupper(s3);
   }
 
   
 char& operator[](int idx) {
   if (idx<0 || idx>2) 
      GError("Error: Codon index out of bounds!\n");
   return nuc[idx];
   }

 char operator[](int idx) const {
   if (idx<0 || idx>2) 
      GError("Error: Codon index out of bounds!\n");
   return nuc[idx];
   }
 
 char translate();
 };



bool codonTableInit();
 
#endif
