#include <iostream>
#include <project/CurrentRates.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/stat.h>
#include <chrono>
#include <thread>
#include <logger/Log.h>

void process()
{
    syslog(LOG_NOTICE, "writing to syslog");
}
int main() {
    setlogmask(LOG_UPTO(LOG_NOTICE));
    openlog("tested", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
    syslog(LOG_INFO, "starting CurrencyRates");
    pid_t pid = fork();
    if(pid < 0)
    {
        exit(EXIT_FAILURE);
    }
    if(pid > 0)
    {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    pid_t sid = setsid();
    if(sid < 0)
    {
        exit(EXIT_FAILURE);
    }
    if((chdir("/")) < 0)
    {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    std::system("gnome-terminal");
    std::system("ls");
//    while(true)
//    {
//        process();
//        std::this_thread::sleep_for(static_cast<std::chrono::seconds>(10));
//    }

    closelog();

    return 0;
}
