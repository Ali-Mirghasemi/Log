#include "Log.h"

int main()
{
#if LOG_DYNAMIC_LEVEL
    while (LOG_LEVEL-- > 0) {
        LOG_PRINT("-----------------------------------------------------" LOG_END_LINE);
#endif

    logPrintFmt(ERROR, HEADER, "\e[31m", "This is error log.");
    logPrintFmt(ERROR, HEADER, "\e[31m", "This is error log with params.: %d", 100);
    logPrintFmt(ERROR, HEADER, "\e[31m", "This is error log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(WARN, HEADER, "\e[33m", "This is warning log.");
    logPrintFmt(WARN, HEADER, "\e[33m", "This is warning log with params.: %d", 100);
    logPrintFmt(WARN, HEADER, "\e[33m", "This is warning log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(INFO, HEADER, "\e[34m", "This is info log.");
    logPrintFmt(INFO, HEADER, "\e[34m", "This is info log with params.: %d", 100);
    logPrintFmt(INFO, HEADER, "\e[34m", "This is info log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(DEBUG, HEADER, "\e[35m", "This is debug log.");
    logPrintFmt(DEBUG, HEADER, "\e[35m", "This is debug log with params.: %d", 100);
    logPrintFmt(DEBUG, HEADER, "\e[35m", "This is debug log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(TRACE, HEADER, "\e[36m", "This is trace log.");
    logPrintFmt(TRACE, HEADER, "\e[36m", "This is trace log with params.: %d", 100);
    logPrintFmt(TRACE, HEADER, "\e[36m", "This is trace log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(ERROR, LINE, "\e[31m", "This is error log.");
    logPrintFmt(ERROR, LINE, "\e[31m", "This is error log with params.: %d", 100);
    logPrintFmt(ERROR, LINE, "\e[31m", "This is error log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(WARN, LINE, "\e[33m", "This is warning log.");
    logPrintFmt(WARN, LINE, "\e[33m", "This is warning log with params.: %d", 100);
    logPrintFmt(WARN, LINE, "\e[33m", "This is warning log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(INFO, LINE, "\e[34m", "This is info log.");
    logPrintFmt(INFO, LINE, "\e[34m", "This is info log with params.: %d", 100);
    logPrintFmt(INFO, LINE, "\e[34m", "This is info log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(DEBUG, LINE, "\e[35m", "This is debug log.");
    logPrintFmt(DEBUG, LINE, "\e[35m", "This is debug log with params.: %d", 100);
    logPrintFmt(DEBUG, LINE, "\e[35m", "This is debug log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(TRACE, LINE, "\e[36m", "This is trace log.");
    logPrintFmt(TRACE, LINE, "\e[36m", "This is trace log with params.: %d", 100);
    logPrintFmt(TRACE, LINE, "\e[36m", "This is trace log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(ERROR, CUSTOM, "\e[31m", "This is error log.");
    logPrintFmt(ERROR, CUSTOM, "\e[31m", "This is error log with params.: %d", 100);
    logPrintFmt(ERROR, CUSTOM, "\e[31m", "This is error log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(WARN, CUSTOM, "\e[33m", "This is warning log.");
    logPrintFmt(WARN, CUSTOM, "\e[33m", "This is warning log with params.: %d", 100);
    logPrintFmt(WARN, CUSTOM, "\e[33m", "This is warning log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(INFO, CUSTOM, "\e[34m", "This is info log.");
    logPrintFmt(INFO, CUSTOM, "\e[34m", "This is info log with params.: %d", 100);
    logPrintFmt(INFO, CUSTOM, "\e[34m", "This is info log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(DEBUG, CUSTOM, "\e[35m", "This is debug log.");
    logPrintFmt(DEBUG, CUSTOM, "\e[35m", "This is debug log with params.: %d", 100);
    logPrintFmt(DEBUG, CUSTOM, "\e[35m", "This is debug log with params.: %d, %x", 100, 0xFF);

    logPrintFmt(TRACE, CUSTOM, "\e[36m", "This is trace log.");
    logPrintFmt(TRACE, CUSTOM, "\e[36m", "This is trace log with params.: %d", 100);
    logPrintFmt(TRACE, CUSTOM, "\e[36m", "This is trace log with params.: %d, %x", 100, 0xFF);

    logPrint(ERROR, "This is error log.");
    logPrint(ERROR, "This is error log with params.: %d", 100);
    logPrint(ERROR, "This is error log with params.: %d, %x", 100, 0xFF);

    logPrint(WARN, "This is warning log.");
    logPrint(WARN, "This is warning log with params.: %d", 100);
    logPrint(WARN, "This is warning log with params.: %d, %x", 100, 0xFF);

    logPrint(INFO, "This is info log.");
    logPrint(INFO, "This is info log with params.: %d", 100);
    logPrint(INFO, "This is info log with params.: %d, %x", 100, 0xFF);

    logPrint(DEBUG, "This is debug log.");
    logPrint(DEBUG, "This is debug log with params.: %d", 100);
    logPrint(DEBUG, "This is debug log with params.: %d, %x", 100, 0xFF);

    logPrint(TRACE, "This is trace log.");
    logPrint(TRACE, "This is trace log with params.: %d", 100);
    logPrint(TRACE, "This is trace log with params.: %d, %x", 100, 0xFF);

#if LOG_DYNAMIC_LEVEL
    }
#endif
}
