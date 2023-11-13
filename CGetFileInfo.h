#ifndef CGETFILEINFO_H
#define CGETFILEINFO_H
#include <sys/stat.h>
#include <string>

class CGetFileInfo
{
private:
    struct stat m_statBuf;
    std::string m_fileName;
    std::string m_fileType;
    std::string m_filePermission;
    off_t m_fileSize;
    std::string m_fileInfo;

public:
    CGetFileInfo(const char* fileName);
    ~CGetFileInfo();

    std::string GetFileType();
    std::string GetFilePermission();
    off_t GetFileSize();
    void PrintFileInfo();
};




#endif