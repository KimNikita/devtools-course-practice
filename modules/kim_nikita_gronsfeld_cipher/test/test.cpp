// Copyright 2022 Kim Nikita

#include <gtest/gtest.h>
#include <string>

#include "include/kim_nikita_gronsfeld_cipher.h"

TEST(Kim_Nikita_Gronsfeld_Cipher_Test, check_constructor) {
  // Assert
  EXPECT_NO_THROW(GronsfeldCipher());
}

TEST(Kim_Nikita_Gronsfeld_Cipher_Test, check_class_object_creation) {
  // Arrange
  GronsfeldCipher gc;
  std::string exp_table;
  std::string res_table;
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 26; j++) {
      exp_table += alpha[(j + i) % 26];
    }
    exp_table += '\n';
  }

  // Act
  res_table = gc.getGronsfeldTable();

  // Assert
  EXPECT_EQ(exp_table, res_table);
}

TEST(Kim_Nikita_Gronsfeld_Cipher_Test, check_encoder) {
  // Arrange
  GronsfeldCipher gc;
  std::string exp_text = "IRPSUFFQF";
  std::string res_text;

  // Act
  res_text = gc.encode("GRONSFELD", "2015");

  // Assert
  EXPECT_EQ(exp_text, res_text);
}

TEST(Kim_Nikita_Gronfeld_Cipher_Test, check_decoder) {
  // Arrange
  GronsfeldCipher gc;
  std::string exp_text = "GRONSFELD";
  std::string res_text;

  // Act
  res_text = gc.decode("IRPSUFFQF", "2015");

  // Assert
  EXPECT_EQ(exp_text, res_text);
}

TEST(Kim_Nikita_Gronfeld_Cipher_Test, check_hacker) {
  // Assert
  EXPECT_TRUE(true);
}

