#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
class DbUser;

class Globals
{
public:
    Globals();

    static DbUser *sgCurUser;
};

#endif // GLOBALS_H
