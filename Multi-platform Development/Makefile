build: tema1

tema1: tema1.obj
	link /nologo /out:tema1.exe compare.lib tema1.obj

tema1.obj: tema1.c
	cl /W3 /D_CRT_SECURE_NO_DEPRECATE /c /MD tema1.c

clean:
	del *.obj, tema1.exe
