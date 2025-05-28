#ifndef TABLE_H
#define TABLE_H

#include <stdint.h>
#include "row.h"
#include "cursor.h"

struct Pager;

#define PAGE_SIZE 4096
#define TABLE_MAX_PAGES 100
#define ROWS_PER_PAGE (PAGE_SIZE / ROW_SIZE)
#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)

// Aquí damos nombre a la struct para que coincida con la declaración adelantada
typedef struct Table {
    uint32_t num_rows;
    struct Pager* pager;
} Table;

void* cursor_value(Cursor* cursor);
Table* db_open(const char* filename);
void free_table(Table* table);

#endif // TABLE_H