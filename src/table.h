#ifndef TABLE_H
#define TABLE_H

#include <stdint.h>
#include "row.h"

const uint32_t PAGE_SIZE = 4096;
#define TABLE_MAX_PAGES 100
const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;

// Metodos
void* row_slot(Table* table, uint32_t row_num);
Table* new_table();
void free_table(Table* table);

#endif // TABLE_H