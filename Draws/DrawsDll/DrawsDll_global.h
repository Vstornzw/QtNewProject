#ifndef DRAWSDLL_GLOBAL_H
#define DRAWSDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DRAWSDLL_LIBRARY)
#  define DRAWSDLL_EXPORT Q_DECL_EXPORT
#else
#  define DRAWSDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // DRAWSDLL_GLOBAL_H
