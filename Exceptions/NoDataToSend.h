#ifndef NODATA_H
#define NODATA_H

#include <exception>
#include <string>

class NoDataToSend : public std::exception
{
};

#endif // NODATA_H
