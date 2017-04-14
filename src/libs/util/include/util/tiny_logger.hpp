#pragma once

#include <memory>
#include <vector>
#include <ostream>
#include <sstream>
#include <iostream>


enum LogLevel
{
    FATAL,
    ERROR,
    WARNING,
    INFO,
    VERBOSE,
    DEBUG,
};

class LogMessage
{
public:
    LogMessage(LogLevel level, const char *file, int line, const char *func, std::ostream *outStream = &std::cout);
    ~LogMessage();

    std::ostringstream & operator()();

private:
    std::shared_ptr<std::ostringstream> stream;
    std::ostream *outStream;
    LogLevel level;
};

class NullStream : public std::ostringstream
{
public:
    NullStream()
        : std::ostringstream()
    {}
};

template<typename T>
inline NullStream & operator<<(NullStream &stream, const T &)
{
    return stream;
}


// helper macros

#define TLOG(level) LogMessage(level, __FILE__, __LINE__, __FUNCTION__)()

#define TLOG_IF(level, cond) !(cond) ? (void)0 : TLOG(level)


// various helper functions

template <typename T>
std::ostream & operator<<(std::ostream &stream, const std::vector<T> &vec)
{
    stream << '[';
    const auto end = std::end(vec);
    for (auto it = std::begin(vec); it != end; ++it)
    {
        stream << *it;
        if (it + 1 != end)
            stream << ", ";
    }
    stream << ']';
    return stream;
}