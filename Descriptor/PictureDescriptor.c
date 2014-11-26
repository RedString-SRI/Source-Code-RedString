#include "PictureDescriptor.h
"
/*Initialize a new picture's descriptor*/
void initPictureDescriptor(PictureDescriptor *pd) {
  
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

/**/
void setNbquantif(PictureDescritor *pd, int n) {
  pd->nbquantif = n;
}

/*return nbquantif*/
int getNbquantif(PictureDescritor pd ){
  return pd.nbquantif;
}

/*Creat the image's histogramm*/
void createHistogramm(){
  
}

/*Print the image's histogramm*/
void printHistogramm() {
  
}
