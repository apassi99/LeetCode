#include <iostream>
#include <stdlib.h> 


unsigned int my_strlen(const char *);
void string_reverse1(char *);
char *string_reverse2(const char *);

int main() {

  char str[] = "Arjun";
  std::cout << "Len of '" << str << "' is " << my_strlen(str) << "\n"; 

  char * rstr = string_reverse2(str);

  std::cout << "Len of '" << rstr << "' is " << my_strlen(rstr) << "\n";

  string_reverse1(str);
  std::cout << "Len of '" << str << "' is " << my_strlen(str) << "\n"; 

  return 0;
}

unsigned int my_strlen(const char *str) {
  if (str == NULL)
     return 0;

  int count = 0;

  while (str[count] != '\0') {
    count++;
  }

  return count;
}

/* In place string reversal */
void string_reverse1(char *str) {
  unsigned int len = my_strlen(str);

  int i1 = 0;
  int i2 = len - 1;

  while (i1 < i2) {
    str[i1] = str[i1] ^ str[i2];
    str[i2] = str[i1] ^ str[i2];
    str[i1] = str[i1] ^ str[i2]; 
    i1++;
    i2--;
  }
}

char *string_reverse2(const char * str) {
  unsigned int len = my_strlen(str);
  char * cpy = (char *) malloc(len * sizeof(char *));

  int count = 0;
  for (int i = len - 1; i >= 0; i--) {
    cpy[count] = str[i];
    count++;
  }

  cpy[len] = '\0';
  return cpy;
}
