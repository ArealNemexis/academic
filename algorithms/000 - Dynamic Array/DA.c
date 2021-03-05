#include <stdio.h>
#include <stdlib.h>
#define INDEX_OUT_OF_RANGE -325

typedef struct Array
{
    long long int size;
    long long int used;
    long long int *array;
} Array;

Array *createArray()
{
    Array *create = (Array *)malloc(sizeof(Array));
    create->size = 10;
    create->used = 0;
    create->array = (long long int *)malloc(sizeof(long long int) * create->size);

    return create;
}

int insert(Array *array, int value)
{
    if (array->size == array->used - 1)
    {
        array->array = realloc(array->array, array->size + 10);
        array->size += 10;
    }
    array->array[array->used] = value;
    array->used++;

    return 0;
}

int get(Array *array, int position)
{
    if (array->used - 1 < position)
    {
        return INDEX_OUT_OF_RANGE;
    }

    return array->array[position];
}

int getSize(Array *array)
{
    return array->size;
}

int getUsed(Array *array)
{
    return array->used;
}

int main(int argc, char const *argv[])
{
    Array *teste = createArray();
    insert(teste, 3);
    printf("Used %d\n",getUsed(teste));
    printf("Size %d\n",getSize(teste));

    insert(teste, 4);
    printf("Used %d\n",getUsed(teste));
    printf("Size %d\n",getSize(teste));

    for (int i = 0; i < 2; i++)
    {
        printf("%d\n", get(teste, i));
    }

    return 0;
}
