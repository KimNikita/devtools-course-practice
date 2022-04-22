// Copyright 2022 Kim Nikita

#ifndef MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_
#define MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_

#include <string>

class GronsfeldCipher {
private:
  char table[10][26];
public:
  GronsfeldCipher();
  std::string getGronsfeldTable();
  std::string encode(std::string source_text, std::string key);
  std::string decode(std::string ciphered_text, std::string key);
  std::string hack(std::string ciphered_text);
};

#endif  // MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_
