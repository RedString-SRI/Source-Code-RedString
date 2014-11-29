#include "PictureDescriptor.h
"
/*Initialize a new picture's descriptor*/
PictureDescriptor initPictureDescriptor(FILE* file) {
   int pd->id=;
  Mode pd->writingMode=AUTO;
  int pd->nbcomp = 0;
  int pd->nbquantif =64;
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
   int matrixRED , *matrixGREEN , *matrixBLUE;
   int pixelIntensityRED[256] , int pixelIntensityGREEN[256] , int pixelIntensityBLUE[256];
   int i , j;
   
   fopen(fileIMG);
   size=getSizePicture(fileIMG);
   
   matrixRED=(*int)malloc(size.width*sizeof(int)); //matrix 1 dimension ...
   for(i=0 ; i<size.heigth ; i++)
   *matrixRED[i]=(*int)malloc(sizeof(int)); // grow up into matrix with 2 dimensions
   
         matrixGREEN=(*int)malloc(size.width*sizeof(int)); 
         for(i=0 ; i<size.height ; i++)
         *matrixGREEN[i]=(*int)malloc(sizeof(int)); 
         
   matrixBLUE=(*int)malloc(size.width*sizeof(int)); 
   for(i=0 ; i<size.height ; i++)
   *matrixBLUE[i]=(*int)malloc(sizeof(int));
      
   for(i=0 ; i<size.wdith ; i++){ // scan the whole matrix : 1rst Red
      for(j=0; j<size.height ; j++)
         fscanf(fileIMG , "%d" , matrixRED[i][j]);
   }
   for(i=0 ; i<size.wdith ; i++){ // scan the whole matrix : 2nd green
      for(j=0; j<size.height ; j++)
         fscanf(fileIMG , "%d" , matrixGREEN[i][j]);
   }
   for(i=0 ; i<size.wdith ; i++){ // scan the whole matrix : 3th blue
      for(j=0; j<size.height ; j++)
         fscanf(fileIMG , "%d" , matrixBLUE[i][j]);
   }
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
void createHistogramm(){
  
}

/**
*Print the image's histogramm.
* his function permit to watch the percentage about pixel's value.
*/
void printHistogramm() {
  
}
