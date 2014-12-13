#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "math.h"

typedef struct{
  int height;
  int width;
}Dimension;

typedef struct{
  int id;
  Dimension size[2];
  int nbcomp ; /*d is the picture's number of components*/
  int *histogram; // Will be an array of size : 2^(d*n)

}PictureDescriptor;
//
//
//
int globs_nbWeightyBits=2; ///*USE A WRONG VARIABLE GLOBALE*/
//
//
//
Dimension getSizePicture(FILE *fileIMG);
void createPictureDescriptor(char path[]);
void createHistogram(FILE *file ,int bit[] , Dimension dim , int size);
void printHistogram(char path[]);
//===================================================================================================
//===================================================================================================
//===================================================================================================
int main()
{
   ///* CreateDescriptor manage getSizeDimension& createHistogramm
   char file[50]="fileTEST.txt";
   createPictureDescriptor(file); // during this function, concatanation : Test.txt -> descriptTest.txt
   printHistogram(file); // So, histogram of the descript

    return 0;
}
//===================================================================================================
//===================================================================================================
//===================================================================================================

//===================================================================================================
Dimension getSizePicture(FILE *fileIMG) {
   Dimension dim;

   fscanf(fileIMG,"%d", &(dim.width));
   fscanf(fileIMG,"%d", &(dim.height));
   return dim;
}
//===================================================================================================
void createPictureDescriptor(char path[]){
   int quantif = globs_nbWeightyBits;
   Dimension size;
   int *matrix ;
   int bit[256]={0} ;
   int tmpBit;
   int i , j , tmpval=1;
   int a; /// A ENLEVER
   char des[20]="descript";
   FILE *descriptIMG ;

   FILE *file=fopen(path, "r");
    printf("FILE OPEN \n");
   size=getSizePicture(file);
      printf("SIZE : %d %d\n" , size.height , size.width);
   matrix=(int*)malloc((size.width*size.height*3)*sizeof(int)); //matrix 1 dimension ...
    printf("MALLOC OK \n\n");
   for(i=0 ; i<size.width*size.height ; i++){ // scan the whole matrix : 1rst Red , 2nd Green , 3th Blue
    printf("=====LOOP %d \n" , i);
         tmpBit=0;
         fscanf(file , "%d" , matrix+i); // on RED matrix
         fscanf(file , "%d" , matrix+1*size.height*size.height+i); // on GREEN matrix
         fscanf(file , "%d" , matrix+2*size.height*size.height+i); // on BLUE matrix
        printf("3 GET OK \n");
         while(quantif > 0) {
                printf("==LOOP while \n");
                printf("CALCUL : %d ; %d ; %d\n" , matrix[i] , matrix[1*size.height*size.width+i] ,matrix[2*size.height*size.width+i]);
               matrix[i] %= (255/tmpval);
               matrix[1*size.height*size.width+i] %= ((int)(255/tmpval) + (tmpval!=1) ); //+ tmpval!=1 : differentiate 127 of 128, because (int)255/2=127, but bit2=1 if number is a modulo of 128, not 127
               matrix[2*size.height*size.width+i] %= ((int)(255/tmpval) + (tmpval!=1) );
            printf("CALCUL OK : %d ; %d ; %d\n" , matrix[i] , matrix[1*size.height*size.width+i] ,matrix[2*size.height*size.width+i]);
            if( matrix[i] == 0 ){printf("RED : 255/%d \n" , tmpval);
                tmpBit+= pow(2,3+quantif);} // on RED matrix, for example quantif=2 : modulo 128, 255
            if( matrix[1*size.height*size.width+i] == 0 ){printf("GREEN : 255/%d \n" , tmpval);
                tmpBit+= pow(2,1+quantif);} // on  GREEN matrix
            if( matrix[2*size.height*size.width+i] == 0 ){printf("BLUE : 255/%d \n" , tmpval);
                tmpBit+=1*pow(2,quantif-1);} // on BLUE matrix
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
         printf("EXIT WHILE==\n");
         printf("%d\n" , tmpBit);
         printf("bit %d\n" , bit[tmpBit-1]);
         bit[tmpBit-1]++;
         printf("bit %d\n\n" , bit[tmpBit-1]);
         quantif=globs_nbWeightyBits;
         tmpBit=0;
         tmpval=1;
    }
    printf("\nEXIT LOOP FOR=====\n");
    a=pow(2,globs_nbWeightyBits*3);
    for(i=0 ; i<a ; i++)
        printf("%d " , bit[i]);
        strcat(des,path);
        strcpy(path,des); //to use this new name descriptTest.txt for the fallowing function in the main function
        printf("%s\n" , des);
    descriptIMG = fopen(des , "w");
    fprintf(descriptIMG , "%s\n" , path);
    fprintf(descriptIMG , "0\n");
    fprintf(descriptIMG , "%s\n" , path);
    fprintf(descriptIMG , "%s\n" , path);
    fprintf(descriptIMG , "%s\n\n" , path);
    fprintf(descriptIMG , "%d %d\n" , size.height , size.width);
    createHistogram( descriptIMG , bit, size , pow(2,globs_nbWeightyBits*3));

   fclose(file);
   fclose(descriptIMG);
}

//===================================================================================================
/**
 *Create an histogramm with the 64 values possibles.
 * It give the number of picture's pixel which have an intensity value : red, blue, green or gray level.
 */
void createHistogram(FILE *file ,int bit[], Dimension dim , int size){
    float tab[size]; // 3 colors of Nquantif bits
    int i;

    printf("\nSIZE : %d\n" , size);
    printf("=====ENTER IN CREATE HISTO=====\n");
  for(i=0 ; i<size ; i++){
    printf("%d bit : %d\t\t" ,i, bit[i]);
    tab[i] = (float)bit[i] / ((float)(dim.height*dim.width)); // give a percentage about IntensityValuePixel on numberPixel.
    printf("tab : %.2f\n" , tab[i]);
    fprintf(file , "%.2f\t" , tab[i]);
  }
  printf("=====END CREATE HISTO=====\n");
}
//===================================================================================================
/**
*Print the image's histogram.
* his function permit to watch the percentage about pixel's value.
*/
void printHistogram(char path[]) {
   int i=0 , j , NbIntensity , size1 , size2 , size;
   float *array; // percentage given of descriptIMG
   char c;
   FILE *file=fopen(path , "r");
   NbIntensity= pow(2,3*globs_nbWeightyBits); // if globs_nbWeightyBits=2 --> 2^(3*2)=64
   array = (float*)malloc(NbIntensity*sizeof(float));
   printf("%d\n" , NbIntensity);

// Permit to place himself at the 7th lines, where the histogram's array start and the sizes.
            // read a line and economise memories
        while((c = fgetc(file)) && (i<5)){
                putchar(c);
                if(c=='\n') i++;
            }
   fscanf(file , "%d" , &size1);
   fscanf(file , "%d" , &size2);
   size = size1*size2;
    printf("%d %d=%d\n" , size1 , size2 , size);
   for(i=0 ; i< NbIntensity ; i++) // get back histogram datas.
      {fscanf(file , "%f" , array[i]); printf("%f " , array[i]);}
   printf("\n\t>=======================================<\n" , size);
   for(i=0 ; i<NbIntensity/2 ; i++){ // printf the histigram
      printf("val%3d:" , i+1);   for(j=0;j<array[i]*10 ; j++) printf('o');
      printf("%d" , array[i]);   for(j=0;j<(1-array[i])*10 ; j++) printf(' '); // give a visual graphic whose the value's size appear on 10 'o' at 100%
       printf("val%3d:" , NbIntensity/2+i);   for(j=0;j<array[NbIntensity/2+i-1]*10 ; j++) printf('o');
      printf("%d" , array[NbIntensity/2+i-1]);   for(j=0;j<(1-array[NbIntensity/2+i-1])*10 ; j++) printf(' ');
   }
   printf("\n\t>======== On %6d read pixels ========<\n" , size);
   fclose(file);
}
