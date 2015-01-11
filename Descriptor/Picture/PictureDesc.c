#include "PictureDesc.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>


Dimension getSizePicture(FILE *fileIMG) {
   Dimension dim;

   fscanf(fileIMG,"%d", &(dim.width));
   fscanf(fileIMG,"%d", &(dim.height));
   return dim;
}
//===================================================================================================
IMGDesc createPictureDesc(FILE *file){
   IMGDesc imgDsc;
   int quantif = globs_nbWeightyBits;
   int nbVal;
   int *matrix;
   int bit[256]={0} ;
   int tmpBit;
   int i , j , tmpval=1;
   
   imgDsc.size=getSizePicture(file);
   fscanf(file, "%d" , imgDsc->nbcomp);
   matrix=(int*)malloc((imgDsc.size.width*imgDsc.size.height*imgDsc.nbcomp)*sizeof(int)); //matrix 1 dimension ...

   for(i=0 ; i<imgDsc.size.width*imgDsc.size.height ; i++){ // scan the whole matrix : 1rst Red , 2nd Green , 3th Blue : for nbrMAtrix=3
         tmpBit=0;
         fscanf(file , "%d" , matrix+i); // on RED matrix
         fscanf(file , "%d" , matrix+1*imgDsc.size.height*imgDsc.size.height+i); // on GREEN matrix
         fscanf(file , "%d" , matrix+2*imgDsc.size.height*imgDsc.size.height+i); // on BLUE matrix

         while(quantif > 0) {
               for(j=0 ; j<imgDsc.nbcomp ; j++){
                  matrix[j*imgDsc.size.height*imgDsc.size.width+i] %= ((int)(255/tmpval) + (tmpval!=1) ); //+ tmpval!=1 : differentiate 127 of 128, because (int)255/2=127, but bit2=1 if number is a modulo of 128, not 127
                  tmpBit+= pow(2,2*j+quantif-1);
               }
               
            quantif--;
            tmpval++;
         /*For example (255,128,16) and quantif=2 and nbrMatrix3(RED,GREEN,BLUE)
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
   nbVal=pow(2,globs_nbWeightyBits*imgDsc.nbcomp);
   (*imgDsc)->histogram=(float*)malloc(nbVal*sizeof(float));
   for(i=0 ; i<nbVal ; i++)
      imgDsc->histogram[i] = (float)bit[i] / ((float)(imgDsc.size.height*imgDsc.size.width)); // give a percentage about IntensityValuePixel on numberPixel.
      
   return imgDsc;
}
//===================================================================================================
/**
*Print the image's histogram.
* his function permit to watch the percentage about pixel's value.
*/
void printHistogram(char path[]) {
   int i=0 , j , size1 , size2 , size , id , nbcp;
   int NbIntensity= pow(2,3*globs_nbWeightyBits); // if globs_nbWeightyBits=2 --> 2^(3*2)=64
   float array[NbIntensity]; // percentage given of descriptIMG
   char c;
   FILE *file=fopen(path , "r");
   
   fscanf(file , "%d" , &id);
   fscanf(file , "%d" , &size1);
   fscanf(file , "%d" , &size2);
   fscanf(file , "%d" , &nbcp);
   size = size1*size2;

   for(i=0 ; i< NbIntensity ; i++) // get back histogram datas.
      fscanf(file , "%f" , array+i);
      

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
}
//===================================================================================================
void printIMGDesc(IMGDesc desc){
   int dim = pow(2,globs_nbWeightyBits*imgDsc.nbcomp);
   int i;
   printf("ID:%l \tsize:%dx%d \tNbComposants:%d\n", desc.ID , desc.size.height , desc.size.width , desc.nbcomp);
   for(i=0 ;i<dim ;i++)
      printf("%f" , desc->histogram[i]);
   printf("\n");
}
//===================================================================================================
void writeIMGDesc(FILE* file, IMGDesc* desc){
   int i, nbcp = desc->nbcomp;
	
	writeStruct(file, &desc->ID, sizeof(desc->ID));
	writeStruct(file, &desc->(size.height), sizeof(desc->(size.height)));
	writeStruct(file, &desc->(size.width), sizeof(desc->(size.width)));
	writeStruct(file, &desc->nbcomp, sizeof(int));
	for(i = 0; i < nbcomp; i++)
		writeStruct(file, desc->histogram[i], sizeof(float));
}
//===================================================================================================
IMGDesc readIMGDesc(FILE* file){
   IMGDesc desc;
   int i , max;
   fscanf(file,"%l" , desc->ID);
   fscanf(file,"%d" , desc->(size.height));
   fscanf(file,"%d" , desc->(size.width));
   fscanf(file,"%d" , desc->nbcomp);
   max=pow(2,globs_nbWeightyBits*desc.nbcomp);
   for(i=0 ; i<max ; i++)
      fscanf(file,"%f" , desc->histogram[i]);
   
   return desc
}
