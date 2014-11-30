#include "PictureDescriptor.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

/*Initialize a new picture's descriptor*/
PictureDescriptor initPictureDescriptor(FILE* file) {
   //OPEN FILE CONFIGURATOR TO CATCH DATAS TO INITIALIZE DESCRIPTOR
   int pd->id= 000000000;
  Mode pd->writingMode=AUTO;
  int pd->nbcomp = 0;
  int pd->nbquantif =2;
  int pd->*histogram=NULL;
}
//===================================================================================================
Dimension getSizePicture(FILE *fileIMG) {
   Dimension dim;

   fscanf(fileIMG,"%d", dim->width); 
   fscanf(fileIMG,"%d", dim->height);
   return dim;
}
//===================================================================================================
PictureDescriptor createPictureDescriptor(FILE *fileIMG){
   Dimension size;
   int *matrixRED ;
   int bit[256]={0} ;
   int tmpBit;
   int i , j , tmpval=1;
   
   fopen(fileIMG, 'r');
   size=getSizePicture(fileIMG);
   quantif=getNbquantif(pd); // GIVE PD
   
   matrix=(*int)malloc(size.width*sizeof(int)); //matrix 1 dimension ...
   for(i=0 ; i<size.heigth ; i++)
   *matrix[i]=(*int)malloc(size.height*3*sizeof(int)); // grow up into matrix with 2 dimensions
      
   for(i=0 ; i<size.wdith ; i++){ // scan the whole matrix : 1rst Red , 2nd Green , 3th Blue
      for(j=0; j<size.height ; j++) {
         tmpBit=0;
         fscanf(fileIMG , "%d" , matrix[i][j]); // on RED matrix
         fscanf(fileIMG , "%d" , matrix[1*size.height+i][j]); // on GREEN matrix
         fscanf(fileIMG , "%d" , matrix[2*size.height+i][j]); // on BLUE matrix
         while(quantif!=0) {
               matrix[i][j]%=(255/tmpval);
               matrix[1*size.height+i][j]%=((int)(255/tmpval) + tmpval!=1 ); //+ tmpval!=1 : differentiate 127 of 128, because (int)255/2=127, but bit2=1 if number is a modulo of 128, not 127
               matrix[2*size.height+i][j]%=((int)(255/tmpval) + tmpval!=1 );
              if( matrix[i][j] == 0 )  tmpBit+= power(2,3+quantif); // on RED matrix, for example quantif=2 : modulo 128, 255
              if( matrix[1*size.height+i][j] == 0 )  tmpBit+= power(2,1+quantif); // on  GREEN matrix
              if( matrix[2*size.height+i][j] == 0 )  tmpBit+=1*power(2,quantif-1); // on BLUE matrix
              quantif--;
              tmpval++;
         /*For example (255,128,16) and quantif=2
          * 1rst round:quantif=2 & tmpval=1 --> matRED[][]%255=0 --> tmpBit=32
          *                                 --> matGREEN[][]%255=128 --> tmpBIT=32
          *                                 --> matBLUE[][]%255=16 --> tmpBIT=32
          * 2nd round:quantif=1 & tmpval=2 --> matRED[][]%128=0 --> tmpBit=32
          *                                 --> matGREEN[][]%128=0 --> tmpBIT=36
          *                                 --> matBLUE[][]%255=16 --> tmpBIT=36
          *--> bit[36-1]++
          */
         }
         bit[tmpBit-1]++;
      }   
   }
  createHistogram( bit[], size , quantif);
   fclose(fileIMG);
}
//===================================================================================================
/*Change mode*/
void setMode(PictureDescritor *pd ,Mode m) {
  pd->writingMode = m;
}
//===================================================================================================
/*return mode*/
Mode getMode(PictureDescriptor pd) {
  return pd.writingMode;
}
//===================================================================================================
/**/
void setNbcomp(PictureDescritor *pd, int n) {
  pd->nbcomp = n;
}
//===================================================================================================
/*return nbcomp*/
int getNbcomp(PictureDescritor pd) {
  return pd.nbcomp;
}
//===================================================================================================
/**
 * 
*/
void setNbquantif(int n) {
  pd->nbquantif = n;
}
//===================================================================================================
/*return nbquantif*/
int getNbquantif(){
  return pd.nbquantif;
}
//===================================================================================================
/**
 *Create an histogramm with the 64 values possibles.
 * It give the number of picture's pixel which have an intensity value : red, blue, green or gray level.
 */
void createHistogram(int bit[] , Dimension dim , int quantif){
  float tab[power(3,quantif)]; // 3 colors of Nquantif bits
  int i;
  
  for(i=0 ; i<power(3,quantif) ; i++);
   tab[i] = bit[i]/(dim.height*dim.width); // give a percentage about IntensityValuePixel on numberPixel.
}
//===================================================================================================
/**
*Print the image's histogram.
* his function permit to watch the percentage about pixel's value.
*/
void printHistogram(FILE *descriptIMG) {
   int i , j , NbIntensity , size1 , size2 , size;
   float array; // percentage given of descriptIMG
   char c;
   // NEED to know Nbquantif !!!!!!!!!!!!!!!
   Nbquantif=getNbquantif();
   NbIntensity= power(2,3*Nbquantif); // if nbQuantif=2 --> 2^(3*2)=64
   array=(*float)malloc(NbIntensity*sizeof(float));
   
   fopen(descriptIMG,'r');
   for(i=0 ; i<7 ; i++){ // Permit to place himself at the 7th lines, where the histogram's array start and the sizes.
            fgets(NULL , 200 , descriptIMG ); // read a line and economise memories
         }
   fscanf(descriptIMG , "%d" , &size1);
   fscanf(descriptIMG , "%d" , &size2);
   size = size1*size2;
   
   for(i=0 ; i< NbIntensity ; i++) // get back histogram datas.
      fscanf(descriptIMG , "%f" , array[i]);
      
   for(i=0 ; i<NbIntensity/2 ; i++){ // printf the histigram
      printf("val%3d:" , i+1);   for(j=0;j<array[i]*10 ; j++) printf('o'); 
      printf("%d" , array[i]);   for(j=0;j<(1-array[i])*10 ; j++) printf(' '); // give a visual graphic whose the value's size appear on 10 'o' at 100%
       printf("val%3d:" , NbIntensity/2+i);   for(j=0;j<array[NbIntensity/2+i-1]*10 ; j++) printf('o'); 
      printf("%d" , array[NbIntensity/2+i-1]);   for(j=0;j<(1-array[NbIntensity/2+i-1])*10 ; j++) printf(' ');
   }
   printf("\n>==== On %d read pixels ====<\n" , size);
}
