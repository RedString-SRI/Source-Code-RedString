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
   int tmpval=1 ;
   int *matrix ;
   int sizeH , sizeW , nbComp; 
   int bit[256]={0} ;
   int tmpBit;
   int nbrPixel;
   int i , j , k , pos=0 , tmpval=1;
   PictureDesc *imgdesc;
   int quantif=globs_nbWeightyBit;;
   
   fscanf(file , "%d" , &((*imgdesc).size.width) );
   fscanf(file , "%d" , &((*imgdesc).size.height) );
   fscanf(file , "%d" , &((*imgdesc).nbcomp) );
   sizeH=(*imgdesc).size.height; // only to have a better code, more understandable
   sizeW=(*imgdesc).size.width;
   nbComp=(*imgdesc).nbcomp;
   nbc=nbComp;
   nbrPixel=pow(2,globs_nbWeightyBits*nbComp);
   
   
   matrix=(int*)malloc((size.width*size.height*3)*sizeof(int)); //matrix 1 dimension ...

   for(i=0 ; i<sizeW*sizeH ; i++){ // scan the whole matrix : 1rst Red , 2nd Green , 3th Blue
         tmpBit=0;
         fscanf(file , "%d" , matrix+i); // on RED matrix
         fscanf(file , "%d" , matrix+1*sizeW*sizeH+i); // on GREEN matrix
         fscanf(file , "%d" , matrix+2*sizeW*sizeH+i); // on BLUE matrix

         while(quantif > 0) {
               matrix[i] %= (255/tmpval);
               matrix[1*sizeH*sizeW+i] %= ((int)(255/tmpval) + (tmpval!=1) ); //+ tmpval!=1 : differentiate 127 of 128, because (int)255/2=127, but bit2=1 if number is a modulo of 128, not 127
               matrix[2*sizeH*sizeW+i] %= ((int)(255/tmpval) + (tmpval!=1) );

            if( matrix[i] == 0 )
                tmpBit+= pow(2,3+quantif); // on RED matrix, for example quantif=2 : modulo 128, 255
            if( matrix[1*sizeH*sizeW+i] == 0 )
                tmpBit+= pow(2,1+quantif); // on  GREEN matrix
            if( matrix[2*sizeH*sizeH+i] == 0 )
                tmpBit+=1*pow(2,quantif-1); // on BLUE matrix

            quantif--;
            tmpval++;
         /*For example (255,128,16) and quantif=2
          * 1rst round:quantif=2 & tmpval=1 --> matRED[]%255=0 --> tmpBit=32
          *                                 --> matGREEN[]%255=128 --> tmpBIT=32
          *                                 --> matBLUE[]%255=16 --> tmpBIT=32
          * 2nd round:quantif=1 & tmpval=2 --> matRED[]%128=0 --> tmpBit=32
          *                                 --> matGREEN[]%128=0 --> tmpBIT=36
          *                                 --> matBLUE[]%255=16 --> tmpBIT=36
          *--> bit[36-1]++
          */
         }
         bit[tmpBit]++;
         quantif=globs_nbWeightyBits;
         tmpBit=0;
         tmpval=1;
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
