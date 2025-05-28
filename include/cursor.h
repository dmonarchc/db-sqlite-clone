#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>
#include "table.h"

typedef struct {
    Table* table;
    uint32_t row_num;
    bool end_of_table;  // Indicates a position one past the last element
} Cursor;

Cursor* table_start(Table* table);
Cursor* table_end(Table* table);

#endif // INPUT_BUFFER_H