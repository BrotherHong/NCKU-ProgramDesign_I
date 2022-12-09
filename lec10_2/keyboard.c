#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
  //freopen("../input.in", "r", stdin);
  char line[BUFFER_LEN];
  char buffer[LINE_LEN][BUFFER_LEN];
  char *arr[LINE_LEN];

  int count = 0;
  while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
    arr[count] = buffer[count];
    strncpy(buffer[count++], line, BUFFER_LEN - 1);
  }
  convert(arr, count);
  for (int i = 0; i < count; i++) {
    printf("%s", arr[i]);
  }
}

//

const char btn[] = "22233344455566677778889999";
const char times[] = "12312312312312312341231234";

void convert(char *arr[], int count){
    for (int i = 0;i < count;i++) {
        char result[BUFFER_LEN*4];
        int res_len = 0;

        char *p = arr[i];
        while (*p != '\n') {
            if (*p == ' ') {
                result[res_len++] = ' ';
            } else {
                int idx = *p - 'a';
                result[res_len++] = '(';
                result[res_len++] = btn[idx];
                result[res_len++] = ')';
                result[res_len++] = times[idx];
            }
            p++;
        }
        result[res_len++] = '\n';
        result[res_len] = '\0';
        strncpy(arr[i], result, res_len);
    }
}