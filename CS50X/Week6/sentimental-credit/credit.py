from cs50 import get_int

# 输入卡号


def main():
    number = get_int("Number: ")
    return number

# 输出结果


def credit(num):
    if not luhn(num):
        print("INVALID")
        return

    length = len(str(num))
    start = int(str(num)[:2])

    if length == 15 and start in [34, 37]:
        print("AMEX")
    elif length == 16 and start in range(51, 56):
        print("MASTERCARD")
    elif length in [13, 16] and start // 10 == 4:
        print("VISA")
    else:
        print("INVALID")
    return

# 卢恩算法


def luhn(num):
    is_second = False
    total = 0

    # 获取卢恩算法所需参数
    while num > 0:
        n = num % 10
        if is_second:
            n *= 2
            is_second = False
        else:
            is_second = True
        total += n - 9 if n > 9 else n
        num //= 10

    # 判断是否符合算法
    return total % 10 == 0


credit(main())
