#include "header-only/HeaderOnly.h"
#include "sample-class/SampleClass.h"

int main() {
  SampleClass printyPlease;
  Increment<unsigned> up;

  auto i = 0U;

  while (++i) {
    if (i % 1000)
      printyPlease.OkayIPrint();

    up.PlusPlus(i);
  }

  return 0;
}