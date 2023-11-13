#include <iostream>
#include <stdio.h>
#include "CGetFileInfo.h"

using namespace std;



CGetFileInfo::CGetFileInfo(const char* fileName)
{

    if(lstat(fileName, &m_statBuf) == -1) {
        cout << "stat error" << endl;
    }
    m_fileName = fileName;
    GetFileSize();
    GetFileType();
    GetFilePermission();
    m_fileInfo = "FileName: " + m_fileName + "  FileType: " + m_fileType + "  FilePermission: " + m_filePermission + "  FileSize: " + to_string(m_fileSize);
}

CGetFileInfo::~CGetFileInfo()
{
}

std::string CGetFileInfo::GetFileType()
{
    if(S_ISREG(m_statBuf.st_mode)) {
        m_fileType = "REG";
    }else if(S_ISDIR(m_statBuf.st_mode)) {
        m_fileType = "DIR";
    }else if(S_ISCHR(m_statBuf.st_mode)) {
        m_fileType = "CHR";
    }else if(S_ISBLK(m_statBuf.st_mode)) {
        m_fileType = "BLK";
    }else if(S_ISFIFO(m_statBuf.st_mode)) {
        m_fileType = "FIFO";
    }else if(S_ISSOCK(m_statBuf.st_mode)) {
        m_fileType = "SOCK";
    }else if(S_ISLNK(m_statBuf.st_mode)) {
        m_fileType = "LINK";
    }
    return m_fileType;
}

std::string CGetFileInfo::GetFilePermission()
{
    if(m_statBuf.st_mode & S_IRUSR) {
        m_filePermission = "r";
    }else {
        m_filePermission = "-";
    }
    if(m_statBuf.st_mode & S_IWUSR) {
        m_filePermission += "w";
    }else {
        m_filePermission += "-";
    }
    if(m_statBuf.st_mode & S_IXUSR) {
        m_filePermission += "x";
    }else {
        m_filePermission += "-";
    }
    if(m_statBuf.st_mode & S_IRGRP) {
        m_filePermission += "r";
    }else {
        m_filePermission += "-";
    }
    if(m_statBuf.st_mode & S_IWGRP) {
        m_filePermission += "w";
    }else {
        m_filePermission += "-";
    }
    if(m_statBuf.st_mode & S_IXGRP) {
        m_filePermission += "x";
    }else {
        m_filePermission += "-";
    }
    if(m_statBuf.st_mode & S_IROTH) {
        m_filePermission += "r";
    }else {
        m_filePermission += "-";
    }
    if(m_statBuf.st_mode & S_IWOTH) {
        m_filePermission += "w";
    }else {
        m_filePermission += "-";
    }
    if(m_statBuf.st_mode & S_IXOTH) {
        m_filePermission += "x";
    }else {
        m_filePermission += "-";
    }

    return m_filePermission;
}

off_t CGetFileInfo::GetFileSize()
{
    m_fileSize = m_statBuf.st_size;
    return m_fileSize;
}

void CGetFileInfo::PrintFileInfo()
{
    cout << m_fileInfo << endl;
}