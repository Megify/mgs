int main()
{
    struct DynamicSlice *dynslice;
    dynslice = create_dynamic_lice(sizeof(void *));
    
    int value = 10;
    
    append(dynslice, &value);
    append(dynslice, &value);
    append(dynslice, &value);
    append(dynslice, &value);
    
    for (int i = 0; i < dynslice->size; i++) {
        printf("Pointer: %d\n", get(dynslice, i));
        printf("%d\n", *(int *)get(dynslice, i));
        value++;
    }

    return 0;
}