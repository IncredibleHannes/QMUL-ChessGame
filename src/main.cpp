#include <iostream>
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

#include "Model/Board.h"

#define UNUSED(x) (void)x;

void handler(int sig) {
  const int items = 10;
  void* array[items];
  size_t size;

  size = backtrace(array, items);

  std::cout << "ERROR: Encountered signal " << sig << std::endl;

  backtrace_symbols_fd(array, size, STDERR_FILENO);

  exit(1);
}

int main(int argc, char const *argv[]) {
  signal(SIGSEGV, handler);

  Board *board = new Board();
  UNUSED(board)

  return 0;
}
