#include "DescriptIMG.h"


Dimension getSizePicture(FILE *fileIMG) {
   Dimension dim;

   fscanf(fileIMG,"%d", &(dim.width));
   fscanf(fileIMG,"%d", &(dim.height));
   return dim;
}
//===================================================================================================
IMGdesc createPictureDesc(FILE *file){
   IMGdesc imgDsc;
   int quantif = globs_nbWeightyBits;
   int bit[256]={0} ;
   int *matrix
   int tmpBit;
   int i , j , tmpval=1;
   FILE *descriptIMG;
   char des[20]="descript"; // Comment créer le nom du desc, je ne connais plus du coup le nom du fichier cible ??????
   /**
    * ?????????????????????????????????????
   */
   
   imgDsc.dim=getSizePicture(file);
   matrix=(int*)malloc((size.width*size.height*3)*sizeof(int)); //matrix 1 dimension ...

   for(i=0 ; i<size.width*size.height ; i++){ // scan the whole matrix : 1rst Red , 2nd Green , 3th Blue
         tmpBit=0;
         fscanf(file , "%d" , matrix+i); // on RED matrix
         fscanf(file , "%d" , matrix +1*imgDsc.dim.height*imgDsc.dim.height+i); // on GREEN matrix
         fscanf(file , "%d" , matrix +2*imgDsc.dim.height*imgDsc.dim.height+i); // on BLUE matrix

         while(quantif > 0) {
               matrix[i] %= (255/tmpval);
               matrix[1*imgDsc.dim.height*imgDsc.dim.width+i] %= ((int)(255/tmpval) + (tmpval!=1) ); //+ tmpval!=1 : differentiate 127 of 128, because (int)255/2=127, but bit2=1 if number is a modulo of 128, not 127
               matrix[2*imgDsc.dim.height*imgDsc.dim.width+i] %= ((int)(255/tmpval) + (tmpval!=1) );

            if( matrix[i] == 0 )
                tmpBit+= pow(2,3+quantif); // on RED matrix, for example quantif=2 : modulo 128, 255
            if( matrix[1*imgDsc.dim.height*imgDsc.dim.width+i] == 0 )
                tmpBit+= pow(2,1+quantif); // on  GREEN matrix
            if( matrix[2*imgDsc.dim.height*imgDsc.dim.width+i] == 0 )
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
    strcat(des,path);
    descriptIMG = fopen(des,"w");
    fprintf(descriptIMG , "%l\n" , getNewID(IMAGE) ); // HOW IT'S GENERATE ????????????? !§!!!!!!
    fprintf(descriptIMG , "%d %d\n" , imgDsc.dim.height , imgDsc.dim.width);

    createHistogram( descriptIMG , bit, &imgDsc , pow(2,globs_nbWeightyBits*3) );

return imgDesc;
}

//===================================================================================================
/**
 *Create an histogramm with the 64 values possibles.
 * It give the number of picture's pixel which have an intensity value : red, blue, green or gray level.
 */
void createHistogram(FILE *file ,int bit[], IMGdesc *imgDsc , int size){
    int i;
    imgDsc->histogram=(float*)malloc(size*sizeof(float)); // 3 colors of Nquantif bits

  for(i=0 ; i<size ; i++){
    imgDsc->histogram[i] = (float)bit[i] / ((float)((*imgDsc).dim.height * (*imgDsc).dim.width)); // give a percentage about IntensityValuePixel on numberPixel.
    fprintf(file , "%.2f\t" , img->histogram[i]);
  }
}
//===================================================================================================
/**
*Print the image's histogram.
* his function permit to watch the percentage about pixel's value.
*/
void printHistogram(FILE *file) {
   int i=0 , j , size1 , size2 , size;
   int NbIntensity= pow(2,3*globs_nbWeightyBits); // if globs_nbWeightyBits=2 --> 2^(3*2)=64
   float array[NbIntensity]; // percentage given of descriptIMG
   char c;

   fscanf(file , "%d" , &size1);
   fscanf(file , "%d" , &size2);
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
}
