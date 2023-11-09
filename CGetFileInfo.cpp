#include <iostream>
#include <stdio.h>
#include "CGetFileInfo.h"

using namespace std;


CGetFileInfo::CGetFileInfo(const char* fileName)
{
    m_fileName = fileName;
    if(lstat(m_fileName, &m_statBuf) == -1) {
        cout << "stat error" << endl;
    }
}

CGetFileInfo::~CGetFileInfo()
{
}

void CGetFileInfo::GeiFileSize()
{
    m_fileSize = m_statBuf.st_size;
    cout << "m_fileSize: " << m_fileSize << endl;
}