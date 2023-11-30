#include <stdio.h>

#define BLOCK_SIZE 8192 // 8 KB
#define BLOCK_POINTER_SIZE 4 // 4 bytes
#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (BLOCK_SIZE / BLOCK_POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)
#define TRIPLE_INDIRECT_BLOCKS (DOUBLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)

int main() {
    // Calculate the maximum file size
    long long maxFileSize = 0;
    maxFileSize += DIRECT_BLOCKS; // Direct blocks
    maxFileSize += SINGLE_INDIRECT_BLOCKS; // Single indirect blocks
    maxFileSize += DOUBLE_INDIRECT_BLOCKS; // Double indirect blocks
    maxFileSize += TRIPLE_INDIRECT_BLOCKS; // Triple indirect blocks

    // Calculate the maximum file size in bytes
    long long maxSizeInBytes = maxFileSize * BLOCK_SIZE;

    printf("Maximum File Size: %lld bytes\n", maxSizeInBytes);

    return 0;
}
