HELLO:CLEAN
  CL.EXE -c hello.c
  RC.EXE hello.rc
  LINK.EXE hello.obj hello.res user32.lib
CLEAN:
  del *.obj
  del *.res
  del *.exe