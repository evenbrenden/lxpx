
typedef struct packed_value
{
    int byte_0;
    int byte_1;
    int byte_2;
} t_packed_value;

void unpacked_to_packed (t_packed_value *packed, int unpacked);
