#include <iostream>
#include "CListDirCont.h"
#include "CGetFileInfo.h"

using namespace std;

CListDirCont::CListDirCont()
{
    dir = opendir("./");
    totalFile = 0;
    if(dir == NULL) {
        cout << "error opendir" << endl;
    }
    cout << "success opendir" << endl;
}

CListDirCont::~CListDirCont()
{
    if(closedir(dir) == -1) {
        cout << "error closedir" << endl;
    }
    cout << "success closedir" << endl;
}

CListDirCont& CListDirCont::GetInstance()
{
    static CListDirCont m_dp;
    return m_dp; 
}

void CListDirCont::ListDirCont()
{
    struct  dirent  *ptr;
    while((ptr=readdir(dir))!=NULL)
    {
        CGetFileInfo fd(ptr->d_name);
        fd.PrintFileInfo();
        totalFile++;
    }
    cout << "totalFile: " << totalFile << endl;
}