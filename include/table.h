#ifndef TABLE_H
#define TABLE_H

#include <stdint.h>
#include "row.h"
#include "cursor.h"

struct Pager;

#define PAGE_SIZE 4096
#define TABLE_MAX_PAGES 100

// Aquí damos nombre a la struct para que coincida con la declaración adelantada
typedef struct Table {
    uint32_t root_page_num;
    struct Pager* pager;
} Table;

void* cursor_value(Cursor* cursor);
Table* db_open(const char* filename);

#endif // TABLE_H
