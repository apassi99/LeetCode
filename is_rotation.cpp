#include <iostream>
#include <string.h>

bool is_rotation(const char*, const char*);

int main(int argc, char *argv[]) {

  if (argc != 3)
    return 0;

  char * str1 = argv[1];
  char * str2 = argv[2];

  std::cout << str1 << "  " << str2 << "\n";
  std::cout << "Is rotation? " << is_rotation(str1, str2) << "\n";
  return 0;
}

/* Compare lengths if they are equal
 * then str2 must be a substring of str1 + str1 */
bool is_rotation(const char* str1, const char* str2) {
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);

  if (len1 != len2)
    return false;

  char * new_str = (char *) malloc( (len1 + len1 + 1 ) * sizeof(char) );
  memcpy(new_str, str1, len1);
  memcpy(new_str + len1, str1, len1 + 1);

  std::string str(new_str);
  std::string cpy(str2);

  free(new_str);
  return  std::string::npos != str.find(cpy);
}
