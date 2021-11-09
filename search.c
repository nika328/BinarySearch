#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <stdio.h>
/*Name: Nikola Davidová 
  Last revision: 2021-06-08

  Program 02
  
  The Item Search: 
  - The function to search an item in a sorted file, which first value is the number of items
  - Input from user, a text file
  - Input from user, the searched item
  - Output: Whether the item was found, if so, the position is printed

*/

int main(void) {
  //Input from the user
  char file [100];
  printf("Write the name and location of the text file: ");
  scanf("%s", file);
  int item;
  printf("\nWrite the item you want to search: ");
  scanf("%d", &item);

  //File opening
  FILE* thefile;
  thefile=fopen(file, "r+"); 
    if (thefile==NULL)
    {
      printf("\nThe file cannot be open");
    }
    else{ printf("\nOpening successful\n");}
 
  //Creating an array for the numbers
  int stop; 
  fscanf(thefile,"%d",&stop );
  int numbers[stop];
  
  for (int i = 0; i < stop; i++)
    {
      fscanf(thefile, "%d", &numbers[i]);
    }
  //Check (if you want to see the array)
   /* printf("\n");
    for (int i = 0; i < stop; i++)
      {
        printf("%d ", numbers[i]);
      }
    */

  //The algorithm itself
  int start=0;
  int middle;
  while(stop>=start)
  {
    middle=(start+stop)/2;
    if(numbers[middle]==item)
    {
      printf("\nThe item is found at the position %d ", middle);
      return 0;
    }
    else if(numbers[middle]>item)
      {
          stop=middle-1;
      }
    else
      {
        start=middle+1;
      }
  }
  printf("\nThe item is not found");

  fclose(thefile);
  return 0;
}

    return 0;
  }
