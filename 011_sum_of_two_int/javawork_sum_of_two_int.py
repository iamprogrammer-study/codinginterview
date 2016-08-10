def getSum(a,b):
    sum = 0
    mask = 1
    carry = 0
    while a > 0 or b > 0 or carry == 1:
        a1 = a & 1
        b1 = b & 1
        if a1 == 1 and b1 == 1:
            if carry == 1:
                sum |= mask
            carry = 1
        elif a1 ^ b1 == 1:
            if carry == 1:
                carry = 1
            else:
                sum |= mask
        else:
            if carry == 1:
                sum |= mask
                carry = 0
        a = a >> 1
        b = b >> 1
        mask = mask << 1
    return sum

a = 5
b = 12
print getSum(a,b)