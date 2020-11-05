target("console")
  set_kind("binary")
  add_cflags("-std=c11")
  add_files("src/*.c")
