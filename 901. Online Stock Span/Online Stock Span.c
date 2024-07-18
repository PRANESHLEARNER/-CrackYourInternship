#include <stdlib.h>

typedef struct {
    int* prices;
    int* spans;
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*) malloc(sizeof(StockSpanner));
    obj->prices = (int*) malloc(10000 * sizeof(int));
    obj->spans = (int*) malloc(10000 * sizeof(int));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while (obj->top >= 0 && obj->prices[obj->top] <= price) {
        span += obj->spans[obj->top];
        obj->top--;
    }
    obj->top++;
    obj->prices[obj->top] = price;
    obj->spans[obj->top] = span;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj->spans);
    free(obj);
}