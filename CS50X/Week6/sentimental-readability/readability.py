from cs50 import get_string


def main():
    text = get_string("Text: ")

    letters = 0
    words = 1
    sentences = 0

    for x in text:
        if x.isalpha():
            letters += 1
        elif x == " ":
            words += 1
        elif x in ["?", ".", "!"]:
            sentences += 1

    """
    print(letters)
    print(words)
    print(sentences)
    print(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)
    """

    index = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)
    print_grade(index)


def print_grade(i):
    if i < 1:
        print("Before Grade 1")
    elif i > 15:
        print("Grade 16+")
    else:
        print(f"Grade {i}")


main()
