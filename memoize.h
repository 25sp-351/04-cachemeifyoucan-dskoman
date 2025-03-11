#ifndef MEMOIZE_H
#define MEMOIZE_H

typedef long long int memoize_value_t;

typedef struct {
  memoize_value_t *data;
  int size;
  int capacity;
  int dbg_flag;
} memoize_cache_t;

memoize_cache_t *memoize_init(int capacity, int dbg_flag);
void memoize_free(memoize_cache_t *cache);

int memoize_check(memoize_cache_t *cache, memoize_value_t data);

int memoize_insert(memoize_cache_t *cache, memoize_value_t data);

int memoize_cache_size(memoize_cache_t *cache);

int memoize_cache_capacity(memoize_cache_t *cache);

int memoize_debug_flag(memoize_cache_t *cache);

void memoize_print_cache(memoize_cache_t *cache);

#endif