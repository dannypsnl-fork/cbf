#include "fileutil.h"
#include "run.h"

int main(int argc, char *argv[]) {
  if (argc != 2)
    err("Usage: compiler-x64 <inputfile>");
  char *text_body = read_file(argv[1]);
  if (text_body == NULL)
    err("Unable to read file");
  run(text_body);
  free(text_body);
}
