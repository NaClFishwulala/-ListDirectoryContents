#include <iostream>
#include <stdio.h>

#include "CGetFileInfo.h"
#include "CListDirCont.h"

int main()
{
    CListDirCont& dp = CListDirCont::GetInstance();
    dp.ListDirCont();
    return 0;
}