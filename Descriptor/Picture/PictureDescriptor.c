#include "PictureDescriptor.h
"
/*Initialize a new picture's descriptor*/
PictureDescriptor PictureDescriptor(FILE* file) {
   int pd->id=;
  Mode pd->writingMode=AUTO;
  int pd->nbcomp = 0;
  int pd->nbquantif =64;
  int pd->*histogram=NULL;
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
