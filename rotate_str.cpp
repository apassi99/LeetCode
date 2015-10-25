#include <iostream>
#include <stdlib.h> 

void rotate_str_left1(char *, unsigned int);
void rotate_str_left2(char *, unsigned int);
void string_reverse1(char *, int, int);
unsigned int my_strlen(const char *);

int main() {
	char str [] = "arjun passi";
	rotate_str_left1(str, 5);

	std::cout << "Rotate str is '" << str << "'" << "\n"; 

	char str1 [] = "arjun";
	rotate_str_left1(str1, 4);

	std::cout << "Rotate str1 is '" << str1 << "'" << "\n"; 

	char str2 [] = "arjun";
	rotate_str_left2(str2, 5);

	std::cout << "Rotate str2 is '" << str2 << "'" << "\n"; 


	char str3 [] = "arjun passi";
	rotate_str_left2(str3, 5);

	std::cout << "Rotate str3 is '" << str3 << "'" << "\n";

	char str4 [] = "a";
	rotate_str_left2(str4, 1);

	std::cout << "Rotate str4 is '" << str4 << "'" << "\n"; 

	char str5 [] = "arjun";
	rotate_str_left2(str5, 2);

	std::cout << "Rotate str5 is '" << str5 << "'" << "\n"; 

	char str6 [] = "arjun";
	rotate_str_left2(str6, 3);

	std::cout << "Rotate str6 is '" << str6 << "'" << "\n"; 

	return 0;
}

/* O(n^k) solution */
void rotate_str_left1(char * str, unsigned int k) {
	
	unsigned int len = my_strlen(str);

	if (len <= 0)
		return;

    k = k % len;

	while (k) {
		int count = 0;
		char temp = str[count];
		while (count != len) {
			str[count] = (count == len - 1) ? temp : 
						  str[(count + 1) % len];
			count++;
		}
		k--;
	}
}

// Rotate arjun by 2 is junar
// Reverse arjun -> nujra
// Reverse "nuj" and "ra"
void rotate_str_left2(char * str, unsigned int k) {
	unsigned int len = my_strlen(str);

	if (!len)
		return;

	k = k % len;

	if (!k)
		return;

	k = (len - k) - 1;
	string_reverse1(str, 0, len - 1);
	string_reverse1(str, 0, k);
	string_reverse1(str, k + 1, len - 1);
}

/* In place string reversal */
void string_reverse1(char *str, int l, int h) {

  while (l < h) {
    str[l] = str[l] ^ str[h];
    str[h] = str[l] ^ str[h];
    str[l] = str[l] ^ str[h]; 
    l++;
    h--;
  }
}

unsigned int my_strlen(const char *str) {
  if (str == NULL)
     return 0;

  unsigned int count = 0;

  // count will overflow if len of str is
  // greater than 2^32
  while (str[count] != '\0') {
    count++;
  }

  return count;
}