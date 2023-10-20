def bin2dec(binary_str):
    dec = 0
    for i in range(len(binary_str)):
        dec += int(binary_str[i]) * 2**(len(binary_str) - i - 1)
    return dec


def bin_to_hex(binary_str):
    while len(binary_str) % 4 != 0:
        binary_str = '0' + binary_str

    hex_digits = '0123456789ABCDEF'

    hex_result = ''
    for i in range(0, len(binary_str), 4):
        four_bits = binary_str[i:i+4]
        decimal_value = 0

        for j in range(len(four_bits)):
            if four_bits[j] == '1':
                print(2 ** (len(four_bits) - j - 1))
                decimal_value += int(four_bits[j]) * 2 ** (len(four_bits) - j - 1)

        hex_digit = hex_digits[decimal_value]
        hex_result += hex_digit

    return hex_result


def dec2bin(dec):
    binary_str = ''
    while dec > 0:
        binary_str += str(dec % 2)
        dec //= 2
    return binary_str[::-1]

