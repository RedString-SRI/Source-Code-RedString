#include<stdio.h>
#include<string.h>

void clearBuffer() {
int c = 0;
while (c != '\n' && c != EOF)
c = getchar();
}

void initStack(DescriptorBase *p) {
  
}


BOOL pathExist(char[] path) {
  int answer;
  char sentence[50]="[ ! -f ";
  char sentenceEnd[5]=" ]";
  strcat(sentence,path);
  strcat(sentence,sentenceEnd);
  answer=system(sentence);
  if(answer==0)
    return FALSE;
  else
    return TRUE;
}
