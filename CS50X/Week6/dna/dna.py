import csv
import sys


def main():

    # TODO: Check for command-line usage
    args = sys.argv
    if len(args) != 3:
        exit(1)

    # TODO: Read database file into a variable
    rows = []
    with open(args[1], 'r') as file:
        reader = csv.DictReader(file)
        fieldnames = reader.fieldnames
        for row in reader:
            rows.append(row)

    field = fieldnames[1:]
    name = fieldnames[0]

    # TODO: Read DNA sequence file into a variable
    with open(args[2], 'r') as file:
        dna = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    ls = []
    for str in field:
        ls.append(longest_match(dna, str))

    """
    调试内容
    print(field)    # 打印序列表头
    print(name)     # 打印名字表头
    print(rows)     # 打印每一行的字典列表
    print(ls)       # 打印最长序列的列表
    """

    # TODO: Check database for matching profiles
    for people in rows:
        for i in range(len(field)):
            if int(people[field[i]]) != ls[i]:
                break
        else:
            print(people[name])
            exit(0)
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
