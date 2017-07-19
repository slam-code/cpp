
#include <stdio.h>
#include <stdlib.h>

int   main() 
{ 
      FILE *fp;
      long i = 9999999;
      fp = fopen("bin.txt","wb");
      fwrite(&i,sizeof(i),1,fp);
      fclose(fp);
      fp = fopen("asc.txt","wt");
      fprintf(fp,"%d",i);
      fclose(fp);
     // system("pause");
}



