#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   fseek(f, 0, SEEK_CUR);
   fwrite(& t, sizeof(t), 1, f);
}

template<typename T> T read(FILE* f)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   T t;

   fseek(f, 0, SEEK_CUR);

   fread(& t, sizeof(t), 1, f);

   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f, n*sizeof(T), SEEK_SET);
}

template<typename T> int fileSize(FILE* f)
{
   fseek(f, 0, SEEK_END);

   return ftell(f)/sizeof(T);
}

template<typename T> int filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}

#endif
