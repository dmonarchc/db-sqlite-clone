#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <stdint.h>

#include "cursor.h"
#include "pager.h"
#include "row.h"
#include "table.h"

/*
 *   Node header format
 */
typedef enum { NODE_INTERNAL, NODE_LEAF } NodeType;

/*
 *   Common Node Header Layout
 */
#define NODE_TYPE_SIZE (sizeof(uint8_t))
#define NODE_TYPE_OFFSET (0)
#define IS_ROOT_SIZE (sizeof(uint8_t))
#define IS_ROOT_OFFSET (NODE_TYPE_OFFSET + NODE_TYPE_SIZE)
#define PARENT_POINTER_SIZE (sizeof(uint32_t))
#define PARENT_POINTER_OFFSET (IS_ROOT_OFFSET + IS_ROOT_SIZE)
#define COMMON_NODE_HEADER_SIZE                                                \
  (NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE)

/*
 *   Leaf Node Header Layout
 */
#define LEAF_NODE_NUM_CELLS_SIZE (sizeof(uint32_t))
#define LEAF_NODE_NUM_CELLS_OFFSET (COMMON_NODE_HEADER_SIZE)
#define LEAF_NODE_NEXT_LEAF_SIZE (sizeof(uint32_t))
#define LEAF_NODE_NEXT_LEAF_OFFSET                                             \
  (LEAF_NODE_NUM_CELLS_OFFSET + LEAF_NODE_NUM_CELLS_SIZE)
#define LEAF_NODE_HEADER_SIZE                                                  \
  (COMMON_NODE_HEADER_SIZE + LEAF_NODE_NUM_CELLS_SIZE +                        \
   LEAF_NODE_NEXT_LEAF_SIZE)
/*
 *   Leaf Node Body Layout
 */
#define LEAF_NODE_KEY_SIZE (sizeof(uint32_t))
#define LEAF_NODE_KEY_OFFSET (0)
#define LEAF_NODE_VALUE_SIZE (ROW_SIZE)
#define LEAF_NODE_VALUE_OFFSET (LEAF_NODE_KEY_OFFSET + LEAF_NODE_KEY_SIZE)
#define LEAF_NODE_CELL_SIZE (LEAF_NODE_KEY_SIZE + LEAF_NODE_VALUE_SIZE)
#define LEAF_NODE_SPACE_FOR_CELLS (PAGE_SIZE - LEAF_NODE_HEADER_SIZE)
#define LEAF_NODE_MAX_CELLS (LEAF_NODE_SPACE_FOR_CELLS / LEAF_NODE_CELL_SIZE)

/*
 * Leaf Node Sizes
 */
#define LEAF_NODE_RIGHT_SPLIT_COUNT ((LEAF_NODE_MAX_CELLS + 1) / 2)
#define LEAF_NODE_LEFT_SPLIT_COUNT                                             \
  ((LEAF_NODE_MAX_CELLS + 1) - LEAF_NODE_RIGHT_SPLIT_COUNT)

/*
 * Internal Node Header Layout
 */
#define INTERNAL_NODE_NUM_KEYS_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_NUM_KEYS_OFFSET (COMMON_NODE_HEADER_SIZE)
#define INTERNAL_NODE_RIGHT_CHILD_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_RIGHT_CHILD_OFFSET                                       \
  (INTERNAL_NODE_NUM_KEYS_OFFSET + INTERNAL_NODE_NUM_KEYS_SIZE)
#define INTERNAL_NODE_HEADER_SIZE                                              \
  (COMMON_NODE_HEADER_SIZE + INTERNAL_NODE_NUM_KEYS_SIZE +                     \
   INTERNAL_NODE_RIGHT_CHILD_SIZE)

/*
 * Internal Node Body Layout
 */
#define INTERNAL_NODE_KEY_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_CHILD_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_CELL_SIZE                                                \
  (INTERNAL_NODE_CHILD_SIZE + INTERNAL_NODE_KEY_SIZE)
/* Keep this small for testing */
#define INTERNAL_NODE_MAX_CELLS (3)
/*
 *  Accessing Leaf Node Fields
 */
uint32_t *leaf_node_num_cells(void *node);
void *leaf_node_cell(void *node, uint32_t cell_num);
uint32_t *leaf_node_key(void *node, uint32_t cell_num);
uint32_t *node_parent(void *node);
void *leaf_node_value(void *node, uint32_t cell_num);
void initialize_leaf_node(void *node);
void initialize_internal_node(void *node);
void leaf_node_insert(Cursor *cursor, uint32_t key, Row *value);
NodeType get_node_type(void *node);
void set_node_type(void *node, NodeType type);
void leaf_node_split_and_insert(Cursor *cursor, uint32_t key, Row *value);
void create_new_root(Table *table, uint32_t right_child_page_num);
uint32_t *internal_node_num_keys(void *node);
uint32_t *internal_node_right_child(void *node);
uint32_t *internal_node_cell(void *node, uint32_t cell_num);
uint32_t *internal_node_child(void *node, uint32_t child_num);
uint32_t *internal_node_key(void *node, uint32_t key_num);
uint32_t get_node_max_key(void *node);
bool is_node_root(void *node);
void set_node_root(void *node, bool is_root);
void indent(uint32_t level);
void print_tree(Pager *pager, uint32_t page_num, uint32_t indentation_level);
Cursor *internal_node_find(Table *table, uint32_t page_num, uint32_t key);
uint32_t *leaf_node_next_leaf(void *node);
void update_internal_node_key(void *node, uint32_t old_key, uint32_t new_key);
void internal_node_insert(Table *table, uint32_t parent_page_num,
                          uint32_t child_page_num);
#endif // NODE_H
