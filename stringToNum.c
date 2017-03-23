#define MAX_LAST_NAME_SIZE 14

val_t stringToNum(char *map)
{
    val_t key = 0;
    val_t mul = 0;
    for (int i = 0; i < MAX_LAST_NAME_SIZE - 1; i++) {
        int rem = 0;
        if (map[i] != '\n' && map[i] != '\0') {
            rem = map[i] - 96;
            mul = pow(27, (MAX_LAST_NAME_SIZE - i - 2));
            key += rem * mul;
        } else
            break;
    }

    return key;
}

