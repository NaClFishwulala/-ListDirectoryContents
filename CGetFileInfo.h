#ifndef CGETFILEINFO_H
#define CGETFILEINFO_H
#include <sys/stat.h>
#include <string>

class CGetFileInfo
{
private:
    struct stat m_statBuf;
    const char* m_fileName;
    off_t m_fileSize;

    std::string m_fileInfo;

public:
    CGetFileInfo(const char* fileName);
    ~CGetFileInfo();

    void GeiFileSize();

};




#endif