#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>
#include <stdbool.h>

struct Table;
typedef struct Table Table;

typedef struct {
    Table* table;
    uint32_t page_num;
    uint32_t cell_num;
    bool end_of_table;  // Indicates a position one past the last element
} Cursor;

Cursor* table_start(Table* table);
Cursor* table_find(Table* table, uint32_t key);
Cursor* leaf_node_find(Table* table, uint32_t page_num, uint32_t key);
void cursor_advance(Cursor* cursor);

#endif // CURSOR_H
