#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
   if(argc != 3){
       printf("%s <freq> <dBel>\n", argv[0]);
       return 1;
   }

   float d;
   float fr = atof(argv[1])*1000;
   float x = atof(argv[2]);
 //  d = pow(10.f, (27.55f - (20.f*log10(fr)) - x)/20.f);
   d = pow(10.f, ( (-x/20.f) - log10(fr) - 1.622 ))*1000;
   printf("%f\n", d);
   return 0;
}
