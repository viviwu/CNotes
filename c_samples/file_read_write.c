//
// Created by viviwu on 2022/4/12.
//

#include <stdio.h>


void file_write() {
  FILE *ofp;
  ofp = fopen("test.txt", "w");
  if (ofp) {
    fprintf(ofp, "Created by viviwu on 2022/4/12.\n");          // override
    fputs("append next line \n", ofp);         // append
    fclose(ofp);
  }

}

void file_read() {
  FILE *fp = NULL;
  char buff[255];

  fp = fopen("test.txt", "r");
  if (fp) {
    fscanf(fp, "%s", buff);
    printf("1: %s\n", buff);

    fgets(buff, 255, (FILE *) fp);
    printf("2: %s\n", buff);

    fgets(buff, 255, (FILE *) fp);
    printf("3: %s\n", buff);
    fclose(fp);
  }

}

int main() {
  //file_write();
  file_read();
}