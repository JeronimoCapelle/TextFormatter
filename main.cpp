#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream file("input.txt", std::ios_base::in);
  char c = 0;
  char andCount = 0;
  int hits = 0;

  std::cout << "Starting" << std::endl;

  while (file.get(c)) {

    switch (c) {
    case ' ':
      if (andCount == 0 || andCount == 3) {
        andCount++;
      } else {
        andCount = 0;
      }
      break;

    case '&':
      if (andCount == 1 || andCount == 2) {
        andCount++;
      } else {
        andCount = 0;
      }
      break;

    default:
      andCount = 0;
      break;
    }

    if (andCount == 4) {
      hits++;
      std::cout << "Found a match: " << hits << std::endl;
      andCount = 0;
    }
  }
  return 0;
}