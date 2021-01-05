#pragma once


#ifdef DEBUG
#define DEBUG_PRINT printf
#else
#define DEBUG_PRINT(fmt, ...) do {} while (0) // while loop
#endif
