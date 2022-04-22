// Copyright 2022 Kim Nikita

#include <string>

#include "include/kim_nikita_gronsfeld_cipher.h"

GronsfeldCipher::GronsfeldCipher() {
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 26; j++) {
      table[i][j] = alpha[(j + i) % 26];
    }
  }
}

std::string GronsfeldCipher::getGronsfeldTable() {
  std::string gronsfeld_table = "";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 26; j++) {
      gronsfeld_table += table[i][j];
    }
    gronsfeld_table += '\n';
  }
  return gronsfeld_table;
}

std::string GronsfeldCipher::encode(std::string source_text, std::string key) {
  // check key
  std::string ciphered_text = "";
  std::string period_key = "";

  int size = source_text.size();
  int period = key.size();

  char pos_A = 'A';
  char pos_Zero = '0';

  for (int i = 0; i < size; i++) {
    period_key += key[i % period];
  }

  for (int i = 0; i < size; i++) {
    ciphered_text += table[period_key[i] - pos_Zero][source_text[i] - pos_A];
  }

  return ciphered_text;
}

std::string GronsfeldCipher::decode(
  std::string ciphered_text, std::string key) {
  // check key
  std::string source_text = "";
  std::string period_key = "";

  int size = ciphered_text.size();
  int period = key.size();

  char pos_Zero = '0';

  for (int i = 0; i < size; i++) {
    period_key += key[i % period];
  }

  for (int i = 0; i < size; i++) {
    int j = 0;
    int k = period_key[i] - pos_Zero;
    while (table[k][j] != ciphered_text[i]) {
      j++;
    }
    source_text += table[k][j];
  }

  return source_text;
}

std::string GronsfeldCipher::hack(std::string ciphered_text) {
  return ciphered_text;
}
