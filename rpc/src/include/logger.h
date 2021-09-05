#pragma once

class Logger {
public:
    enum Level {
        INFO,
        ERROR,
    };
    void setLevel(Level level);
    
private:
    Logger();
    Logger(Logger&& ) = delete;
    Logger(const Logger&) = delete;
    int level_;
};
