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

Dimension getSizePicture(FILE *fileIMG) {
   Dimension dim;

   fscanf(fileIMG,"%d", dim->width); 
   fscanf(fileIMG,"%d", dim->height);
   return dim;
}

PictureDescriptor createPictureDescriptor(FILE *fileIMG){
   Dimension size;
   int *matrixRED ;
   int bit[256]={0} ;
   int tmpBit;
   int i , j , tmpval=1;
   
   fopen(fileIMG);
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
               matrix[1*size.height+i][j]%=(255/tmpval);
               matrix[2*size.height+i][j]%=(255/tmpval);
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
  createHistogram( bit[], size );
   fclose(fileIMG);
}

/*Change mode*/
void setMode(PictureDescritor *pd ,Mode m) {
  pd->writingMode = m;
}

/*return mode*/
Mode getMode(PictureDescriptor pd) {
  return pd.writingMode;
}

/**/
void setNbcomp(PictureDescritor *pd, int n) {
  pd->nbcomp = n;
}

/*return nbcomp*/
int getNbcomp(PictureDescritor pd) {
  return pd.nbcomp;
}

/**
 * 
*/
void setNbquantif(PictureDescritor *pd, int n) {
  pd->nbquantif = n;
}

/*return nbquantif*/
int getNbquantif(PictureDescritor pd ){
  return pd.nbquantif;
}

/**
 *Create an histogramm with the 64 values possibles.
 * It give the number of picture's pixel which have an intensity value : red, blue, green or gray level.
 */
void createHistogram(int bit[] , Dimension dim){
  
}

/**
*Print the image's histogram.
* his function permit to watch the percentage about pixel's value.
*/
void printHistogram() {
  
}
