#ifndef CLISTDIRCONT_H
#define CLISTDIRCONT_H
#include <dirent.h>

class CListDirCont
{
private:
    DIR* dir;
    unsigned int totalFile;

private:
    CListDirCont();
    ~CListDirCont();
public:
    static CListDirCont& GetInstance();
    void ListDirCont();
};

#endif