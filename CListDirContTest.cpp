#include <iostream>
#include <stdio.h>

#include "CGetFileInfo.h"

#define FILENAME "../readfile.txt"

int main()
{
    const char* fileName = FILENAME;
    CGetFileInfo fd(fileName);
    fd.GeiFileSize();
    return 0;
}