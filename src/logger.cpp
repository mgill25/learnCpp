#include <iostream>
#include "log.h"
#include "common.h"

void Log(const char* message) {
    std::cout << message << std::endl;
}

void InitLog() {
    Log("Initialized the log");
}

void MyLog::SetLevel(LogLevel level)
{
    m_LogLevel = level;
}

void MyLog::Warn(const char* message)
{
    if (m_LogLevel >= LevelWarning)
        std::cout << "[WARNING]: " << message << std::endl;
}

void MyLog::Error(const char* message)
{
    if (m_LogLevel >= LevelError)
        std::cout << "[ERROR]: " << message << std::endl;
}

void MyLog::Info(const char* message)
{
    if (m_LogLevel >= LevelInfo)
        std::cout << "[INFO]: " << message << std::endl;
}