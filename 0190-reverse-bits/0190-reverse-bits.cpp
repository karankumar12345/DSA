class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
 uint32_t result = 0; // Initialize result as 0
        for (int i = 0; i < 32; i++) { // Loop 32 times for 32-bit number
            result <<= 1;       // Shift result left by 1 to make space
            result |= (n & 1);  // Take the last bit of n and add it to result
            n >>= 1;            // Shift n right to remove the last bit
        }
        return result;
    }
};