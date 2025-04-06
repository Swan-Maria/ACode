#include <cmath> // для sqrt()

class IErrorLog
{
public:
    virtual bool openLog(const char* filename) = 0;
    virtual bool closeLog() = 0;

    virtual bool writeError(const char* errorMessage) = 0;

    virtual ~IErrorLog() {}; // создаем виртуальный деструктор, чтобы вызывался соответствующий деструктор дочернего класса в случае, если удалим указатель на IErrorLog
};

double mySqrt(double value, IErrorLog& log)
{
    if (value < 0.0)
    {
        log.writeError("Tried to take square root of value less than 0");
        return 0.0;
    }
    else
        return sqrt(value);
}