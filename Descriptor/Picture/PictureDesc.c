/**
 * \file PictureDesc.c
 * \brief picture desc
 * \author Gabriel.DR
 * \version 0.95
 * \date 29 November 2014
 *
 */

#include "PictureDesc.h"
extern int globs_nbWeightyBits;


PictureDesc * createPictureDesc(FILE *file){
   int nbc ;
   int *matrix ;
   int sizeH , sizeW , nbComp; 
   int bit[256]={0} ;
   int tmpBit;
   int nbrPixel;
   int i , j , k , pos=0 , tmpval=1;
   PictureDesc *imgdesc;

   fscanf(file , "%d" , &((*imgdesc).size.height) );
   fscanf(file , "%d" , &((*imgdesc).size.width) );
   fscanf(file , "%d" , &((*imgdesc).nbcomp) );
   sizeH=(*imgdesc).size.height; // only to have a best code, more understandable
   sizeW=(*imgdesc).size.width;
   nbComp=(*imgdesc).nbcomp;
   nbc=nbComp;
   nbrPixel=pow(2,globs_nbWeightyBits*nbComp);

   matrix=(int*)malloc((sizeW*sizeH*nbComp)*sizeof(int)); //matrix 1 dimension ...

	while(!feof(file)){
             fscanf(file , "%d" , matrix+i);
		if(matrix[i]>255 || matrix[i]<0){fprintf(stderr,"ERROR, false IMG\n"); exit(0);} // security
	     i++;
	}
	j=0;
	for(j; j<sizeH*sizeW ;j++){
		while(nbc>0) {
			for(k=1 ; k<=globs_nbWeightyBits; k++){
				if(matrix[j] >= ((int)255/k +(k!=1)) ){ // can differentiate 255, 128 , 64 ...
					matrix[j] -= ((int)255/k +(k!=1));
					pos+=pow(2,(nbc*globs_nbWeightyBits - k+1));
				}
			
			}
			nbc--;
		}
		nbc=nbComp;	
		bit[pos]++;
		pos=0;
	}

  for(i=0 ; i<sizeH*sizeW ; i++)
    imgdesc->histogram[i] = (float)bit[i] / ((float)(sizeH*sizeW)); // give a percentage about IntensityValuePixel on numberPixel.
   
  return imgdesc;
}
//===================================================================================================
/**
*Print the image's histogram.
* his function permit to watch the percentage about pixel's value.
*/
/*				-------> ONLY FOR DEBBUGGING <-------
void printHistogram(PictureDesc imgdesc) {
   int i=0 , j , size1 , size2 , size;
   int NbIntensity; // if globs_nbWeightyBits=2 --> 2^(3*2)=64
   float array[NbIntensity]; // percentage given of descriptIMG
   char c;
   NbIntensity= pow(2,imgdesc.nbcomp*globs_nbWeightyBits);

   printf("\n\t>=======================================<\n");
   for(i=0 ; i<NbIntensity/2 ; i++){ // printf the histigram
        printf("val%3d:" , i);                        for(j=0;j<array[i]*20 ; j++) printf("o");
        if(array[i]!=0 ){printf(" %2.2f" , array[i]); for(j=0;j<(1-array[i])*20 ; j++) printf(" ");} // give a visual graphic whose the value's size appear on 10 'o' at 100%
        else printf("     ");

        printf("val%3d:" , NbIntensity/2+i);         for(j=0;j<array[NbIntensity/2+i]*20 ; j++) printf("o");
        if(array[NbIntensity/2+i]!=0 ){printf(" %2.2f" , array[NbIntensity/2+i]);}
        else printf("     ");
        printf("\n");
   }
   printf("\n\t>======== %6d read pixels ========<\n" , size);
   fclose(file);
}*/
//===================================================================================================
void printPictureDesc(PictureDesc * desc){
   int dim = pow(2,(globs_nbWeightyBits*(*desc).nbcomp));
   int i;
   printf("ID:%ld \tsize:%dx%d \tNbComposants:%d\n", desc->ID , (*desc).size.height , (*desc).size.width , desc->nbcomp );
   for(i=0 ;i<dim ;i++)
      printf("%f" , (*desc).histogram[i] );
   printf("\n");
}
//===================================================================================================
void writePictureDesc(FILE* file, PictureDesc* desc){
   int i, max;
	fprintf(file, "%ld\n" , (*desc).ID);
	fprintf(file, "%d " , (*desc).size.height);
	fprintf(file, "%d " , (*desc).size.width);
	fprintf(file, "%d\n" , (*desc).nbcomp);	
	max=pow(2,globs_nbWeightyBits*(desc->nbcomp));
	for(i = 0; i <max; i++)
		fprintf(file , "%.2f " , (*desc).histogram[i]);

}
//===================================================================================================
PictureDesc* readPictureDesc(FILE* file){
   PictureDesc *desc;
   int i , max;
   fscanf(file,"%ld" , &((*desc).ID));
   fscanf(file,"%d" , &((*desc).size.height));
   fscanf(file,"%d" , &((*desc).size.width));
   fscanf(file,"%d" , &((*desc).nbcomp));
   max=pow(2,globs_nbWeightyBits*(*desc).nbcomp);
   for(i=0 ; i<max ; i++)
      fscanf(file,"%f" , (*desc).histogram[i]);
   
   return desc;
}
