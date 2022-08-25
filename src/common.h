#pragma once

#include "log.h"

class MyLog
{
public:
    enum LogLevel : unsigned char
    {
        LevelError = 0, LevelWarning, LevelInfo
    };
private:
    LogLevel m_LogLevel = LogLevel::LevelInfo;

public:
    void SetLevel(LogLevel level);
    void Warn(const char* message);
    void Error(const char* message);
    void Info(const char* message);
};