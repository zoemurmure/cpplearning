#ifndef MY_SALES_DATA_H
#define MY_SALES_DATA_H
#include <string>
struct My_sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
