#include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <unistd.h>

 #include "linux_ssd1306_ioctl.h"
 
 int main()
 {
    int fd;
    int line = 0;                             /*line to clear*/

    fd = open("/dev/ssd130601", O_RDWR);
    if (fd == -1){
        printf("Error while opening the display\n");
        return -1;
    }

    /*create struct and initialize the necessary fields for calling the underlying function.
    required args:
    int page;
    char *text;
    int text_len;
    bool invert;
    */

    static struct function_args args = {
      .page = line;                         /*line to write*/
      .text = "it works!";                  /*text to write*/
      .text_len = 9;                        /*text lenght*/
      .invert = 0;                           /*dont invert display*/
    }

    ioctl(fd, SSD1306_DISPLAY_TEXT_X3, (unsigned long)&args);    /*pass pointer to structure as unsigned long */
    close(fd);

    printf("Line %d cleared.", line);
    return 0;
 }