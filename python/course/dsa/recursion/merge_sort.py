"""
Module: to demonstrate merge sorting
"""


def merge(left, right):
    """Merging two lists"""
    li, ri = 0, 0
    merged_lists = []

    # compare smallest to the list.
    while li < len(left) and ri < len(right):
        if left[li] <= right[ri]:
            merged_lists.append(left[li])
            li += 1
        else:
            merged_lists.append(right[ri])
            ri += 1

    # add all remaining
    merged_lists += left[li:]
    merged_lists += right[ri:]

    return merged_lists


def merge_sort(lists):
    """Merge sort function"""
    half = len(lists) // 2

    if len(lists) == 1:
        return lists

    return merge(merge_sort(lists[:half]), merge_sort(lists[half:]))


if __name__ == "__main__":
    output = merge_sort([6, 5, 4, 3, 2, 1])

    print(output)
